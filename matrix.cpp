#include "matrix.h"
#include <cassert>

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

    int size = ret[Status::Blank].size();

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

//    return
//            matinfo1.at(Status::Blank).size() == matinfo2.at(Status::Blank).size() &&
//            matinfo1.at(Status::UnKnown).size() == matinfo2.at(Status::UnKnown).size() &&
//            matinfo1.at(Status::Flagged).size() == matinfo2.at(Status::Flagged).size() &&
//            matinfo1.at(Status::Number1).size() == matinfo2.at(Status::Number1).size() &&
//            matinfo1.at(Status::Number2).size() == matinfo2.at(Status::Number2).size() &&
//            matinfo1.at(Status::Number3).size() == matinfo2.at(Status::Number3).size() &&
//            matinfo1.at(Status::Number4).size() == matinfo2.at(Status::Number4).size() &&
//            matinfo1.at(Status::Number5).size() == matinfo2.at(Status::Number5).size() &&
//            matinfo1.at(Status::Number6).size() == matinfo2.at(Status::Number6).size() &&
//            matinfo1.at(Status::Number7).size() == matinfo2.at(Status::Number7).size() &&
//            matinfo1.at(Status::Number8).size() == matinfo2.at(Status::Number8).size() ;

    for (MatrixInfo::const_iterator it=matinfo1.cbegin(), last=matinfo1.cend();
         it!=last;
         ++it)
    {
        if (it->second.size()!=matinfo2.at(it->first).size())
            return false;
    }
    return true;
}
