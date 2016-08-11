#include <iostream>
#include "board.h"
#include "boardprinter.h"
using namespace std;

int main()
{
    Board b;
    b.reset(10, 40, 30);
    BoardPrinter::print_r(b);
    BoardPrinter::print_u(b);
    bool a = true;
    do{
        char c;
        while (true)
        {
            cout<<"input method:"<<endl;
            cin>>c;
            if (c=='c' || c=='f' || c=='d' || c=='u')
                break;
            else
                cout<<"input wrong!\n c for click\n f for flag\n d for double click"<<endl;
        }

        Pos p(0,0);
        while (true)
        {
            cout<<"input pos:"<<endl;
            cin>>p;
            if (b.isInBoard(p))
                break;
            else
                cout<<"out of rang, input again!";
        }
        switch(c)
        {
        case 'c':
            a = b.clickPos(p);
            break;
        case 'f':
            b.flagPos(p);
            break;
        case 'u':
            b.unflagPos(p);
            break;
        }

        BoardPrinter::print_r(b);
        BoardPrinter::print_u(b);
    }
    while (a);
    system("pause");
    return 0;
}

