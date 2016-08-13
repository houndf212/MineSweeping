#include "matrixfinder.h"

bool MatrixFinder::findBlankArea(const Matrix &m, Pos *p)
{
    for(MatrixCIter iter=m.begin(), end=m.end(); iter!=end; ++iter)
    {
        if (*iter == Status::Blank && checkAroundIsBlank(m, iter.toPos()))
        {
            *p = iter.toPos();
            return true;
        }
    }
    return false;
}

bool MatrixFinder::checkAroundIsBlank(const Matrix &m, Pos p)
{
    assert(m.get(p)==Status::Blank);

    Pos p1(p.row-1, p.col-1);
    Pos p2(p.row-1, p.col);
    Pos p3(p.row-1, p.col+1);

    Pos p4(p.row, p.col-1);
    Pos p5(p.row, p.col+1);

    Pos p6(p.row+1, p.col-1);
    Pos p7(p.row+1, p.col);
    Pos p8(p.row+1, p.col+1);

    return  (m.isInMatrix(p1) && m.get(p1)==Status::Blank) ||
            (m.isInMatrix(p2) && m.get(p2)==Status::Blank) ||
            (m.isInMatrix(p3) && m.get(p3)==Status::Blank) ||
            (m.isInMatrix(p4) && m.get(p4)==Status::Blank) ||
            (m.isInMatrix(p5) && m.get(p5)==Status::Blank) ||
            (m.isInMatrix(p6) && m.get(p6)==Status::Blank) ||
            (m.isInMatrix(p7) && m.get(p7)==Status::Blank) ||
            (m.isInMatrix(p8) && m.get(p8)==Status::Blank);
}
