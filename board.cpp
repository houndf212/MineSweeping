﻿#include "board.h"
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

void Board::reset(MineLevel l)
{
    switch (l)
    {
    case MineLevel::Small:
        reset(9, 9, 10);
        break;
    case MineLevel::Medium:
        reset(16, 16, 40);
        break;
    case MineLevel::Large:
        reset(16, 30, 99);
        break;
    }
}

void Board::reset(int row, int col, int n)
{
    mine_num = n;
    flagged_num = 0;
    real_matrix.resize(row, col, Status::Blank);
    BoardGen::Gen(&real_matrix, mine_num);
    user_matrix.resize(row, col, Status::UnKnown);
}

void Board::flagPos(Pos p)
{
    if (getPos_u(p)==Status::UnKnown)
    {
        setPos_u(p, Status::Flagged);
        ++flagged_num;
    }
}

void Board::unflagPos(Pos p)
{
    if (getPos_u(p) == Status::Flagged)
    {
        setPos_u(p, Status::UnKnown);
        --flagged_num;
    }
}

bool Board::clickPos(Pos p)
{
    checkBound(p);

    //如果已经是已知类型，直接返回
    Status us = getPos_u(p);
    if (us!=Status::UnKnown)
        return true;

    Status tmp = getPos_r(p);

    switch(tmp)
    {
    case Status::Flagged:
        user_matrix = real_matrix;
        return false;
        break;
    case Status::Number1:
    case Status::Number2:
    case Status::Number3:
    case Status::Number4:
    case Status::Number5:
    case Status::Number6:
    case Status::Number7:
    case Status::Number8:
        setPos_u(p, tmp);
        break;
    case Status::Blank:
        BoardSpanner::span(*this, p);
        break;
    default:
        assert(false);
    }
    return true;
}

bool Board::doubleClick(Pos p)
{
    Status s = getPos_u(p);
    switch(s)
    {
    case Status::Blank:
    case Status::UnKnown:
    case Status::Flagged:
//    case Status::Mine:
        return true;
        break;
    case Status::Number1:
    case Status::Number2:
    case Status::Number3:
    case Status::Number4:
    case Status::Number5:
    case Status::Number6:
    case Status::Number7:
    case Status::Number8:
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

void Board::setPos_r(Pos p, Status s)
{
    checkBound(p);
    real_matrix.set(p, s);
}

bool Board::setPos_u(Pos p, Status s)
{
    checkBound(p);
    Status tmp = getPos_u(p);
    if (tmp == Status::UnKnown || tmp == Status::Flagged)
    {
        user_matrix.set(p, s);
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
    for (MatrixCIter it=user_matrix.begin(), end=user_matrix.end(); it!=end; ++it)
    {
        Status s = *it;
        if (s==Status::Flagged || s==Status::UnKnown)
            ++unOpenedNum;
    }
    return unOpenedNum <= mine_num+1;
}
