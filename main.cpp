#include <iostream>
#include "board.h"
#include "humanplayer.h"
#include <time.h>
using namespace std;

int main()
{
    std::srand(time(0));

    Board b;
    b.reset(8, 10, 30);

    HumanPlayer::play(b);

//    system("pause");
    return 0;
}

