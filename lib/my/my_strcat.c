/*
** EPITECH PROJECT, 2020
** my strcat
** File description:
** contain my strcat
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int c;

    while (dest[i] != '\0') {
        i++;
    }
    for (c = 0; src[c] != '\0'; c++) {
        dest[i] = src[c];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
