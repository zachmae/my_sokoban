/*
** EPITECH PROJECT, 2020
** my is prime
** File description:
** contain the function my is prime
*/

int my_is_prime(int nb)
{
    int c;

    if (nb < 2)
        return 0;
    if (nb == 2)
        return 1;
    for (c = 2; c < nb; c++) {
        if (nb % c == 0)
            return 0;
    }
    return 1;
}
