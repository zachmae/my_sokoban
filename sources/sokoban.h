/*
** EPITECH PROJECT, 2021
** my sokoban.h
** File description:
** .h file for sokoban
*/

#ifndef _SOKOBAN_H_
#define _SOKOBAN_H_

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include <curses.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <SFML/Audio.h>

typedef struct pos {
    int x;
    int y;
}pos;

void error(char *str);
int get_height(char *str);
int get_width(char *str);
int get_occ(char **tab, char c);
char **my_tabcpy(char **src, char **dest);
char **str_to_word_array(char *str, char lim);
void handle_mvt(char **map, int key, pos *player, char **init_map);
pos *get_pos_player(char **map);
int map_handling(char *str);
void disp_game(char **map, int cpt, int retry, char *str);
int check_winlose(char **map, int key, char **init_map);
int check_lose(char **map, char **init_map);
int my_game(char **map, char **init_map, char *str);
int check_seal(char up, char down, char left, char right);
int sokoban (char **av);
char *get_file(char **av);
int move_up(char **map, pos *player);
int move_down(char **map, pos *player);
int move_left(char **map, pos *player);
int move_right(char **map, pos *player);

#endif