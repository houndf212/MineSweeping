#ifndef GROUPTESTER_H
#define GROUPTESTER_H
#include "board.h"
#include "group.h"
#include "posinfo.h"

class GroupTester
{
public:
    GroupTester(Board& b, const Group& g);

private:
    bool testCanTest() const;
    bool isOutBorderAllMine() const;
    bool findOneInTwo(Pos *ret) const;
    bool isInInnerBorder(const PosSet& s) const;
    bool test(PosInfo info) const;
    bool testFlagPos(Pos p, PosSet s, Board b) const;

    Board board;
    const Matrix& view;
    const Group& group;
};

#endif // GROUPTESTER_H
