#ifndef MATRIXFINDER_H
#define MATRIXFINDER_H
#include "matrix.h"

class MatrixFinder
{
public:
    //找到一块空白的区域
    static bool findBlankArea(const Matrix& m, Pos* p);
    static bool checkAroundIsBlank(const Matrix& m, Pos p);
};

#endif // MATRIXFINDER_H
