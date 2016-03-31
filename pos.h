#ifndef POS_H
#define POS_H
#include <iostream>

class Pos
{
public:
    int row;
    int col;
    Pos(int r, int c);
};

std::ostream& operator<<(std::ostream& os, const Pos& p);
std::istream& operator>>(std::istream& is, Pos& p);

#endif // POS_H
