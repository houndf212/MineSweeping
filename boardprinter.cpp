#include "boardprinter.h"
#include <iostream>
using std::cout;
using std::endl;

void BoardPrinter::print_u(const Board &b)
{
    cout<<"left mine: "<<b.MineNum() - b.FlaggedNum()<<endl;
    print(b.user_matrix);
}

void BoardPrinter::print(const StatusMatrix &m)
{
    cout<<"  ";
    for (int col=0; col<m.col_size(); ++col)
        cout<<col;
    cout<<endl;
    std::cout << "---------------"<<std::endl;
    for (int row=0; row<m.row_size(); ++row)
    {
        cout<<row<<'|';
        for (int col=0; col<m.col_size(); ++col)
        {
            std::cout<<char(m(Pos(row, col)));
        }
        std::cout<<std::endl;
    }
    std::cout << "---------------"<<std::endl;
}
