#include "statusmatrix.h"
#include <cassert>

void StatusMatrix::resize(int row, int col, PosStatus s)
{
    row_len = row;
    col_len = col;
    matrix.clear();
    matrix.resize(row, vector<PosStatus>(col, s));
}

PosStatus StatusMatrix::operator()(const Pos &p) const
{
    checkBound(p);
    return matrix[p.row][p.col];
}

PosStatus &StatusMatrix::operator()(const Pos &p)
{
    checkBound(p);
    return matrix[p.row][p.col];
}

bool StatusMatrix::isInMatrix(const Pos &p) const
{
    return 0<=p.row && p.row<row_size() && 0<=p.col && p.col<col_size();
}

void StatusMatrix::checkBound(const Pos &p) const
{
    assert(isInMatrix(p));
}


