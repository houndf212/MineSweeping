#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <algorithm>

#include "board.h"
#include "humanplayer.h"
#include "matrixfinder.h"
#include "boardprinter.h"

using namespace std;

void testRandomShuffle(int n, int t)
{
    vector<int> vec(n, 0);
    for (size_t i=0; i<vec.size(); ++i)
    {
        vec[i]=i;
    }

    vector<int> count(n, 0);
    int k = 0;
    while(k++<t)
    {
        vector<int> v = vec;
        random_shuffle(v.begin(), v.end());
        for (size_t i=0; i<v.size(); ++i)
        {
            if (v[i] == int(i))
                ++count[i];
        }
    }
    for (size_t i=0; i<count.size(); ++i)
    {
        cout<< "0: "<< count[i] << "/"<<t<<","<<"\t"<<double(count[i])/t*100<<endl;
    }

}
int main()
{
    std::srand(time(0));
    Board b;
    b.reset(MineLevel::Small);
//    while(true)
//    {
//        system("clear");
//        b.reset(10, 50, 20);
//        BoardPrinter::print_r(b);
//        Pos p(0, 0);
//        bool blank = MatrixFinder::findBlankArea(b.real_matrix, &p);
//        if (blank)
//            cout << p <<endl;

//        string c;
//        cin>>c;
//    }

    HumanPlayer::play(b);

//    system("pause");
    return 0;
}

