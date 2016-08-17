#include "grouptester.h"
#include <iostream>
using namespace std;

GroupTester::GroupTester(const Matrix& m, int n, const Group &g)
    :mine_num(n)
    ,view(m)
    ,group(g)
    ,isWrong(false)
{
    while(handleClearInfo())
        ;
}

bool GroupTester::isGood(Pos *p) const
{
    //如果超过总雷数，错误
    if (!testMineNum())
        return false;

    // 如果未检测过
    if (isWrong)
        return false;

    //如果处理过没有内点
    if (group.innter_border.empty())
        return true;

    // 如果out border 全是mine 暂时不能解
    if (isOutBorderAllMine())
        return false;

    // 如果找不到有两个块下面只有一颗雷的情况，暂时没法解
    PosInfo info;
    if (!findOneInTwo(&info))
        return false;

    return test(info, p);
}

bool GroupTester::isOutBorderAllMine() const
{
    for (const Pos& p : group.outer_border)
    {
        if (view.get(p)!=Status::Flagged)
        {
            return false;
        }
    }
    return true;
}

bool GroupTester::findOneInTwo(PosInfo *ret) const
{
    for (const Pos& p : group.outer_border)
    {
        assert (view.get(p)!=Status::Flagged);

        PosInfo info(p, view);
        //边界点周围的位置点不可能是1，不然这个1 就是mine
        //            assert(info.unknow_set.size()>1);
        if (info.unknow_set.size()<=1)
        {
            cout<<view;
            cout<<info.mine_num<<":"<<info.flagged_num<<":"<<info.unknow_num<<endl;
            cout<<"\nassert: "<<p<<endl;
            assert(false);
        }
        if (info.unknow_set.size()==2 && isInInnerBorder(info.unknow_set))
        {
            *ret = info;
            return true;
        }

    }
    return false;
}

bool GroupTester::isInInnerBorder(const PosSet &s) const
{
    for (const Pos& p : s)
    {
        if (group.innter_border.find(p) == group.innter_border.end())
            return false;
    }
    return true;
}

bool GroupTester::test(PosInfo info, Pos *ret) const
{
    PosSet::const_iterator iter = info.unknow_set.cbegin();
    Pos p1 = *iter;
    ++iter;
    Pos p2 = *iter;

    Group g(group);
    g.outer_border.erase(info.pos);
    g.all_unknow.erase(p1);
    g.all_unknow.erase(p2);
    g.innter_border.erase(p1);
    g.innter_border.erase(p2);

    Matrix m1(view);
    m1.set(p1, Status::Flagged);
    m1.set(p2, Status::Blank);

    Matrix m2(view);
    m2.set(p2, Status::Flagged);
    m2.set(p1, Status::Blank);

    GroupTester t1(m1, mine_num ,g);
    GroupTester t2(m2 ,mine_num ,g);
    Pos tp;
    bool b1 = t1.isGood(&tp);
    if (b1) *ret = p1;
    bool b2 = t2.isGood(&tp);
    if (b2) *ret = p2;

    return b1 ^ b2;
}

bool GroupTester::testMineNum() const
{
    int num=0;
    for (const Status& s : view)
    {
        if (s==Status::Flagged)
            num++;
    }
    return num <= mine_num;
}

bool GroupTester::handleClearInfo()
{
    for (const Pos& p : group.outer_border)
    {
        if (view.get(p) == Status::Flagged)
        {
            group.outer_border.erase(p);
            return true;
        }
        PosInfo info(p, view);

        if (info.mine_num<info.flagged_num)
        {
            isWrong = true;
            return false;
        }
        else if (info.mine_num == info.flagged_num)
        {
            group.outer_border.erase(p);
            for (const Pos& p1 : info.unknow_set)
            {
                view.set(p1, Status::Blank);
                group.innter_border.erase(p1);
                return true;
            }
        }
        else //mine num > flagged
        {
            if (info.mine_num > info.flagged_num + info.unknow_num)
            {
                isWrong = true;
                return false;
            }
            else if (info.mine_num == info.flagged_num+info.unknow_num)
            {
                for (const Pos& p1 : info.unknow_set)
                {
                    view.set(p1, Status::Flagged);
                    group.innter_border.erase(p1);
                    return true;
                }
            }
            // unclear pos
        }
    }
    return false;
}
