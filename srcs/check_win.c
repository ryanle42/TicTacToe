#include "ticktac.h"

int     check_vert(char *board, int pos)
{
    char c;
    int count = 0;
    int tmp;

    c = board[pos];
    tmp = pos;
    while (tmp - 4 >= 0)
    {
        if (board[tmp - 4] == c)
            count++;
        tmp -= 4;
    }
    tmp = pos;
    while (tmp + 4 < 11)
    {
        if (board[tmp + 4] == c)
            count++;
        tmp += 4;
    }
    return (count == 2) ? (1) : (0);
}

int     check_horz(char *board, int pos)
{
    char c;
    int count = 0;
    int tmp;

    c = board[pos];
    tmp = pos;
    while (tmp - 1 >= 0)
    {
        if (board[tmp - 1] == '\n')
            break;
        if (board[tmp - 1] == c)
            count++;
        tmp--;
    }
    tmp = pos;
    while (tmp + 1 <= 11)
    {
        if (board[tmp + 1] == '\n')
            break;
        if (board[tmp + 1] == c)
            count++;
        tmp++;
    }
    return (count == 2) ? (1) : (0);
}

int     check_ldiag(char *board, int pos)
{
    char c;
    int count = 0;
    int tmp;

    c = board[pos];
    tmp = pos;
    while (tmp - 5 >= 0)
    {
        if (board[tmp - 5] == c)
            count++;
        tmp -= 5;
    }
    tmp = pos;
    while (tmp + 5 <= 11)
    {
        if (board[tmp + 5] == c)
            count++;
        tmp += 5;
    }
    return (count == 2) ? (1) : (0);
}

int     check_rdiag(char *board, int pos)
{
    char c;
    int count = 0;
    int tmp;

    c = board[pos];
    tmp = pos;
    while (tmp - 3 >= 0)
    {
        if (board[tmp - 3] == '\n')
            break;
        if (board[tmp - 3] == c)
            count++;
        tmp -= 3;
    }
    tmp = pos;
    while (tmp + 3 <= 11)
    {
        if (board[tmp + 3] == '\n')
            break;
        if (board[tmp + 3] == c)
            count++;
        tmp += 3;
    }
    return (count == 2) ? (1) : (0);
}

int     check_win(char *board, int pos)
{
    if (check_ldiag(board, pos))
        return (1);
    if (check_rdiag(board, pos))
        return (1);
    if (check_horz(board, pos))
        return (1);
    if (check_vert(board, pos))
        return (1);
    return (0);
}
