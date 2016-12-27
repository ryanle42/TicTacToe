#include "ticktac.h"

int     adj_pos(int pos)
{
    if (pos <= 3)
        pos--;
    else if (pos >= 7)
        pos++;
    return (pos);
}