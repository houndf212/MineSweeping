#ifndef BOARDGEN_H
#define BOARDGEN_H
#include "board.h"

class BoardGen
{
public:
    static void Gen(Board& b);
private:
    static void cleanRealMatrix(Board& b);
    static vector<int> randRang(int s, int n);
    static vector<MatrixIter> randPos(Board& b);
    static void calNum(Board& b, const vector<MatrixIter> &vec);
};

#endif // BOARDGEN_H
