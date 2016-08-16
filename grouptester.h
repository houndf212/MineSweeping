#ifndef GROUPTESTER_H
#define GROUPTESTER_H
#include "board.h"
#include "group.h"

class GroupTester
{
public:
    GroupTester(Board& b, const Group& g);

private:
    bool testCanTest() const;
    bool isOutBorderAllMine() const;
    PosSet findOneInTwo() const;


    Board board;
    const Matrix& view;
    const Group& group;
};

#endif // GROUPTESTER_H
