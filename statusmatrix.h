#ifndef STATUSMATRIX_H
#define STATUSMATRIX_H
#include <vector>
#include <assert.h>
#include "posstatus.h"
#include "pos.h"
#include "matrixiter.h"
using std::vector;

class StatusMatrix
{
public:
    MatrixIter begin();
    MatrixIter end();

    MatrixCIter begin() const;
    MatrixCIter end() const;

    int row_size() const { return row_len; }
    int col_size() const { return col_len; }
public:
    void resize(int row, int col, PosStatus s);
    PosStatus operator()(Pos p) const;
    PosStatus& operator()(Pos p);
    bool isInMatrix(Pos p) const;
private:
    void checkBound(Pos p) const;
private:
    vector<vector<PosStatus>> matrix;
    int row_len;
    int col_len;

public:
    static bool equal(const StatusMatrix& m1, const StatusMatrix& m2);
};

#endif // STATUSMATRIX_H
