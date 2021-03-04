/*
** EPITECH PROJECT, 2021
** main
** File description:
** main function
*/

#include "sokoban.h"

char *get_file(char **av)
{
    int fd = open(av[1], O_RDONLY);
    char *buff = malloc(sizeof(char) * 10000000000);
    int offset = 0;
    int len;

    if (fd == -1) {
        error("error, file does not exist.\n");
    }
    while ((len = read(fd , buff + offset , 10000000000 - offset)) > 0) {
        offset = offset + len;
    }
    if (offset == 0) {
        error("empty file\n");
    }
    buff[offset] = '\0';
    close(fd);
    return buff;
}

void error(char *str)
{
    write(2, str, my_strlen(str));
    exit(84);
}

int error_handle(int ac, char **av)
{
    if (ac != 2) {
        write(2, "read usage.\n", 13);
        return 84;
    }
    return 0;
}

int print_usage(int ac, char **av)
{
    if (ac == 2)
        if (my_strcmp(av[1], "-h") == 0) {
            my_printf("Hello, this is my_sokoban, a 1st year EPITECH project"
            "\nthis game is an adaptation of the eponym japanese game\n");
            my_printf("USAGE\n\t./my_popup map\n");
            my_printf("DESCRIPTION\n\tmap\ta file representing the map you "
            "will play in.\n\t\t'#' will represent walls\n\t\t"
            "'P' represent player\n\t\t'X' represent box"
            "\n\t\t'O' represent storages\n");
            my_printf("\t\tuse arrows key to move, "
            "space to reset the map and r to quit\n");
            return 1;
        }
    return 0;
}

int main(int ac, char **av)
{
    if (print_usage(ac, av) == 1)
        return 0;
    if (error_handle(ac, av) == 84)
        return 84;
    return (sokoban(av));
}