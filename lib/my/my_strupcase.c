/*
** EPITECH PROJECT, 2020
** my strupcase
** File description:
** contain my strupcase
*/

char *my_strupcase(char *str)
{
    int c;

    for (c = 0; str[c] != '\0'; c++) {
        if (str[c] < 123 && str[c] > 96)
            str[c] = str[c] - 32;
    }
    return (str);
}
