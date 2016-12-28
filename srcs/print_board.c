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
	i = 0;
	while (i < 3)
	{
		if (copy[i] == 'X')
			printf(ANSI_COLOR_RED " %c " ANSI_COLOR_RESET, copy[i]);
		if (copy[i] == 'O')
			printf(ANSI_COLOR_YELLOW " %c " ANSI_COLOR_RESET, copy[i]);
        if (copy[i] == ' ')
			printf(" %c ", copy[i]);
		if (i < 2)
			printf("|");
        i++;
	}
    i++;
	printf("\n-----------\n");
    while (i < 7)
    {
        if (copy[i] == 'X')
            printf(ANSI_COLOR_RED " %c " ANSI_COLOR_RESET, copy[i]);
        if (copy[i] == 'O')
            printf(ANSI_COLOR_YELLOW " %c " ANSI_COLOR_RESET, copy[i]);
        if (copy[i] == ' ')
            printf(" %c ", copy[i]);
        if (i < 6)
            printf("|");
        i++;
    }
    i++;
    printf("\n-----------\n");
    while (i < 11)
    {
        if (copy[i] == 'X')
            printf(ANSI_COLOR_RED " %c " ANSI_COLOR_RESET, copy[i]);
        if (copy[i] == 'O')
            printf(ANSI_COLOR_YELLOW " %c " ANSI_COLOR_RESET, copy[i]);
        if (copy[i] == ' ')
            printf(" %c ", copy[i]);
        if (i < 10)
            printf("|");
        i++;
    }
    printf("\n\n");
}
