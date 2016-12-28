#include "ticktac.h"

int cpu_easy()
{
    char *board;
    char p_piece;
    char c_piece;
    int pos;
    int end;
    int i;

    srand (time(NULL));
    board = make_board();
    new_line();
    printf("CPU Easy\n");
    p_piece = choose_piece();
    if (p_piece == 'x' || p_piece == 'X')
    {
        p_piece = 'X';
        c_piece = 'O';
        i = 0;
    }
    else if (p_piece == 'o' || p_piece == 'O')
    {
        p_piece = 'O';
        c_piece = 'X';
        i = 1;
    }
    end = 0;
    while (!end)
    {
        if (i % 2 == 0)
        {
            new_line();
            printf("CPU Easy\n\n");
            print_board(board);
            print_guide();
            printf("Your turn: ");
            scanf("%i", &pos);
            pos = adj_pos(pos);
            while (!(is_safe(board, pos)))
            {
                new_line();
                printf("CPU Easy\n\n");
                print_board(board);
                print_guide();
                printf("\nYou can't put a piece there!\n");
                printf("Your turn: ");
                scanf("%i", &pos);
                pos = adj_pos(pos);
            }
            board[pos] = p_piece;
            if ((check_win(board, pos)))
            {
                new_line();
                printf("CPU Easy\n\n");
                print_board(board);
                printf("You win!\n");
                end = 1;
            }
            if (filled_board(board) && !end)
            {
                new_line();
                printf("CPU Easy\n\n");
                print_board(board);
                printf("Draw!\n");
                end = 1;
            }
        }
        if (i % 2 != 0 && !end)
        {
            while (!(is_safe(board, pos)))
                pos = rand() % 11;
            board[pos] = c_piece;
            if ((check_win(board, pos)))
            {
                new_line();
                printf("CPU Easy\n\n");
                print_board(board);
                printf("You lose.\n");
                end = 1;
            }
            if (filled_board(board) && !end)
            {
                new_line();
                printf("CPU Easy\n\n");
                print_board(board);
                printf("Draw!\n");
                end = 1;
            }
        }
        i++;
    }
    return (1);
}