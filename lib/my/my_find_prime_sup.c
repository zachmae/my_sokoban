/*
** EPITECH PROJECT, 2020
** my find prime
** File description:
** contain my find prime
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    for (nb; ; nb++)
        if (my_is_prime(nb) == 1)
            return nb;
}
