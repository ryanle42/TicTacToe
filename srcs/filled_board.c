#include "ticktac.h"

int filled_board(char *board)
{
    int i;

    i = 0;
    while (board[i])
    {
        if (board[i] == '.')
            return (0);
        i++;
    }
    return (1);
}