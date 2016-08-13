#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <map>
#include <assert.h>
#include "status.h"
#include "pos.h"
#include "matrixiter.h"
using std::vector;
using std::map;

typedef map<Status, PosSet> MatrixInfo;

class Matrix
{
    friend class MatrixIter;
    friend class MatrixCIter;
public:
    // where to put this?
    MatrixInfo toPosSetMap() const;
    MatrixIter begin();
    MatrixIter end();

    MatrixCIter begin() const;
    MatrixCIter end() const;

    int row_size() const { return row_len; }
    int col_size() const { return col_len; }
public:
    void resize(int row, int col, Status s);
    bool isInMatrix(Pos p) const;

    Status get(Pos p) const;
    void set(Pos p, Status s);
private:
    void checkBound(Pos p) const;
private:
    vector<vector<Status>> matrix;
    int row_len;
    int col_len;

public:
    static bool equal(const Matrix& m1, const Matrix& m2);
};

#endif // MATRIX_H
