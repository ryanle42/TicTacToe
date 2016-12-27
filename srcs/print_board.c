#include "ticktac.h"

void print_board(char *board)
{
    char *copy;
    int i = 0;

    copy = copy_board(board);
    while (copy[i])
    {
        if (copy[i] == '.')
            copy[i] = ' ';
        i++;
    }
    printf(" %c | %c | %c \n", copy[0], copy[1], copy[2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", copy[4], copy[5], copy[6]);
    printf("-----------\n");
    printf(" %c | %c | %c \n\n", copy[8], copy[9], copy[10]);
}