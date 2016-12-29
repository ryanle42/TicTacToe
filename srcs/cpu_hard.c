#include "ticktac.h"

int     cpu_hard()
{
    
    char *board;
    char p_piece, c_piece;
    char *cpy;
    int i, j, k, place, pos, end;
    int turn = 1;
    int draw = 0;
    int random;

    srand (time(NULL));
    board = make_board();
    new_line();
    printf("CPU Hard\n");
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
    //player 1 move
    while (!end)
    {
        if (i % 2 == 0)
        {
            turn++;
            new_line();
            printf("CPU Hard\n\n");
            print_board(board);
            print_guide();
            printf("Your turn: ");
            scanf("%i", &pos);
            pos = adj_pos(pos);
            while (!(is_safe(board, pos)))
            {
                new_line();
                printf("CPU Hard\n\n");
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
                printf("CPU Hard\n\n");
                print_board(board);
                printf("You win!\n");
                end = 1;
            }
            if (filled_board(board) && !end)
            {
                new_line();
                printf("CPU Hard\n\n");
                print_board(board);
                printf("Draw!\n");
                end = 1;
            }
        }
        //cpu turn
        if (i % 2 != 0 && !end)
        {
            place = 0;
            // protect insta-win
            if (turn == 2 && c_piece == 'O')
            {
                j = turn_one(pos);
                if (is_safe(board, j))
                {
                    board[j] = c_piece;
                    k = j;
                    place++;
                    draw++;
                }
            }
            //can_win
            j = 0;
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
            // Go for draw
            if (turn == 3 && c_piece == 'O' && draw && !place)
            {
                random = 0;
                while (!(random >= 1 && random <= 4))
                    random = rand() % 4;
                if (random == 1)
				{
				 	if (is_safe(board, 1))
                        j = 1;
                    else
                        random++;
				}
                if (random == 2)
				{
                    if (is_safe(board, 5))
                        j = 5;
                    else
                        random++;
				}
                if  (random == 3)
				{
				 	if (is_safe(board, 7))
                        j = 7;
                    else
                        random++;
				}
				if (random == 4)
				 	if (is_safe(board, 9))
                        j = 9;
                if (is_safe(board, j))
                {
                    board[j] = c_piece;
                    k = j;
                    place++;
                }
            }
            if (!place)
            {
                if (is_safe(board, 10))
                    j = 10;
                else if (is_safe(board, 8))
                    j = 8;
                else if (is_safe(board, 2))
                    j = 2;
                else if (is_safe(board, 0))
                    j = 0;
                if (is_safe(board, j))
                {
                    board[j] = c_piece;
                    k = j;
                    place++;
                }
            }
            if (!place)
            {
                while (!(is_safe(board, j)))
                {
                    j = rand() % 11;
                }
                if (is_safe(board, j))
                {
                    board[j] = c_piece;
                    k = j;
                    place++;
                }
            }
            if ((check_win(board, k)))
            {
                new_line();
                printf("CPU Hard\n\n");
                print_board(board);
                printf("You lose.\n");
                end = 1;
            }
            if (filled_board(board) && !end)
            {
                new_line();
                printf("CPU Hard\n\n");
                print_board(board);
                printf("Draw!\n");
                end = 1;
            }
        }
        i++;
    }
    return (1);
}
