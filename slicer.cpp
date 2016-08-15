#include "slicer.h"

Slicer::Slicer(const Matrix &m)
{
    //用unkown 表示没检查过 flagged 表示已经检查
    //第一步 所有赋值为 没检查过
    slice_matrix.resize(m.row_size(), m.col_size(), Status::UnKnown);

    for (MatrixIter it=slice_matrix.begin(), end=slice_matrix.end();
         it!=end;
         ++it)
    {
        if (*it!=Status::Flagged && m.get(it.toPos())==Status::UnKnown)
        {
            group.resize(group.size()+1);
            findGroup(&group.back(), m, it.toPos());

        }
    }
}

void Slicer::findGroup(Group *ps, const Matrix &m, Pos p)
{
    if (m.isInMatrix(p) &&
        slice_matrix.get(p)!=Status::Flagged &&
        m.get(p)==Status::UnKnown)
    {
        slice_matrix.set(p, Status::Flagged);
        add(&std::get<0>(*ps), p);
        findGroup(ps, m, Pos(p.row, p.col-1));
        findGroup(ps, m, Pos(p.row, p.col+1));
        findGroup(ps, m, Pos(p.row-1, p.col));
        findGroup(ps, m, Pos(p.row+1, p.col));
    }
}

