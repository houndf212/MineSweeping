#include "matrixiter.h"
#include "matrix.h"

MatrixIter::MatrixIter(Matrix *m, int i)
    :matrix(m)
    ,index(i)
{

}

MatrixIter &MatrixIter::operator++()
{
    ++index;
    return *this;
}

Status &MatrixIter::operator*()
{
    Pos p = toPos();
    return matrix->matrix[p.row][p.col];
}

Pos MatrixIter::toPos() const
{
    return Pos(index/matrix->col_size(), index%matrix->col_size());
}

MatrixCIter::MatrixCIter(const Matrix *m, int i)
    :matrix(m)
    ,index(i)
{

}

MatrixCIter &MatrixCIter::operator++()
{
    ++index;
    return *this;
}

const Status &MatrixCIter::operator*()
{
    Pos p = toPos();
    return matrix->matrix[p.row][p.col];
}

Pos MatrixCIter::toPos() const
{
    return Pos(index/matrix->col_size(), index%matrix->col_size());
}
