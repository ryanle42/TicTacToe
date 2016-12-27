#include "ticktac.h"

char    *copy_board(char *board)
{
    int i;
    char *cpy;

    i = 0;
    cpy = (char *)malloc(sizeof(char) * 12);
    while (board[i])
    {
        cpy[i] = board[i];
        i++;
    }
    cpy[i] = '\0';
    return (cpy);
}