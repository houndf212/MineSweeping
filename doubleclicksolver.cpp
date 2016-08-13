#include "doubleclicksolver.h"
#include <stdlib.h>

DoubleClickSolver::DoubleClickSolver(const Board &b)
    :board(b)
{

}

//bool DoubleClickSolver::solve()
//{

//}

int DoubleClickSolver::rand(int n)
{
    int r = std::rand() % n;
    return r;
}
