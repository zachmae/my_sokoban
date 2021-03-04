/*
** EPITECH PROJECT, 2020
** my printf
** File description:
** recreation of printf
*/

#include <stdarg.h>
#include <unistd.h>
#include "my_base.c"

int my_strlen(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
void my_putrev(char *str);
int my_showstr(char const *str);
unsigned int my_put_uint(unsigned int nb);
void my_put_ptr(int ptr);

void switch_casep1(char flag, va_list args)
{
    switch (flag) {
    case 'd':
        my_put_nbr(va_arg(args, int));
        break;
    case 's':
        my_putstr(va_arg(args, char *));
        break;
    case 'S':
        my_showstr(va_arg(args, char *));
        break;
    case 'c':
        my_putchar(va_arg(args, int));
        break;
    case 'u':
        my_put_uint(va_arg(args, unsigned int));
        break;
    case 'i':
        my_put_nbr(va_arg(args, int));
        break;
    }
}

void switch_casep2(char flag, va_list args)
{
    switch (flag) {
    case 'b':
        my_put_binary(va_arg(args, int));
        break;
    case 'o':
        my_put_octal(va_arg(args, int));
        break;
    case 'x':
        my_put_hexa(va_arg(args, int));
        break;
    case 'X':
        my_put_uphexa(va_arg(args, int));
        break;
    case 'p':
        my_put_ptr(va_arg(args, int));
        break;
    case 'r':
        my_putrev(va_arg(args, char *));
        break;
    }
}

void my_printf(char *s, ...)
{
    va_list args;
    int c = 0;
    char *order = s;
    int n = my_strlen(s);

    va_start(args, s);
    for (c; c < n ; c++) {
        if (order[c] == '%') {
            c++;
            if (order[c] == '%')
                my_putchar('%');
            switch_casep1(order[c], args);
            switch_casep2(order[c], args);
        } else
            my_putchar(order[c]);
    }
    va_end(args);
    return;
}
