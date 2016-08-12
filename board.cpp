#include "board.h"
#include "boardgen.h"
#include "boardspanner.h"
#include "posinfo.h"
#include <iostream>
using std::cout;
using std::endl;

Board::Board()
{
    reset(20, 70, 50);
}

void Board::reset(int row, int col, int n)
{
    mine_num = n;
    flagged_num = 0;
    real_matrix.resize(row, col, PosStatus::Blank);
    BoardGen::Gen(*this);
    user_matrix.resize(row, col, PosStatus::UnKnown);
}

void Board::flagPos(Pos p)
{
    if (getPos_u(p)==PosStatus::UnKnown)
    {
        setPos_u(p, PosStatus::Flaged);
        ++flagged_num;
    }
}

void Board::unflagPos(Pos p)
{
    if (getPos_u(p) == PosStatus::Flaged)
    {
        setPos_u(p, PosStatus::UnKnown);
        --flagged_num;
    }
}

bool Board::clickPos(Pos p, PosStatus *s)
{
    checkBound(p);

    //如果已经是已知类型，直接返回
    PosStatus us = getPos_u(p);
    if (us!=PosStatus::UnKnown)
        return true;

    PosStatus tmp = getPos_r(p);
    if (s) *s = tmp;

    switch(tmp)
    {
    case PosStatus::Mine:
        user_matrix = real_matrix;
        return false;
        break;
    case PosStatus::Number1:
    case PosStatus::Number2:
    case PosStatus::Number3:
    case PosStatus::Number4:
    case PosStatus::Number5:
    case PosStatus::Number6:
    case PosStatus::Number7:
    case PosStatus::Number8:
        setPos_u(p, tmp);
        break;
    case PosStatus::Blank:
        BoardSpanner::span(*this, p);
        break;
    default:
        assert(false);
    }
    return true;
}

bool Board::doubleClick(Pos p)
{
    PosStatus s = getPos_u(p);
    switch(s)
    {
    case PosStatus::Blank:
    case PosStatus::UnKnown:
    case PosStatus::Flaged:
    case PosStatus::Mine:
        return true;
        break;
    case PosStatus::Number1:
    case PosStatus::Number2:
    case PosStatus::Number3:
    case PosStatus::Number4:
    case PosStatus::Number5:
    case PosStatus::Number6:
    case PosStatus::Number7:
    case PosStatus::Number8:
    {
        PosInfo info(p, *this);
        cout << info.mine_num << ":"<<info.flagged_num<<":"<<info.unknow_num<<endl;
        if (info.mine_num == info.flagged_num)
        {
            //如果标记完毕还有 unknow num 那么就有可能引爆
            //mine num == flagged num
            return info.openBlank();
        }
        else if (info.mine_num == info.flagged_num + info.unknow_num)
        {
            //mine num > flagged num
            info.flagAll();
            return true;
        }
        else
        {
            //标记多了
            //mine num < flagged num
            return true;
        }
    }
        break;
    }
    assert(false);
    return false;
}

void Board::setPos_r(Pos p, PosStatus s)
{
    checkBound(p);
    real_matrix(p) = s;
}

bool Board::setPos_u(Pos p, PosStatus s)
{
    checkBound(p);
    PosStatus tmp = getPos_u(p);
    if (tmp == PosStatus::UnKnown || tmp == PosStatus::Flaged)
    {
        user_matrix(p) = s;
        return true;
    }
    else
    { return false; }
}

void Board::checkBound(Pos p) const
{
    assert(real_matrix.isInMatrix(p));
}

bool Board::isDone() const
{
    int unOpenedNum = 0;
    for (auto it=user_matrix.begin(); it!=user_matrix.end(); ++it)
    {
        auto s = *it;
        if (s==PosStatus::Flaged || s==PosStatus::UnKnown)
            ++unOpenedNum;
    }
    return unOpenedNum == mine_num;
}
