#include "posinfo.h"

PosInfo::PosInfo(Pos p, Board& m)
    :pos(p)
    ,mine_num(0)
    ,blank_num(0)
    ,flagged_num(0)
{
    mine_num = m.getPos_u(p);
    assert(1<=mine_num && mine_num<=8);

    getNum(Pos(p.row-1, p.col-1));
    getNum(Pos(p.row-1, p.col));
    getNum(Pos(p.row-1, p.col+1));
    getNum(Pos(p.row, p.col-1));
    getNum(Pos(p.row, p.col+1));
    getNum(Pos(p.row+1, p.col-1));
    getNum(Pos(p.row+1, p.col));
    getNum(Pos(p.row+1, p.col+1));

}

bool PosInfo::openBlank() const
{
    assert(isClear());

    return
    clickPos(Pos(p.row-1, p.col-1));
    && clickPos(Pos(p.row-1, p.col));
    && clickPos(Pos(p.row-1, p.col+1));
    && clickPos(Pos(p.row, p.col-1));
    && clickPos(Pos(p.row, p.col+1));
    && clickPos(Pos(p.row+1, p.col-1));
    && clickPos(Pos(p.row+1, p.col));
    && clickPos(Pos(p.row+1, p.col+1));
}

void PosInfo::getNum(Pos p)
{
    if (board.isInBoard(p))
    {
        if (board.getPos_u(p)==PosStatus::Blank)
            ++blank_num;
        else if (board.getPos_u(p)== PosStatus::Flaged)
            ++flagged_num;
    }
}

bool PosInfo::clickPos(Pos p) const
{
    if (board.isInBoard(p) && board.getPos_u(p) == PosStatus::UnKnown)
        return board.clickPos(p);
    else
        return true;
}
