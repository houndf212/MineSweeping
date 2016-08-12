#ifndef BOARDPRINTER_H
#define BOARDPRINTER_H
#include "board.h"

class BoardPrinter
{
public:
    static void print_r(const Board& b) { print(b.real_matrix); }
    static void print_u(const Board& b);
private:
    static void print(const StatusMatrix& m);
};

#endif // BOARDPRINTER_H
