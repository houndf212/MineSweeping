#include "board.h"
#include "boardgen.h"
#include "boardspanner.h"
#include "posinfo.h"

Board::Board()
{
    reset(20, 70, 50);
}

void Board::reset(int row, int col, int n)
{
    mine_num = n;
    real_matrix.resize(row, col, PosStatus::Blank);
    BoardGen::Gen(*this);
    user_matrix.resize(row, col, PosStatus::UnKnown);
}

void Board::flagPos(const Pos &p)
{
    if (getPos_u(p)==PosStatus::UnKnown)
        setPos_u(p, PosStatus::Flaged);
}

void Board::unflagPos(Pos p)
{
    if (getPos_u(p) == PosStatus::Flaged)
        setPos_u(p, PosStatus::UnKnown);
}

bool Board::clickPos(const Pos &p, PosStatus *s)
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

bool Board::doubleCheck(const Pos &p)
{
    PosStatus s = getPos_u(p);
    switch(s)
    {
    case PosStatus::Blank:
    case PosStatus::UnKnown:
    case PosStatus::Flaged:
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
        //TODO
        break;
    case PosStatus::Mine:
        assert(false);
        break;
    }
    assert(false);
    return false;
}

PosStatus Board::getPos_u(const Pos &p) const
{
    return user_matrix(p);
}

PosStatus Board::getPos_r(const Pos &p) const
{
    return real_matrix(p);
}

void Board::setPos_r(const Pos &p, PosStatus s)
{
    checkBound(p);
    real_matrix(p) = s;
}

bool Board::setPos_u(const Pos &p, PosStatus s)
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

void Board::checkBound(const Pos &p) const
{
    assert(real_matrix.isInMatrix(p));
}

bool Board::isInBoard(const Pos &p) const
{
    return real_matrix.isInMatrix(p);
}
