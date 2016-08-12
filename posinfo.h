#ifndef POSINFO_H
#define POSINFO_H
#include "statusmatrix.h"
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
    int flagged_num;
private:
    void getNum(Pos p);
    bool clickPos(Pos p) const;
    void flagPos(Pos p) const;
};

#endif // POSINFO_H
