/*
** EPITECH PROJECT, 2020
** my getnbr
** File description:
** contain function my getnbr
*/

int my_getnbr(char const *str)
{
    int c;
    int nb = 0;
    int signe = 1;

    for (c = 0; str[c] == 43 || str[c] == 45; c++) {
        if (str[c] == 45)
            signe = signe * -1;
    }
    for (c; str[c] > 47 && str[c] < 58; c++) {
        if (nb > 214748364) {
            return 0;
        } else if (nb == 214748364) {
            if (signe == -1 && str[c] > '8')
                return 0;
            if (signe == 1 && str[c] > '7')
                return 0;
            return ((signe * nb * 10) + signe * (str[c] - 48));
        }
        nb = ((nb * 10) + (str[c] - 48));
    }
    return (nb * signe);
}
