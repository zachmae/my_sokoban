/*
** EPITECH PROJECT, 2021
** small functions
** File description:
** bunch of small useful functions
*/

#include "sokoban.h"

int get_height(char *str)
{
    int c;
    int nb = 0;

    for (c = 0; str[c] != '\0'; c++)
        if (str[c] == '\n')
            nb++;
    if (str[c - 1] != '\n')
        nb++;
    return nb;
}

int get_width(char *str)
{
    int c;
    int i = 0;
    int max = 0;
    int j;

    for (c = 0; str[c + i] != '\0'; c++) {
        if (str[c + i] == '\n' || str[c + 1] == '\0'){
            j = c;
            i += c;
            c = 0;
            if (max < j)
                max = j;
        }
    }
    return (max);
}

void disp_game(char **map, int cpt, int retry, char *str)
{
    int y;
    int height = get_height(str);
    int width = get_width(str);
    const char *small = "window too small.";
    const char *credit = "Music: Layton's theme   Game by Zacharie Lawson.";

    clear();
    if (LINES < height || COLS < width)
            mvprintw(LINES / 2, COLS / 2 - my_strlen(small) / 2, "%s", small);
    else {
        mvprintw(LINES - 1, COLS - my_strlen(credit) , "%s", credit);
        mvprintw(0, 0, "vous avez effectué %d coups et %d retry", cpt, retry);
        for (y = 0; map[y] != NULL; y++)
            mvprintw(LINES / 2 - height / 2 + y,
                COLS / 2 - width / 2, "%s", map[y]);
    }
    refresh();
    curs_set(0);
}

int check_lose(char **map, char **init_map)
{
    int stor = get_occ(init_map, 'O');
    int box = get_occ(init_map, 'X');
    int y;
    int x;
    int seal = 0;

    for (y = 0; map[y] != NULL; y++)
        for (x = 0; map[y][x] != '\0'; x++)
            if (map[y][x] == 'X' && init_map[y][x] != 'O' &&
                check_seal(map[y - 1][x], map[y + 1][x],
                map[y][x - 1], map[y][x + 1]) == 1) {
                    seal++;
    }
    if (box - stor < seal)
        return 1;
    return 0;
}

int check_seal(char up, char down, char left, char right)
{
    if (up == '#' && (left == '#' || right == '#'))
        return 1;
    if (down == '#' && (left == '#' || right == '#'))
        return 1;
    return 0;
}