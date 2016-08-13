#include "matrix.h"
#include <cassert>

MatrixInfo Matrix::toPosSetMap() const
{
    MatrixInfo ret;
    for (MatrixCIter it=begin(), last=end();it!=last; ++it)
    {
        ret[*it].insert(it.toPos());
    }
    return ret;
}

MatrixIter Matrix::begin()
{
    return MatrixIter(this, 0);
}

MatrixIter Matrix::end()
{
    return MatrixIter(this, row_size()*col_size());
}

MatrixCIter Matrix::begin() const
{
    return MatrixCIter(this, 0);
}

MatrixCIter Matrix::end() const
{
    return MatrixCIter(this, row_size()*col_size());
}

void Matrix::resize(int row, int col, Status s)
{
    row_len = row;
    col_len = col;
    matrix.clear();
    matrix.resize(row, vector<Status>(col, s));
}

Status Matrix::get(Pos p) const
{
    checkBound(p);
    return matrix[p.row][p.col];
}

void Matrix::set(Pos p, Status s)
{
    checkBound(p);
    matrix[p.row][p.col] = s;
}

bool Matrix::isInMatrix(Pos p) const
{
    return 0<=p.row && p.row<row_size() && 0<=p.col && p.col<col_size();
}

void Matrix::checkBound(Pos p) const
{
    assert(isInMatrix(p));
}

bool Matrix::equal(const Matrix &m1, const Matrix &m2)
{
    assert(m1.row_size()==m2.row_size() && m1.col_size()==m2.col_size());

    for (MatrixCIter iter=m1.begin(), end=m1.end(); iter!=end; ++iter)
    {
        if (*iter != m2.get(iter.toPos()))
            return false;
    }
    return true;
}


