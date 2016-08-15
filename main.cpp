#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <algorithm>

#include "board.h"
#include "humanplayer.h"
#include "matrixfinder.h"
#include "boardprinter.h"
#include "doubleclicksolver.h"

using namespace std;

void testDoubleSolve(int n)
{
    int sum=0;
    int k=0;
    while (k++<n)
    {
        Board b;
        b.reset(MineLevel::Small);
        DoubleClickSolver s(b);
        if (s.solve())
            ++sum;
    }
    cout<< "solved: "<< sum<<",  "<<double(sum)/n<<endl;
}
int main()
{
    std::srand(time(0));
//    Board b;
//    b.reset(MineLevel::Small);

//    HumanPlayer::play(b);
    testDoubleSolve(10000);

//    system("pause");
    return 0;
}
