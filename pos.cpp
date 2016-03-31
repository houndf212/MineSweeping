#include "pos.h"

Pos::Pos(int r, int c)
    : row(r), col(c)
{
}

std::ostream &operator<<(std::ostream &os, const Pos &p)
{
    return os <<'('<<p.row<<','<<p.col<<')';
}

std::istream &operator>>(std::istream &is, Pos &p)
{
    return is >> p.row >> p.col;
}
