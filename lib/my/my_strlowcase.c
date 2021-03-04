/*
** EPITECH PROJECT, 2020
** my strlowcase
** File description:
** contain my strlowcase
*/

char *my_strlowcase(char *str)
{
    int c;
    for (c = 0; str[c] != '\0'; c++) {
        if (str[c] < 91 && str[c] > 64)
            str[c] = str[c] + 32;
    }
    return (str);
}
