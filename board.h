#ifndef BOARD_H
#define BOARD_H
#include "matrix.h"

enum class MineLevel
{
    Small,
    Medium,
    Large,
};

class Board
{
//    friend class DoubleClickSolver;
    friend int main();
    friend class PosInfo;
    friend class BoardGen;
    friend class BoardSpanner;
public:
    Board();
    void reset(MineLevel l);
    void reset(int row, int col, int n);
    bool isInBoard(Pos p) const { return real_matrix.isInMatrix(p); }
    bool isDone() const;
    const Matrix& getViewMatrix() const { return user_matrix; }
    const Matrix& getRealMatrix() const { return real_matrix; }
public:
    //user interface, return false, game over
    void flagPos(Pos p);
    void unflagPos(Pos p);
    bool clickPos(Pos p);
    bool doubleClick(Pos p, bool *isCleardPos);
public:
    // some get interface
    int MineNum() const { return mine_num; }
    int FlaggedNum() const { return flagged_num; }
    int RowSize() const { return real_matrix.row_size(); }
    int ColSize() const { return real_matrix.col_size(); }
public:
    Status getPos_u(Pos p) const { return user_matrix.get(p); }
    bool setPos_u(Pos p, Status s);
private:
    Status getPos_r(Pos p) const { return real_matrix.get(p); }
    void setPos_r(Pos p, Status s);
private:
    void checkBound(Pos p) const;
private:
    Matrix real_matrix;
    Matrix user_matrix;
    int mine_num;
    int flagged_num;
};




#endif // BOARD_H
