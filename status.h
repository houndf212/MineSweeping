#ifndef STATUS_H
#define STATUS_H

enum class Status
{
    Blank   = ' ',
    Flagged = '*',
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

//bool isNumber(Status s)
//{
//    return s!=Status::Blank && s!=Status::Flagged && s!=Status::UnKnown;
//}

inline bool isNumber(Status s)
{
    return     s==Status::Number1
            || s==Status::Number2
            || s==Status::Number3
            || s==Status::Number4
            || s==Status::Number5
            || s==Status::Number6
            || s==Status::Number7
            || s==Status::Number8;
}

enum class MineLevel
{
    Small,
    Medium,
    Large,
};

#endif // STATUS_H

