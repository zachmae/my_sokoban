/*
** EPITECH PROJECT, 2020
** my strstr
** File description:
** contain my strstr
*/
#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int c = 0;

    if (to_find[0] == '\0')
        return (str);
    if (str[0] != '\0') {
        c = 0;
        while (to_find[c] != '\0') {
            if (to_find[c] != str[c])
                return (my_strstr(str + 1, to_find));
            c++;
        }
        return (str);
    }
    return (0);
}
