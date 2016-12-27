#include "ticktac.h"

int cpu_medium()
{
    char *board;
    char p_piece;
    char c_piece;
    char *guide;
    char *cpy;
    int turn;
    int i, j, k, place, pos, end;

    srand (time(NULL));
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
        if (i % 2 == 0)
        {
            new_line();
            printf("CPU Medium\n\n");
            print_board(board);
            print_guide();
            printf("Your turn: ");
            scanf("%i", &pos);
            pos = adj_pos(pos);
            while (!(is_safe(board, pos)))
            {
                new_line();
                printf("CPU Medium\n\n");
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
                printf("CPU Medium\n\n");
                print_board(board);
                printf("You win!\n");
                end = 1;
            }
            if (filled_board(board) && !end)
            {
                new_line();
                printf("CPU Medium\n\n");
                print_board(board);
                printf("Draw!\n");
                end = 1;
            }
        }
        if (i % 2 != 0 && !end)
        {
            j = 0;
            place = 0;
            //check win
            while (j < 11 && !place)
            {
                cpy = copy_board(board);
                if (is_safe(board, j))
                {
                    cpy[j] = c_piece;
                    if ((check_win(cpy, j)))
                    {
                        board[j] = c_piece;
                        k = j;
                        place++;
                    }
                }
                if (!place)
                    j++;
            }
            //block
            j = 0;
            while (j < 11 && !place)
            {
                cpy = copy_board(board);
                if (is_safe(board, j))
                {
                    cpy[j] = p_piece;
                    if ((check_win(cpy, j)))
                    {
                        board[j] = c_piece;
                        k = j;
                        place++;
                    }
                }
                if (!place)
                    j++;
            }
            if (!place)
            {
                while (!(is_safe(board, j)))
                {
                    j = rand() % 11;
                }
                board[j] = c_piece;
                k = j;
                place++;
            }
            if ((check_win(board, k)))
            {
                new_line();
                printf("CPU Medium\n\n");
                print_board(board);
                printf("You lose.\n");
                end = 1;
            }
            if (filled_board(board) && !end)
            {
                new_line();
                printf("CPU Medium\n\n");
                print_board(board);
                printf("Draw!\n");
                end = 1;
            }
        }
        i++;
    }
    return (1);
}