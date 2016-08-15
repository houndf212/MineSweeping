#include "doubleclicksolver.h"
#include <stdlib.h>
//#include <iostream>
#include "matrixfinder.h"
//#include "boardprinter.h"

//using namespace std;

DoubleClickSolver::DoubleClickSolver(const Board &b)
    :board(b)
{
    matinfo = b.getViewMatrix().toPosSetMap();
}

bool DoubleClickSolver::solve()
{
    //第一步 作弊，点击空白处
    Pos p(0, 0);
    bool hasBlank = MatrixFinder::findBlankArea(board.getRealMatrix(), &p);
    if (hasBlank)
    {
        bool tb = board.clickPos(p);
        assert(tb);
        matinfo = board.getViewMatrix().toPosSetMap();
    }
    else
    {
//        cout<<"I cannnot solve a game without any blank!"<<endl;
        return false;
    }

    //循环重复双击点击所有数字，直到user matrix 不再变化

    while (!board.isDone())
    {
        doubleClickAll();
        MatrixInfo newinfo = board.getViewMatrix().toPosSetMap();
        if ( MatrixInfo_Equal(newinfo, matinfo))
        {
//            cout<<"double click cannot solve the board!"<<endl;
//            BoardPrinter::print_r(board);
//            BoardPrinter::print_u(board);
            return false;
//            break;
        }
        matinfo = newinfo;
    }

//    BoardPrinter::print_r(board);
//    BoardPrinter::print_u(board);
//    cout<<"I sovle the board!"<<endl;
    return true;
}

void DoubleClickSolver::doubleClickAll()
{
    clearSet.clear();
    //对所有是数字的位置执行双击操作
    doubleClickNum(Status::Number1);
    doubleClickNum(Status::Number2);
    doubleClickNum(Status::Number3);
    doubleClickNum(Status::Number4);
    doubleClickNum(Status::Number5);
    doubleClickNum(Status::Number6);
    doubleClickNum(Status::Number7);
    doubleClickNum(Status::Number8);
}

void DoubleClickSolver::doubleClickNum(Status s)
{
    // the c++ 11 for loop
    for (Pos p : matinfo[s])
    {
        bool b=false;
        board.doubleClick(p, &b);
        if (b)
        {
            add(&clearSet, p);
        }
    }
}

//bool DoubleClickSolver::solve()
//{

//}

int DoubleClickSolver::rand(int n)
{
    int r = std::rand() % n;
    return r;
}
