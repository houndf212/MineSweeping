#ifndef SLICER_H
#define SLICER_H
#include "matrix.h"


typedef std::pair<PosSet, PosSet> Group;

class Slicer
{
public:
    explicit Slicer(const Matrix& m);
    //pair first是未确认的块 second 是它的边界（可能包括已经标记的雷）
    std::vector<Group> group;
private:
    void findGroup(Group* ps , const Matrix& m, Pos p);
    void checkPos(Group* ps , const Matrix& m, Pos p);
private:
    Matrix slice_matrix;
};

#endif // SLICER_H
