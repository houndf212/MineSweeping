#include "humanplayer.h"
#include <iostream>
using namespace std;

#include "slicer.h"

bool HumanPlayer::play(Board &b)
{
    bool a = true;
    while (a)
    {
        cout<<b.getRealMatrix();
        cout<<b.getViewMatrix();
        cout<<"left mine: "<<b.MineNum() - b.FlaggedNum()<<endl;
        MatrixInfo mmap = b.getViewMatrix().toPosSetMap();
        for (MatrixInfo::value_type& p : mmap)
        {
            cout<<char(p.first)<<":"<<p.second.size()<<endl;
        }
        Slicer sl(b.getViewMatrix());
        for (const auto& t : sl.group)
        {
            cout<<"##"<<endl;
            cout<<std::get<0>(t).size()<<endl;
            cout<<std::get<1>(t).size()<<endl;
            cout<<std::get<2>(t).size()<<endl;
        }

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
        {
            bool bt=false;
            a = b.doubleClick(p, &bt);
        }
            break;
        }
    }


    if (a)
    {
        cout<< "you have done!!"<<endl;
        return true;
    }
    else
    {
        cout << "you click mine!"<<endl;
        return false;
    }
}
