#ifndef BOARDSPANNER_H
#define BOARDSPANNER_H
#include "board.h"

class BoardSpanner
{
public:
    static void span(Board& b, Pos p);
private:
    static void open(Board& b, Pos p);
};

#endif // BOARDSPANNER_H
