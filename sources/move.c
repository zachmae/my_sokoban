/*
** EPITECH PROJECT, 2021
** handle movement
** File description:
** move.c
*/

#include "sokoban.h"

void handle_mvt(char **map, int key, pos *player, char **init_map)
{
    int y;
    int x;

    if (key == KEY_UP)
        move_up(map, player);
    if (key == KEY_DOWN)
        move_down(map, player);
    if (key == KEY_LEFT)
        move_left(map, player);
    if (key == KEY_RIGHT)
        move_right(map, player);
    for (y = 0; map[y] != NULL; y++) {
        for (x = 0; map[y][x] != '\0'; x++) {
            if ((init_map[y][x] == 'O' || init_map[y][x] == 'R' || init_map[y][x] == 'G') && map[y][x] == ' ')
                map[y][x] = init_map[y][x];
        }
    }
}

int move_up(char **map, pos *p)
{
    int off;

    if (map[p->y - 1][p->x] == 'X' && map[p->y - 2][p->x] != '#'
        && map[p->y - 2][p->x] != 'X' && map[p->y - 2][p->x] != 'R') {
        for (off = 2; map[p->y - off - 1][p->x] == 'G'; off++);
        map[p->y][p->x] = ' ';
        map[p->y - 1][p->x] = 'P';
        map[p->y - off][p->x] = 'X';
    } else if (map[p->y - 1][p->x] != 'X' && map[p->y - 1][p->x] != '#') {
        map[p->y][p->x] = ' ';
        map[p->y - 1][p->x] = 'P';
    }
    return 0;
}

int move_down(char **map, pos *p)
{
    int off;

    if (map[p->y + 1][p->x] == 'X' && map[p->y + 2][p->x] != '#'
        && map[p->y + 2][p->x] != 'X' && map[p->y + 2][p->x] != 'R') {
        for (off = 2; map[p->y + off + 1][p->x] == 'G'; off++);
        map[p->y][p->x] = ' ';
        map[p->y + 1][p->x] = 'P';
        map[p->y + off][p->x] = 'X';
    } else if (map[p->y + 1][p->x] != 'X' && map[p->y + 1][p->x] != '#') {
        map[p->y][p->x] = ' ';
        map[p->y + 1][p->x] = 'P';
    }
    return 0;
}

int move_left(char **map, pos *p)
{
    int off;

    if (map[p->y][p->x - 1] == 'X' && map[p->y][p->x - 2] != '#'
        && map[p->y][p->x - 2] != 'X' && map[p->y][p->x - 2] != 'R') {
        for (off = 2; map[p->y][p->x - off - 1] == 'G'; off++);
        map[p->y][p->x] = ' ';
        map[p->y][p->x - 1] = 'P';
        map[p->y][p->x - off] = 'X';
    } else if (map[p->y][p->x - 1] != 'X' && map[p->y][p->x - 1] != '#') {
        map[p->y][p->x] = ' ';
        map[p->y][p->x - 1] = 'P';
    }
    return 0;
}

int move_right(char **map, pos *p)
{
    int off;

    if (map[p->y][p->x + 1] == 'X' && map[p->y][p->x + 2] != '#'
        && map[p->y][p->x + 2] != 'X' && map[p->y][p->x + 2] != 'R') {
        for (off = 2; map[p->y][p->x + off + 1] == 'G'; off++);
        map[p->y][p->x] = ' ';
        map[p->y][p->x + 1] = 'P';
        map[p->y][p->x + off] = 'X';
    } else if (map[p->y][p->x + 1] != 'X' && map[p->y][p->x + 1] != '#') {
        map[p->y][p->x] = ' ';
        map[p->y][p->x + 1] = 'P';
    }
    return 0;
}
