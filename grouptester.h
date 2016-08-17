#ifndef GROUPTESTER_H
#define GROUPTESTER_H
#include "board.h"
#include "group.h"
#include "posinfo.h"

class GroupTester
{
public:
    GroupTester(const Matrix& m, int n, const Group& g);
    bool isGood( Pos *p) const;
private:

    bool testCanTest() const;
    bool isOutBorderAllMine() const;
    bool findOneInTwo(PosInfo *ret) const;
    bool isInInnerBorder(const PosSet& s) const;
    bool test(PosInfo info, Pos *ret) const;
    bool testMineNum() const;

private:
    bool handleClearInfo();
    const int mine_num;
    Matrix view;
    Group group;
    bool isWrong;
};

#endif // GROUPTESTER_H
