#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <algorithm>

#include "board.h"
#include "humanplayer.h"
#include "matrixfinder.h"
#include "doubleclicksolver.h"
#include "boardgen.h"

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

    b.reset(MineLevel::Large);

//    b.reset(4, 4, 3);
//    BoardGen::cleanRealMatrix(&b.real_matrix);
//    std::vector<MatrixIter> vec;
//    vec.push_back(MatrixIter(&b.real_matrix, 1*b.ColSize()+2));
//    vec.push_back(MatrixIter(&b.real_matrix, 2*b.ColSize()+1));
//    vec.push_back(MatrixIter(&b.real_matrix, 2*b.ColSize()+3));

//    for (const MatrixIter& it : vec)
//    {
//        b.real_matrix.set(it.toPos(), Status::Flagged);
//    }

//    BoardGen::calNum(&b.real_matrix, vec);

    HumanPlayer::play(b);
//    testDoubleSolve(10000);

//    system("pause");
    return 0;
}
