#ifndef BOARD_H
#define BOARD_H
#include "posmatrix.h"
#include "assert.h"

class Board
{
    friend class BoardGen;
    friend class BoardSpanner;
    friend class BoardPrinter;
public:
    Board();
    void reset(int row, int col, int n);
public:
    //user interface, return false, game over
    bool flagPos(const Pos& p, PosStatus status);
    bool clickPos(const Pos& p, PosStatus* s = nullptr);
    bool doubleCheck(const Pos& p);
public:
    // some get interface
    int MineNum() const { return mine_num; }
    int RowSize() const { return real_matrix.row_size(); }
    int ColSize() const { return real_matrix.col_size(); }
public:
    PosStatus getPos_u(const Pos& p) const;
    bool setPos_u(const Pos& p, PosStatus s);
private:
    PosStatus getPos_r(const Pos& p) const;
    void setPos_r(const Pos& p, PosStatus s);

private:
    void checkBound(const Pos& p) const;
    bool isInBoard(const Pos& p) const;
private:
    PosMatrix real_matrix;
    PosMatrix user_matrix;
    int mine_num;
};




#endif // BOARD_H
