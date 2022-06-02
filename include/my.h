/*
** EPITECH PROJECT, 2021
** my
** File description:
** Macro which use libmy.a
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>

void my_putchar(char c);
int my_isneg(int nb);
void my_put_nbr(int nb);
void my_swap(int *a, int *b);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *chr);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char my_strupcase(char *str);
char my_strlowcase(char *str);
char *my_strcapitalize(char const *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
int my_printf(char const *format, ...);
void my_putnbr_bin(unsigned int nbr);
void my_putnbr_hexalow(unsigned int nbr);
void my_putnbr_hexaup(unsigned int nbr);
void my_putnbr_oct(unsigned int nbr);
void my_putnbr_dec(unsigned int nbr);
void uppercase_s(char *str);
void display_hashtag(char *ch, int *i, void *tmp);
void display_space(char *format, int *i, int argument);
void get_nbr_for_spaces(char *format, int *i, void *tmp);
void spaces_nbr(int *argument, int nbr);
void spaces_strings(char *argument, int nbr);
void spaces_characters(char *argument, int nbr);
void wrapper_putnbr_hexaup(va_list *list);
void wrapper_putnbr_dec(va_list *list);
void wrapper_putnbr(va_list *list);
void wrapper_putchar(va_list *list);
void wrapper_putstr(va_list *list);
void wrapper_putnbr_oct(va_list *list);
void wrapper_putnbr_hexalow(va_list *list);
void wrapper_uppercase_s(va_list *list);
void wrapper_putnbr_bin(va_list *list);
void wrapper_put_percentage(va_list *list);
void put_percentage(void);
void wrapper_put_pointer(va_list *list);

typedef struct flags_s {
    char flag;
    void (*fptr)(va_list *);
} flags_t;

typedef struct modifier_s {
    char flag;
    void (*fptr)();
} modifier_t;

typedef struct converter_and_symbol_s {
    char flag;
    char *str;
} converter_and_symbol_t;

#endif /* MY_H_ */
