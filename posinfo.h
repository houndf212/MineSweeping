#ifndef POSINFO_H
#define POSINFO_H

#include "board.h"

class PosInfo
{
public:
    PosInfo(Pos p, Board& m);

    // the below func will change the board!
    void flagAll() const;
    bool openBlank() const;
public:
    Board &board;
    const Pos pos;
    int mine_num;
    int unknow_num;
    PosSet unknow_set;
    int flagged_num;
    PosSet flagged_set;
private:
    void getNum(Pos p);
    bool clickPos(Pos p) const;
    void flagPos(Pos p) const;
};

#endif // POSINFO_H
