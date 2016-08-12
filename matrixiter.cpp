#include "matrixiter.h"
#include "statusmatrix.h"

MatrixIter::MatrixIter(StatusMatrix *m, int i)
    :matrix(m)
    ,index(i)
{

}

MatrixIter &MatrixIter::operator++()
{
    ++index;
    return *this;
}

PosStatus &MatrixIter::operator*()
{
    return matrix->operator ()(toPos());
}

Pos MatrixIter::toPos() const
{
    return Pos(index/matrix->col_size(), index%matrix->col_size());
}

MatrixCIter::MatrixCIter(const StatusMatrix *m, int i)
    :matrix(m)
    ,index(i)
{

}

MatrixCIter &MatrixCIter::operator++()
{
    ++index;
    return *this;
}

const PosStatus &MatrixCIter::operator*()
{
    return matrix->operator ()(toPos());
}

Pos MatrixCIter::toPos() const
{
    return Pos(index/matrix->col_size(), index%matrix->col_size());
}
