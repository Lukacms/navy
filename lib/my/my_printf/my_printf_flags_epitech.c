/*
** EPITECH PROJECT, 2021
** my printf flags Special
** File description:
** Function for %S and %b flags
*/

#include "my.h"

void my_putnbr_oct(unsigned int nbr);

void uppercase_s(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] < 8 && str[i] < 32) {
            my_putchar('\\');
            my_putstr("00");
        } else if (str[i] > 8 && str[i] < 32) {
            my_putchar('\\');
            my_putchar('0');
        }
        if (str[i] == 127)
            my_putchar('\\');
        if (str[i] < 32 || str[i] == 127) {
            my_putnbr_oct(str[i]);
        } else {
            my_putchar(str[i]);
        }
    }
}

void my_putnbr_bin(unsigned int nbr)
{
    char *base = "01";
    int len = my_strlen(base);

    if (nbr < 0) {
        my_putchar('-');
        nbr *= -1;
    }
    if (nbr >= len) {
        my_putnbr_bin(nbr / len);
        my_putchar(base[nbr % len]);
    }
    if (nbr < len)
        my_putchar(base[nbr % len]);
}
