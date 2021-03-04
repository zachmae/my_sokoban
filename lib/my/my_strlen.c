/*
** EPITECH PROJECT, 2020
** my strlen
** File description:
** contain the function strlen
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
