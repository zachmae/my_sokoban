/*
** EPITECH PROJECT, 2020
** my strcmp
** File description:
** contain my strcmp
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int c;

    if (my_strlen(s1) > my_strlen(s2))
        return 1;
    else if (my_strlen(s1) < my_strlen(s2))
        return 1;
    for (c = 0; s1[c] != '\0' && s2[c] != '\0'; c++) {
        if (s1[c] > s2[c])
            return 1;
        if (s2[c] > s1[c])
            return -1;
    }
    return 0;
}
