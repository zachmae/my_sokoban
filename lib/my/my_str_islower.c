/*
** EPITECH PROJECT, 2020
** my str is lower
** File description:
** contain my str is lower
*/

int my_str_islower(char const *str)
{
    int c;

    for (c = 0; str[c] != '\0'; c++) {
        if (str[c] < 97 || str[c] > 122)
            return 0;
    }
    return 1;
}
