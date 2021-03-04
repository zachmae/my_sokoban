/*
** EPITECH PROJECT, 2020
** my str is printable
** File description:
** contain my str is printable
*/

int my_str_isprintable(char const *str)
{
    int c;

    for (c = 0; str[c] != '\0'; c++) {
        if (str[c] < 32)
            return 0;
    }
    return 1;
}
