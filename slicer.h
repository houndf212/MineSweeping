#ifndef SLICER_H
#define SLICER_H
#include "matrix.h"
#include "group.h"

class Slicer
{
public:
    explicit Slicer(const Matrix& m);
    std::vector<Group> groups;
private:
    void findGroup(Group* ps , const Matrix& m, Pos p);
    void getBorder(Group* ps , const Matrix& m, Pos p);
    static void checkInnerBorder(PosSet *ps, const Matrix& m, Pos cp);
private:
    Matrix slice_matrix;
};

#endif // SLICER_H
