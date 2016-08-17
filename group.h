#ifndef GROUP_H
#define GROUP_H
#include "pos.h"

class Group
{
public:
    PosSet all_unknow;
    PosSet innter_border;
    PosSet outer_border;
};

std::ostream &operator<<(std::ostream& os, const Group& g);


#endif // GROUP_H
