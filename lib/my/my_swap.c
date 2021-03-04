/*
** EPITECH PROJECT, 2020
** my swap
** File description:
** contain the function my swap
*/

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
