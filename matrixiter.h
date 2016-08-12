#ifndef MATRIXITER_H
#define MATRIXITER_H
#include <assert.h>
#include "posstatus.h"
#include "pos.h"

class StatusMatrix;
class MatrixIter
{
    friend bool operator!=(const MatrixIter& it1, const MatrixIter& it2);
    friend class StatusMatrix;
public:
    MatrixIter(StatusMatrix *m, int i);
    MatrixIter& operator++();
    PosStatus& operator*();
    Pos toPos() const;
private:
    StatusMatrix*const matrix;
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
    friend class StatusMatrix;
public:
    MatrixCIter(const StatusMatrix *m, int i);
    MatrixCIter& operator++();
    const PosStatus& operator*();
    Pos toPos() const;
private:
    const StatusMatrix* matrix;
    int index;
};

inline bool operator!=(const MatrixCIter& it1, const MatrixCIter& it2)
{
    assert(it1.matrix == it2.matrix);
    return it1.index != it2.index;
}

#endif // MATRIXITER_H
