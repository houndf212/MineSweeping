#ifndef SLICER_H
#define SLICER_H
#include "matrix.h"

class Group
{
public:
    PosSet all_unknow;
    PosSet innter_border;
    PosSet outer_border;
};

class Slicer
{
public:
    explicit Slicer(const Matrix& m);
    std::vector<Group> groups;
private:
    void findGroup(Group* ps , const Matrix& m, Pos p);
    void checkPos(Group* ps , const Matrix& m, Pos p);
private:
    Matrix slice_matrix;
};

#endif // SLICER_H
