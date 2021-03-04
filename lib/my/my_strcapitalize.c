/*
** EPITECH PROJECT, 2020
** my strcapitalize
** File description:
** contain my strcapitalize
*/

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str)
{
    int i = 0;
    str = my_strlowcase(str);
    if (str[i] > 96 && str[i] < 123)
        str[0] = str[0] - 32;
    while (str[i] != '\0') {
        if (str[i-1] > 31 && str[i-1] <48 && str[i] > 96 && str[i] < 123) {
            str[i] = str[i] - 32;
        }
        i++;
    }
    return (str);
}
