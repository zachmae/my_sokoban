/*
** EPITECH PROJECT, 2020
** my sort in array
** File description:
** contain the function my sort in array
*/

void my_sort_int_array(int *tab, int size)
{
    int c;
    int i;
    int tmp;

    for (c = 0; c < size; c++) {
        for (i = 0; i < size; i++) {
            if (tab[c] > tab[i]) {
                tmp = tab[c];
                tab[c] = tab[i];
                tab[i] = tmp;
            }
        }
    }
    return;
}
