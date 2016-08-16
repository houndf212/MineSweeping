#ifndef POS_H
#define POS_H
#include <iostream>
#include <set>
#include <vector>
#include <list>

class Pos
{
public:
    int row;
    int col;
    Pos(int r, int c);
    static bool less(const Pos& p1, const Pos& p2);
    static bool equal(const Pos& p1, const Pos& p2);
};

std::ostream& operator<<(std::ostream& os, const Pos& p);
std::istream& operator>>(std::istream& is, Pos& p);

// the old one
class Pos_Less
{
public:
    bool operator()(const Pos& p1, const Pos& p2) const
    {
        return Pos::less(p1, p2);
    }
};
//typedef std::set<Pos, Pos_Less> PosSet;

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


typedef std::set<Pos> PosSet;


#endif // POS_H
