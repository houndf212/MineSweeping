#ifndef GROUP_H
#define GROUP_H
#include "pos.h"

class Group
{
public:
    PosSet all_unknow;
    PosSet innter_border;
    std::set<Pos> outer_border;
};

#endif // GROUP_H
