/*
** EPITECH PROJECT, 2020
** my base
** File description:
** handle different bases
*/

int my_put_nbr(int nb);
int my_putstr(char const *str);
void my_putchar(char c);

void my_put_binary(int nb)
{
    if (nb > 1)
        my_put_binary(nb / 2);
    my_put_nbr(nb % 2);
}

void my_put_octal(int nb)
{
    if (nb > 8)
        my_put_octal(nb / 8);
    my_put_nbr(nb % 8);
}

void my_put_hexa(int nb)
{
    if (nb > 15)
        my_put_hexa(nb / 16);
    nb = nb % 16;
    if (nb < 10)
        my_put_nbr(nb);
    else
        my_putchar(87 + nb);
}

void my_put_uphexa(int nb)
{
    if (nb > 15)
        my_put_hexa(nb / 16);
    nb = nb % 16;
    if (nb < 10)
        my_put_nbr(nb);
    else
        my_putchar(55 + nb);
}

void my_put_ptr(int ptr)
{
    my_putstr("0x");
    my_put_hexa(ptr);
}
