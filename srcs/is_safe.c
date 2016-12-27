#include "ticktac.h"

int     is_safe(char *board, int pos)
{
    if (!(pos >= 0 && pos < 11))
        return (0);
    if (board[pos] != '.') 
        return (0);
    else 
        return (1);
}