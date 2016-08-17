#ifndef BOARDGEN_H
#define BOARDGEN_H
#include "board.h"

class BoardGen
{
public:
    static void Gen(Matrix* m, int n);
//private:
    static void cleanRealMatrix(Matrix *m);
    static vector<int> randRang(int s, int n);
    static vector<MatrixIter> randPos(Matrix* m, int n);
    static void calNum(Matrix* m, const vector<MatrixIter> &vec);
    static void addone(Matrix* m, int row, int col);
};

#endif // BOARDGEN_H
