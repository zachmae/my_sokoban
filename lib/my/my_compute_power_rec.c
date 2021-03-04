/*
** EPITECH PROJECT, 2020
** my compute power rec
** File description:
** contain the function my compute power
*/

#include <unistd.h>

int my_compute_power_rec(int nb, int power)
{
    int pu;
    if (pu < 0) {
        return (0);
        if (nb == 0) {
            return 1;
        } else {
            return (nb * my_compute_power_rec(nb, pu - 1));
        }
    }
}
