#include "posinfo.h"

PosInfo::PosInfo(Pos p, Board& m)
    :board(m)
    ,pos(p)
    ,mine_num(0)
    ,unknow_num(0)
    ,flagged_num(0)
{
    mine_num = int(board.getPos_u(p)) - '0';
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

void PosInfo::flagAll() const
{
    assert( mine_num == unknow_num+flagged_num);

    //如果还有没有标记的，那就把剩下的标记
    flagPos(Pos(pos.row-1, pos.col-1));
    flagPos(Pos(pos.row-1, pos.col));
    flagPos(Pos(pos.row-1, pos.col+1));
    flagPos(Pos(pos.row, pos.col-1));
    flagPos(Pos(pos.row, pos.col+1));
    flagPos(Pos(pos.row+1, pos.col-1));
    flagPos(Pos(pos.row+1, pos.col));
    flagPos(Pos(pos.row+1, pos.col+1));
}

bool PosInfo::openBlank() const
{
    assert(mine_num == flagged_num);

    return
       clickPos(Pos(pos.row-1, pos.col-1))
    && clickPos(Pos(pos.row-1, pos.col))
    && clickPos(Pos(pos.row-1, pos.col+1))
    && clickPos(Pos(pos.row, pos.col-1))
    && clickPos(Pos(pos.row, pos.col+1))
    && clickPos(Pos(pos.row+1, pos.col-1))
    && clickPos(Pos(pos.row+1, pos.col))
    && clickPos(Pos(pos.row+1, pos.col+1));
}

void PosInfo::getNum(Pos p)
{
    if (board.isInBoard(p))
    {
        if (board.getPos_u(p)==PosStatus::UnKnown)
            ++unknow_num;
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

void PosInfo::flagPos(Pos p) const
{
    if (board.isInBoard(p) && board.getPos_u(p) == PosStatus::UnKnown)
        board.flagPos(p);
}
