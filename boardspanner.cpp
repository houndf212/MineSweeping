#include "boardspanner.h"
#include <iostream>
using namespace std;

void BoardSpanner::span(Board &b, Pos p)
{
    assert(b.getPos_r(p) == Status::Blank);
    open(b, p);
}

void BoardSpanner::open(Board &b, Pos p)
{
    if (!b.isInBoard(p))
        return;

    //跳过用户标记块以及已经打开的块
    if (b.getPos_u(p) != Status::UnKnown)
    {
//        cout<<"checked pos: "<< p <<endl;
        return;
    }

    Status s = b.getPos_r(p);
    assert(s != Status::Flagged);

    switch(s)
    {
    case Status::Number1:
    case Status::Number2:
    case Status::Number3:
    case Status::Number4:
    case Status::Number5:
    case Status::Number6:
    case Status::Number7:
    case Status::Number8:
//        cout<<"find number: "<<p<<", "<<char(s)<<endl;
        b.setPos_u(p, s);
        break;
    case Status::Blank:
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
    case Status::Flagged:
    default:
        assert(false);
    }
}
