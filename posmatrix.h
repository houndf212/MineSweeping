#ifndef POSMATRIX_H
#define POSMATRIX_H
#include <vector>
#include "posstatus.h"
#include "pos.h"
using std::vector;

class PosMatrix
{
public:
    int row_size() const { return row_len; }
    int col_size() const { return col_len; }
public:
    void resize(int row, int col, PosStatus s);
    PosStatus operator()(const Pos& p) const;
    PosStatus& operator()(const Pos& p);
    bool isInMatrix(const Pos& p) const;
private:
    void checkBound(const Pos& p) const;
private:
    vector<vector<PosStatus>> matrix;
    int row_len;
    int col_len;
};

#endif // POSMATRIX_H
