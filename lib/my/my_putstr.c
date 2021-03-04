/*
** EPITECH PROJECT, 2020
** my putstr
** File description:
** contain the function my put str
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
