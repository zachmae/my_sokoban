/*
** EPITECH PROJECT, 2020
** my str is alpha
** File description:
** contain my str is alpha
*/

int my_str_isalpha(char const *str)
{
    int c;

    for (c = 0; str[c] != '\0'; c++) {
        if (str[c] < 65 || str[c] > 90 && str[c] < 97 || str[c] > 122)
            return 0;
    }
    return 1;
}
