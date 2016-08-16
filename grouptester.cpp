#include "grouptester.h"
#include "posinfo.h"

GroupTester::GroupTester(Board &b, const Group &g)
    :board(b)
    ,view(b.getViewMatrix())
    ,group(g)
{
    assert(group.all_unknow.size()>0);
    assert(group.innter_border.size()>0);
    assert(group.outer_border.size()>=3);
}

bool GroupTester::testCanTest() const
{
    // 如果out border 全是mine 暂时不能解
    if (isOutBorderAllMine())
        return false;

    // 如果找不到有两个块下面只有一颗雷的情况，暂时没法解
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

PosSet GroupTester::findOneInTwo() const
{
    PosSet ret;
    for (const Pos& p : group.outer_border)
    {
        if (view.get(p)!=Status::Flagged)
        {
            PosInfo info(p, board);
            //边界点周围的位置点不可能是1，不然这个1 就是mine
            assert(info.unknow_set.size()<=1);
            if (info.unknow_set.size()==2)
            {
                add(&ret, p);
                return ret;
            }
        }
    }
    return ret;
}
