#ifndef POSINFO_H
#define POSINFO_H
#include "statusmatrix.h"
#include "board.h"

class PosInfo
{
public:
    PosInfo(Pos p, Board& m);
    bool isClear() const { return mine_num == blank_num + flagged_num; }
    bool isFlaggedAll() const { return mine_num == flagged_num; }
    bool openBlank() const;
public:
    Board &board;
    Pos pos;
    int mine_num;
    int blank_num;
    int flagged_num;
private:
    void getNum(Pos p);
    bool clickPos(Pos p) const;
};

#endif // POSINFO_H
