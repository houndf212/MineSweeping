#include "humanplayer.h"
#include "boardprinter.h"
#include <iostream>
using namespace std;

bool HumanPlayer::play(Board &b)
{
    BoardPrinter::print_r(b);
    BoardPrinter::print_u(b);
    bool a = true;
    do{
        if (b.isDone())
        {
            break;
        }
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
        case 'd':
            b.doubleClick(p);
            break;
        }

        BoardPrinter::print_r(b);
        BoardPrinter::print_u(b);
    }
    while (a);

    if (a)
    {
        cout<< "you have done!!"<<endl;
        return true;
    }
    else
        return false;
}
