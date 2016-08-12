#include "statusmatrix.h"
#include <cassert>

MatrixIter StatusMatrix::begin()
{
    return MatrixIter(this, 0);
}

MatrixIter StatusMatrix::end()
{
    return MatrixIter(this, row_size()*col_size());
}

MatrixCIter StatusMatrix::begin() const
{
    return MatrixCIter(this, 0);
}

MatrixCIter StatusMatrix::end() const
{
    return MatrixCIter(this, row_size()*col_size());
}

void StatusMatrix::resize(int row, int col, PosStatus s)
{
    row_len = row;
    col_len = col;
    matrix.clear();
    matrix.resize(row, vector<PosStatus>(col, s));
}

PosStatus StatusMatrix::operator()(Pos p) const
{
    checkBound(p);
    return matrix[p.row][p.col];
}

PosStatus &StatusMatrix::operator()(Pos p)
{
    checkBound(p);
    return matrix[p.row][p.col];
}

bool StatusMatrix::isInMatrix(Pos p) const
{
    return 0<=p.row && p.row<row_size() && 0<=p.col && p.col<col_size();
}

void StatusMatrix::checkBound(Pos p) const
{
    assert(isInMatrix(p));
}

bool StatusMatrix::equal(const StatusMatrix &m1, const StatusMatrix &m2)
{
    assert(m1.row_size()==m2.row_size() && m1.col_size()==m2.col_size());
    for (auto iter=m1.begin(); iter!=m1.end(); ++iter)
    {
        if (*iter != m2(iter.toPos()))
            return false;
    }
    return true;
}


