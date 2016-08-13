#include "boardprinter.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;

void BoardPrinter::print_u(const Board &b)
{
    print(b.user_matrix);
    cout<<"left mine: "<<b.MineNum() - b.FlaggedNum()<<endl;
    MatrixInfo mmap = b.user_matrix.toPosSetMap();
    typedef MatrixInfo::const_iterator Iter;
    for (Iter iter=mmap.cbegin(), end=mmap.cend(); iter!=end; ++iter)
    {
        std::cout<<char(iter->first)<<":"<<iter->second.size()<<std::endl;
    }
}

void BoardPrinter::print(const Matrix &m)
{
    cout<<"   ";
    for (int col=0; col<m.col_size(); ++col)
    {
        cout<<std::setw(2)<<col;
    }
    cout<<endl;
    for (int col=0; col<m.col_size()+2; ++col)
    {
        cout<<std::setw(2)<<"--";
    }
    cout<<endl;
    for (int row=0; row<m.row_size(); ++row)
    {
        cout<<std::setw(2)<<row;
        cout<<'|';
        for (int col=0; col<m.col_size(); ++col)
        {
            std::cout<<std::setw(2)<<char(m.get(Pos(row, col)));
        }
        std::cout<<std::endl;
    }
    for (int col=0; col<m.col_size()+2; ++col)
    {
        cout<<std::setw(2)<<"--";
    }
    cout<<endl;
}
