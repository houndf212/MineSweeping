#ifndef DOUBLECLICKSOLVER_H
#define DOUBLECLICKSOLVER_H
#include "board.h"

class DoubleClickSolver
{
public:
    explicit DoubleClickSolver(Board& b);
    bool solve();
private:
    void doubleClickAll();
    void doubleClickNum(Status s);

private:
    Board& board;
    MatrixInfo matinfo;
    PosSet clearSet;
private:
    static int rand(int n);
};

#endif // DOUBLECLICKSOLVER_H
