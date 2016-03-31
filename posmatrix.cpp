#include "posmatrix.h"
#include <cassert>

void PosMatrix::resize(int row, int col, PosStatus s)
{
    row_len = row;
    col_len = col;
    matrix.clear();
    matrix.resize(row, vector<PosStatus>(col, s));
}

PosStatus PosMatrix::operator()(const Pos &p) const
{
    checkBound(p);
    return matrix[p.row][p.col];
}

PosStatus &PosMatrix::operator()(const Pos &p)
{
    checkBound(p);
    return matrix[p.row][p.col];
}

bool PosMatrix::isInMatrix(const Pos &p) const
{
    return 0<=p.row && p.row<row_size() && 0<=p.col && p.col<col_size();
}

void PosMatrix::checkBound(const Pos &p) const
{
    assert(isInMatrix(p));
}


