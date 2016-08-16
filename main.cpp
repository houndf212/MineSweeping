#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <algorithm>

#include "board.h"
#include "humanplayer.h"
#include "matrixfinder.h"
#include "doubleclicksolver.h"

using namespace std;

void testDoubleSolve(int n)
{
    time_t tm;
    time(&tm);
    cout<<ctime(&tm)<<endl;
    int sum=0;
    int k=0;
    while (k++<n)
    {
        Board b;
        b.reset(MineLevel::Medium);
        DoubleClickSolver s(b);
        if (s.solve())
            ++sum;
    }
    time(&tm);
    cout<<ctime(&tm)<<endl;
    cout<< "solved: "<< sum<<",  "<<double(sum)/n<<endl;
}
int main()
{
    std::srand(time(0));
    Board b;
//    b.reset(20, 20, 200);
    b.reset(MineLevel::Medium);

    HumanPlayer::play(b);
//    testDoubleSolve(10000);

//    system("pause");
    return 0;
}
