#ifndef MATRIXITER_H
#define MATRIXITER_H
#include <assert.h>
#include "status.h"
#include "pos.h"

class Matrix;
class MatrixIter
{
    friend bool operator!=(const MatrixIter& it1, const MatrixIter& it2);
    friend class Matrix;
public:
    MatrixIter(Matrix *m, int i);
    MatrixIter& operator++();
    Status& operator*();
    Pos toPos() const;
private:
    Matrix*const matrix;
    int index;
};

inline bool operator!=(const MatrixIter& it1, const MatrixIter& it2)
{
    assert(it1.matrix == it2.matrix);
    return it1.index != it2.index;
}

class MatrixCIter
{
    friend bool operator!=(const MatrixCIter& it1, const MatrixCIter& it2);
    friend class Matrix;
public:
    MatrixCIter(const Matrix *m, int i);
    MatrixCIter& operator++();
    const Status& operator*();
    Pos toPos() const;
private:
    const Matrix*const matrix;
    int index;
};

inline bool operator!=(const MatrixCIter& it1, const MatrixCIter& it2)
{
    assert(it1.matrix == it2.matrix);
    return it1.index != it2.index;
}

#endif // MATRIXITER_H
