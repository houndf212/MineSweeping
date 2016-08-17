#include "posinfo.h"
#include <iostream>

PosInfo::PosInfo(Pos p, const Matrix &m)
    :
    pos(p)
    ,mine_num(0)
    ,unknow_num(0)
    ,flagged_num(0)
{
//    std::cout<< p<<":"<<char(m.get(p));
    mine_num = int(m.get(p)) - '0';
    assert(1<=mine_num && mine_num<=8);

    getNum(Pos(p.row-1, p.col-1), m);
    getNum(Pos(p.row-1, p.col), m);
    getNum(Pos(p.row-1, p.col+1), m);
    getNum(Pos(p.row, p.col-1), m);
    getNum(Pos(p.row, p.col+1), m);
    getNum(Pos(p.row+1, p.col-1), m);
    getNum(Pos(p.row+1, p.col), m);
    getNum(Pos(p.row+1, p.col+1), m);

}

void PosInfo::flagAll(Board* board) const
{
    assert( mine_num == unknow_num+flagged_num);

    //如果还有没有标记的，那就把剩下的标记
    flagPos(Pos(pos.row-1, pos.col-1), board);
    flagPos(Pos(pos.row-1, pos.col), board);
    flagPos(Pos(pos.row-1, pos.col+1), board);
    flagPos(Pos(pos.row, pos.col-1), board);
    flagPos(Pos(pos.row, pos.col+1), board);
    flagPos(Pos(pos.row+1, pos.col-1), board);
    flagPos(Pos(pos.row+1, pos.col), board);
    flagPos(Pos(pos.row+1, pos.col+1), board);
}

bool PosInfo::openBlank(Board *board) const
{
    assert(mine_num == flagged_num);

    return
       clickPos(Pos(pos.row-1, pos.col-1), board)
    && clickPos(Pos(pos.row-1, pos.col), board)
    && clickPos(Pos(pos.row-1, pos.col+1), board)
    && clickPos(Pos(pos.row, pos.col-1), board)
    && clickPos(Pos(pos.row, pos.col+1), board)
    && clickPos(Pos(pos.row+1, pos.col-1), board)
    && clickPos(Pos(pos.row+1, pos.col), board)
    && clickPos(Pos(pos.row+1, pos.col+1), board);
}

void PosInfo::getNum(Pos p, const Matrix &m)
{
    if (m.isInMatrix(p))
    {
        if (m.get(p)==Status::UnKnown)
        {
            ++unknow_num;
            unknow_set.insert(p);
        }
        else if (m.get(p)==Status::Flagged)
        {
            ++flagged_num;
            flagged_set.insert(p);
        }
    }
}

bool PosInfo::clickPos(Pos p, Board* board) const
{
    if (board->isInBoard(p) && board->getPos_u(p) == Status::UnKnown)
        return board->clickPos(p);
    else
        return true;
}

void PosInfo::flagPos(Pos p, Board *board) const
{
    if (board->isInBoard(p) && board->getPos_u(p) == Status::UnKnown)
        board->flagPos(p);
}
