#ifndef DOUBLECLICKSOLVER_H
#define DOUBLECLICKSOLVER_H
#include "board.h"

class DoubleClickSolver
{
public:
    explicit DoubleClickSolver(const Board& b);
    bool solve();
private:
    static int rand(int n);
private:
    Board board;
};

#endif // DOUBLECLICKSOLVER_H
