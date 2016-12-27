#ifndef TIC_TAC_H
# define TIC_TAC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int     check_win(char *board, int pos);
char    *place_piece(char *board, int pos, char piece);
int     is_safe(char *board, int pos);
int     adj_pos(int pos);
char    *make_board();
int     menu();
void    new_line();
int     pvp();
char    choose_piece();
int     cpu_easy();
int     cpu_medium();
int     cpu_hard();
char    *copy_board(char *board);
int     turn_one(int pos);
int     filled_board(char *board);
void    print_board(char *board);
void    print_guide();

# endif