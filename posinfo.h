#ifndef POSINFO_H
#define POSINFO_H

#include "board.h"

class PosInfo
{
public:
    PosInfo() {}
    PosInfo(Pos p, const Matrix& m);

    // the below func will change the board!
    void flagAll( Board* board) const;
    bool openBlank( Board* board) const;
public:
    Pos pos;
    int mine_num;
    int unknow_num;
    PosSet unknow_set;
    int flagged_num;
    PosSet flagged_set;
private:
    void getNum(Pos p, const Matrix& m);
    bool clickPos(Pos p, Board* board) const;
    void flagPos(Pos p, Board* board) const;
};

#endif // POSINFO_H
