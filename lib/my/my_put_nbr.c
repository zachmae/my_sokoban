/*
** EPITECH PROJECT, 2020
** my put nbr
** File description:
** contain the function my put nbr
*/

#include <unistd.h>

void my_putchar(char c);

int     my_put_nbr(int nb)
{
    if (nb < 0)
    {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
    {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    if (nb < 10)
    {
        my_putchar(nb % 10 + '0');
    }
    return (nb);
}

unsigned int my_put_uint(unsigned int nb)
{
    if (nb >= 10)
    {
        my_put_uint(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    if (nb < 10)
    {
        my_putchar(nb % 10 + '0');
    }
    return (nb);
}
