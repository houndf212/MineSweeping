#include "boardspanner.h"
#include <iostream>
using namespace std;

void BoardSpanner::span(Board &b, const Pos &p)
{
    assert(b.getPos_r(p) == PosStatus::Blank);
    open(b, p);
}

void BoardSpanner::open(Board &b, const Pos &p)
{
    if (!b.isInBoard(p))
        return;

    if (b.getPos_u(p) != PosStatus::UnKnown)
    {
//        cout<<"checked pos: "<< p <<endl;
        return;
    }

    PosStatus s = b.getPos_r(p);
    assert(s != PosStatus::Mine);

    switch(s)
    {
    case PosStatus::Number1:
    case PosStatus::Number2:
    case PosStatus::Number3:
    case PosStatus::Number4:
    case PosStatus::Number5:
    case PosStatus::Number6:
    case PosStatus::Number7:
    case PosStatus::Number8:
//        cout<<"find number: "<<p<<", "<<char(s)<<endl;
        b.setPos_u(p, s);
        break;
    case PosStatus::Blank:
//        cout<<"find blank: "<<p<<endl;
        b.setPos_u(p, s);
        open(b, Pos(p.row-1, p.col-1));
        open(b, Pos(p.row-1, p.col));
        open(b, Pos(p.row-1, p.col+1));
        open(b, Pos(p.row, p.col-1));
        open(b, Pos(p.row, p.col+1));
        open(b, Pos(p.row+1, p.col-1));
        open(b, Pos(p.row+1, p.col));
        open(b, Pos(p.row+1, p.col+1));
        break;
    }
}
