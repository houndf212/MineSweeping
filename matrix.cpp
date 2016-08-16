#include "matrix.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;

MatrixInfo Matrix::toPosSetMap() const
{
    MatrixInfo ret;

    //先初始化所有为空集合
    ret[Status::Blank];
    ret[Status::Flagged];
    ret[Status::UnKnown];
    ret[Status::Number1];
    ret[Status::Number2];
    ret[Status::Number3];
    ret[Status::Number4];
    ret[Status::Number5];
    ret[Status::Number6];
    ret[Status::Number7];
    ret[Status::Number8];

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

bool MatrixInfo_Equal(const MatrixInfo &matinfo1, const MatrixInfo &matinfo2)
{
    //因为 matrixinfo 都是来自同一个board 所以，只需要比较每个PosSet的大小即可
    for (const MatrixInfo::value_type& p : matinfo1)
    {
        if (p.second.size() != matinfo2.at(p.first).size())
            return false;
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, const Matrix &m)
{
    os<<"   ";
    for (int col=0; col<m.col_size(); ++col)
    {
        os<<std::setw(2)<<col;
    }
    os<<endl;
    for (int col=0; col<m.col_size()+2; ++col)
    {
        os<<std::setw(2)<<"--";
    }
    os<<endl;
    for (int row=0; row<m.row_size(); ++row)
    {
        os<<std::setw(2)<<row;
        os<<'|';
        for (int col=0; col<m.col_size(); ++col)
        {
            os<<std::setw(2)<<char(m.get(Pos(row, col)));
        }
        os<<endl;
    }
    for (int col=0; col<m.col_size()+2; ++col)
    {
        os<<std::setw(2)<<"--";
    }
    os<<endl;
    return os;
}
