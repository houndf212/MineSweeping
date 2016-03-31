#ifndef BOARDGEN_H
#define BOARDGEN_H
#include "board.h"

class BoardGen
{
    friend class Board;
    static void Gen(Board& b);
    static void cleanRealMatrix(Board& b);
    static vector<int> randRang(int s, int n);
    static vector<Pos> transIndex(const vector<int>& vec, int rowlen);
    static vector<Pos> randPos(Board& b);
    static void calNum(Board& b, const vector<Pos>& vec);
};

#endif // BOARDGEN_H
