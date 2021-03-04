/*
** EPITECH PROJECT, 2021
** sokoban.c
** File description:
** major part of my sokoban
*/

#include "sokoban.h"

int check_winlose(char **map, int key, char **init_map)
{
    int y;
    int x;
    int win = 1;
    int lose;

    if (key == ' ')
        return 1;
    for (y = 0; map[y] != NULL; y++) {
        for (x = 0; map[y][x] != '\0'; x++) {
            if (init_map[y][x] == 'O' && map[y][x] != 'X')
                win = 0;
        }
    }
    lose = check_lose(map, init_map);
    if (win == 1)
        return 0;
    else if (lose == 1)
        return 1;
    return 2;
}

pos *get_pos_player(char **map)
{
    pos *player = malloc(sizeof(pos));
    int y = 0;
    int x = 0;

    for (y = 0; map[y] != NULL; y++) {
        for (x = 0; map[y][x] != '\0'; x++) {
            if (map[y][x] == 'P') {
                player->y = y;
                player->x = x;
                return player;
            }
        }
    }
}

int map_handling(char *str)
{
    int c;
    int p = 0;
    int b = 0;
    int o = 0;

    for (c = 0; str[c] != '\0'; c++) {
        if (str[c] != 'X' && str[c] != 'P' && str[c] != ' ' && str[c] != 'O'
            && str[c] != '\n' && str[c] != '#' && str[c] != 'R'
            && str[c] != 'G')
            return 84;
        if (str[c] == 'P')
            p++;
        if (str[c] == 'X')
            b++;
        if (str[c] == 'O')
            o++;
    }
    if (p != 1 || o > b)
        return 84;
    return 0;
}

int my_game(char **map, char **init_map, char *str)
{
    pos *player;
    int key = -1;
    int res = 2;
    int cpt = 0;
    int retry = 0;
    sfMusic *music = sfMusic_createFromFile("assets/music.ogg");

    sfMusic_play(music);
    sfMusic_setLoop(music, TRUE);
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    while (key != ' ' && res != 1 && res != 0) {
        player = get_pos_player(map);
        disp_game(map, cpt, retry, str);
        key = getch();
        handle_mvt(map, key, player, init_map);
        cpt++;
        if (key == 'r') {
            map = my_tabcpy(init_map, map);
            free(init_map);
            init_map = str_to_word_array(str, '\n');
            cpt = 0;
            retry++;
        }
        res = check_winlose(map, key, init_map);
    }
    endwin();
    curs_set(1);
    sfMusic_destroy(music);
    if (res == 0)
        my_printf("%s: YOU WON, %d moves and %d retries\n", str, cpt, retry);
    else
        my_printf("%s: YOU LOST\n", str);
    return res;
}

int sokoban(char **av)
{
    char *mapstr = get_file(av);
    int res;
    char **map = str_to_word_array(mapstr, '\n');
    char **init_map = str_to_word_array(mapstr, '\n');

    if (map_handling(mapstr) == 84) {
        write(2, "invalid map\n", 13);
        return 84;
    }
    res = my_game(map, init_map, mapstr);
    return res;
}