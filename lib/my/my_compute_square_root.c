/*
** EPITECH PROJECT, 2020
** my compute square root
** File description:
** contain my compute square root
*/

int my_compute_square_root(int nb)
{
    int c;
    int V;

    c = 0;
    V = 1;
    while (c <  nb) {
        c = V * V;
        if (c < nb) {
            V++;
        } else if (c == nb) {
            return V;
        } else {
            return 0;
        }
    }
}
