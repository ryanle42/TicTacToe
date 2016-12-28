#ifndef TIC_TAC_H
# define TIC_TAC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

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