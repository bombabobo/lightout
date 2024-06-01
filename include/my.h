#ifndef MY_H_
    #define MY_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "struct.h"
    #include "init.h"

void decimal_to_octal(int decinum, int *ptr);
void decimal_to_hexa(int decinum, int *ptr, int l);
int my_put_int(int nb, int *ptr);
int my_put_ptr(unsigned long nb, int *ptr);
unsigned int my_put_unsigned_int(unsigned int nb, int *ptr);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int *my_getnbr(char const *str);
int my_is_prime(int nb);
void my_isneg(int n);
int my_put_nbr(int nb);
void my_putcharptr(char c, int *ptr);
void my_putchar(char c);
int my_putstrptr(char const *str, int *ptr);
int my_put_float(double nb, int *ptr, int precision);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *array, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcapitalize(char *S);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char calclen(const char *str);
int imin(int a, int b);
int imax(int a, int b);
int my_printf(const char *format, ...);
int *upgraded_atoi(char *str, int numbers);
void analyse_events(sfRenderWindow *window, sfEvent *event, gstruct *gstruct);
void sp_upd_all(gstruct *gst, sfRenderWindow *window);
void create_sprites(gstruct *gstruct);
void random_tab_create(gstruct *gstruct);


#endif /* !MY_H_ */
