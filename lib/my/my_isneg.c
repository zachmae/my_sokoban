/*
** EPITECH PROJECT, 2020
** my isneg
** File description:
** contain the function my isneg
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_isneg(int nb)
{
    if (nb >= 0){
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    my_putchar('\n');
}
