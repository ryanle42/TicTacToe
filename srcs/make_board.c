#include "ticktac.h"

char    *make_board()
{
    char *tmp = "...\n...\n...\n";
    char *board;
    int i = 0;

    board = (char *)malloc(sizeof(char) * 12);
    while (tmp[i])
    {
        board[i] = tmp[i];
        i++;
    }
    board[i] = '\0';
    return (board);
}