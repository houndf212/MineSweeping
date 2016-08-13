#ifndef POS_H
#define POS_H
#include <iostream>
#include <set>

class Pos
{
public:
    int row;
    int col;
    Pos(int r, int c);
    static bool less(const Pos& p1, const Pos& p2);
    static bool equal(const Pos& p1, const Pos& p2);
};

// the old one
class Pos_Less
{
public:
    bool operator()(const Pos& p1, const Pos& p2) const
    {
        return Pos::less(p1, p2);
    }
};

// c++11 template way!
namespace std{
template <>
struct less<Pos>
{
    bool operator() (const Pos& x, const Pos& y) const
    {
        return Pos::less(x, y);
    }
};
}

//typedef std::set<Pos, Pos_Less> PosSet;
typedef std::set<Pos> PosSet;

std::ostream& operator<<(std::ostream& os, const Pos& p);
std::istream& operator>>(std::istream& is, Pos& p);

#endif // POS_H
