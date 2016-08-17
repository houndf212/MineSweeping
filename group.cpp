#include "group.h"

std::ostream &operator<<(std::ostream &os, const Group &g)
{
    os<<"all: "<<g.all_unknow.size()<<": "<<g.all_unknow<<std::endl;
    os<<"in : "<<g.innter_border.size()<<": "<<g.innter_border<<std::endl;
    os<<"out: "<<g.outer_border.size()<<": "<<g.outer_border<<std::endl;
}
