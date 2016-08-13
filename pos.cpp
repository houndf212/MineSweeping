#include "pos.h"

Pos::Pos(int r, int c)
    : row(r), col(c)
{
}

bool Pos::less(const Pos &p1, const Pos &p2)
{
    return p1.row<p2.row || (p1.row==p2.row && p1.col<p2.col);
}

bool Pos::equal(const Pos &p1, const Pos &p2)
{
    return p1.row==p2.row && p1.col==p2.col;
}

std::ostream &operator<<(std::ostream &os, const Pos &p)
{
    return os <<'('<<p.row<<','<<p.col<<')';
}

std::istream &operator>>(std::istream &is, Pos &p)
{
    return is >> p.row >> p.col;
}
