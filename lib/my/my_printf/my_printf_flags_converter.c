/*
** EPITECH PROJECT, 2021
** my printf flag Hexa Oct Dec
** File description:
** Function for convert flags
*/

#include "my.h"

void my_putnbr_oct(unsigned int nbr)
{
    char *base = "01234567";
    int len = my_strlen(base);

    if (nbr >= len) {
        my_putnbr_oct(nbr / len);
        my_putchar(base[nbr % len]);
    }
    if (nbr < len)
        my_putchar(base[nbr % len]);
}

void my_putnbr_hexalow(unsigned int nbr)
{
    char *base = "0123456789abcdef";
    int len = my_strlen(base);

    if (nbr >= len) {
        my_putnbr_hexalow(nbr / len);
        my_putchar(base[nbr % len]);
    }
    if (nbr < len)
        my_putchar(base[nbr % len]);
}

void my_putnbr_hexaup(unsigned int nbr)
{
    char *base = "0123456789ABCDEF";
    int len = my_strlen(base);

    if (nbr >= len) {
        my_putnbr_hexaup(nbr / len);
        my_putchar(base[nbr % len]);
    }
    if (nbr < len)
        my_putchar(base[nbr % len]);
}

void my_putnbr_dec(unsigned int nbr)
{
    char *base = "0123456789";
    int len = my_strlen(base);

    if (nbr >= len) {
        my_putnbr_dec(nbr / len);
        my_putchar(base[nbr % len]);
    }
    if (nbr < len)
        my_putchar(base[nbr % len]);
}
