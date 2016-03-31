#include "boardprinter.h"
#include <iostream>

void BoardPrinter::print(const PosMatrix &m)
{
    std::cout << "---------------"<<std::endl;
    for (int row=0; row<m.row_size(); ++row)
    {
        for (int col=0; col<m.col_size(); ++col)
        {
            std::cout<<char(m(Pos(row, col)));
        }
        std::cout<<std::endl;
    }
    std::cout << "---------------"<<std::endl;
}
