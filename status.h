#ifndef STATUS_H
#define STATUS_H

enum class Status
{
    Blank   = '0',
    Flagged = '#',
    UnKnown = '?',
    Number1 = '1',
    Number2 = '2',
    Number3 = '3',
    Number4 = '4',
    Number5 = '5',
    Number6 = '6',
    Number7 = '7',
    Number8 = '8',
};

enum class MineLevel
{
    Small,
    Medium,
    Large,
};

#endif // STATUS_H

