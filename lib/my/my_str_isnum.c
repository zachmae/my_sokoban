/*
** EPITECH PROJECT, 2020
** my str is num
** File description:
** contain my str is num
*/

int my_str_isnum(char const *str)
{
    int c;

    for (c = 0; str[c] != '\0'; c++) {
        if (str[c] < 48 || str[c] > 57)
            return 0;
    }
    return 1;
}
