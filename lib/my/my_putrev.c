/*
** EPITECH PROJECT, 2020
** my put rev
** File description:
** put reverse string
*/

void my_putchar(char c);
int my_strlen(char *str);

void my_putrev(char *str)
{
    int c = my_strlen(str);

    for (c ; c != -1; c--)
        my_putchar(str[c]);
    return;
}
