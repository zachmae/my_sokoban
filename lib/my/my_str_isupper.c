/*
** EPITECH PROJECT, 2020
** my str is upper
** File description:
** contain my str is upper
*/

int my_str_isupper(char const *str)
{
    int c;

    for (c = 0; str[c] != '\0'; c++) {
        if (str[c] < 65 || str[c] > 90)
            return 0;
    }
    return 1;
}
