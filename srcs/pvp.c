#include "ticktac.h"

int pvp()
{
    char *board;
    char p_piece;
    char c_piece;
    int pos;
    int end;
    char *guide;
    int i;

    guide = "123\n456\n789\n";
    board = make_board();
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
        new_line();
        printf("PvP\n\n");
        print_board(board);
        print_guide();
        if (i % 2 == 0)
            printf("P1 Pos: ");
        else
            printf("P2 Pos: ");
        scanf("%i", &pos);
        pos = adj_pos(pos);
        while (!(is_safe(board, pos)))
        {
            new_line();
            printf("PvP\n");
            print_board(board);
            print_guide();
            printf("\nYou can't put a piece there!\n");
            if (i % 2 == 0)
                printf("P1 Pos: ");
            else
                printf("P2 Pos: ");
            scanf("%i", &pos);
            pos = adj_pos(pos);
        }
        if (i % 2 == 0)
            board[pos] = p_piece;
        else
            board[pos] = c_piece;
        if ((check_win(board, pos)))
        {
            new_line();
            printf("PvP\n\n");
            print_board(board);
            if (i % 2 == 0)
                printf("Player 1 Wins!\n");
            else
                printf("Player 2 Wins!\n");
            end = 1;
        }
        if (filled_board(board) && !end)
        {
            new_line();
            printf("PvP\n\n");
            print_board(board);
            printf("Draw!\n");
            end = 1;
        }
        i++;
    }
    return (1);
}