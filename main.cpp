#include <iostream>
#include "board.h"
#include "boardprinter.h"
using namespace std;

int main()
{
    Board b;
    b.reset(10, 40, 30);
    BoardPrinter::print_r(b);
    bool a = true;
    do{
        Pos p(0,0);
        cin>>p;
        a = b.clickPos(p);
        BoardPrinter::print_r(b);
        BoardPrinter::print_u(b);
    }
    while (a);
    system("pause");
    return 0;
}

