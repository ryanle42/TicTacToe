#include "ticktac.h"

char    choose_piece()
{
    char c[100];

    printf("\nX goes first. Choose X or O\n");
    while (c[0] != 'x' && c[0] != 'o' && c[0] != 'X' && c[0] != 'O' || strlen(c) > 1)
    {
        scanf("%s", c);
        if (c[0] != 'x' && c[0] != 'o' && c[0] != 'X' && c[0] != 'O' || strlen(c) > 1)
            printf("Type X or O\n");
    }
    return (c[0]);
}