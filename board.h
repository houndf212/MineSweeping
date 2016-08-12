#ifndef BOARD_H
#define BOARD_H
#include "statusmatrix.h"

class Board
{
    friend class DoubleClickSolver;
    friend class PosInfo;
    friend class BoardGen;
    friend class BoardSpanner;
    friend class BoardPrinter;
public:
    Board();
    void reset(int row, int col, int n);
    bool isInBoard(Pos p) const { return real_matrix.isInMatrix(p); }
    bool isDone() const;
public:
    //user interface, return false, game over
    void flagPos(Pos p);
    void unflagPos(Pos p);
    bool clickPos(Pos p, PosStatus* s = nullptr);
    bool doubleClick(Pos p);
public:
    // some get interface
    int MineNum() const { return mine_num; }
    int FlaggedNum() const { return flagged_num; }
    int RowSize() const { return real_matrix.row_size(); }
    int ColSize() const { return real_matrix.col_size(); }
public:
    PosStatus getPos_u(Pos p) const { return user_matrix(p); }
    bool setPos_u(Pos p, PosStatus s);
private:
    PosStatus getPos_r(Pos p) const { return real_matrix(p); }
    void setPos_r(Pos p, PosStatus s);
private:
    void checkBound(Pos p) const;
private:
    StatusMatrix real_matrix;
    StatusMatrix user_matrix;
    int mine_num;
    int flagged_num;
};




#endif // BOARD_H
