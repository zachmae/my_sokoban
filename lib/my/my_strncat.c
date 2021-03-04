/*
** EPITECH PROJECT, 2020
** my strncat
** File description:
** contain my strncat
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int c;

    while (dest[i] != '\0') {
        i++;
    }
    for (c = 0; src[c] != '\0' && c < nb; c++) {
        dest[i] = src[c];
        i++;
    }
    dest[i + 1] = '\0';
    return dest;
}
