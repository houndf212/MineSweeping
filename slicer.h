#ifndef SLICER_H
#define SLICER_H
#include "matrix.h"

//0 所有为unknow
//1 0集合的 ‘内边界’ 值为unknow
//2 0集合真 ‘外边界’ 值为 数字或者已经标记的雷
typedef std::tuple<PosSet, PosSet, PosSet> Group;

class Slicer
{
public:
    explicit Slicer(const Matrix& m);
    std::vector<Group> group;
private:
    void findGroup(Group* ps , const Matrix& m, Pos p);
    void checkPos(Group* ps , const Matrix& m, Pos p);
private:
    Matrix slice_matrix;
};

#endif // SLICER_H
