/*
** EPITECH PROJECT, 2020
** my show str
** File description:
** contain my showstr
*/

#include<unistd.h>

void my_putchar(char c);
void my_put_hexa(int nb);

int my_showstr(char const *str)
{
    int cpt = 0;
    int v;
    int r;

    for (;str[cpt] != '\0'; cpt++) {
        if (str[cpt] > 31 && str[cpt] < 127)
            my_putchar(str[cpt]);
        else {
            my_putchar('\\');
            my_putchar('0');
            if (str[cpt] < 16)
                my_putchar('0');
            my_put_hexa(str[cpt]);
        }
    }
    return 0;
}
