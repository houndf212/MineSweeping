﻿#include "slicer.h"

Slicer::Slicer(const Matrix &m)
{
    //用unkown 表示没检查过 flagged 表示已经检查
    //第一步 所有赋值为 没检查过
    slice_matrix.resize(m.row_size(), m.col_size(), Status::UnKnown);

    for (MatrixIter it=slice_matrix.begin(),
         end=slice_matrix.end();
         it!=end;
         ++it)
    {
        if (*it!=Status::Flagged && m.get(it.toPos())==Status::UnKnown)
        {
            groups.push_back(Group());
            findGroup(&groups.back(), m, it.toPos());
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
        ps->all_unknow.insert(p);
        getBorder(ps, m, p);

        findGroup(ps, m, Pos(p.row, p.col-1));
        findGroup(ps, m, Pos(p.row, p.col+1));
        findGroup(ps, m, Pos(p.row-1, p.col));
        findGroup(ps, m, Pos(p.row+1, p.col));
    }
}

void Slicer::getBorder(Group *ps, const Matrix &m, Pos p)
{
    PosSet tempset;

    checkInnerBorder(&tempset, m, Pos(p.row-1, p.col-1));
    checkInnerBorder(&tempset, m, Pos(p.row-1, p.col));
    checkInnerBorder(&tempset, m, Pos(p.row-1, p.col+1));
    checkInnerBorder(&tempset, m, Pos(p.row, p.col-1));
    checkInnerBorder(&tempset, m, Pos(p.row, p.col+1));
    checkInnerBorder(&tempset, m, Pos(p.row+1, p.col-1));
    checkInnerBorder(&tempset, m, Pos(p.row+1, p.col));
    checkInnerBorder(&tempset, m, Pos(p.row+1, p.col+1));

    if (!tempset.empty())
    {
        ps->innter_border.insert(p);
//        ps->outer_border.insert(tempset.cbegin(), tempset.cend());
        for (const Pos& tp : tempset)
        {
            if (m.get(tp)!=Status::Flagged)
                ps->outer_border.insert(tp);
        }
    }


}

void Slicer::checkInnerBorder(PosSet *ps, const Matrix &m, Pos cp)
{
//    if (m.isInMatrix(cp) && m.get(cp)!=Status::UnKnown)
    if (m.isInMatrix(cp) && isNumber(m.get(cp)))
    {
        ps->insert(cp);
    }
}

