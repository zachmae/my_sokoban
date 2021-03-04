/*
** EPITECH PROJECT, 2020
** my strncmp
** File description:
** contain my strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int c = 0;

    while (s1[c] == s2[c] && s1[c] && s2[c] && c < n)
        c++;
    if ((s1[c] == '\0' && s2[c] == '\0') || c == n)
            return 0;
    else if (s1[c] > s2[c])
            return 1;
    else
        return -1;

}
