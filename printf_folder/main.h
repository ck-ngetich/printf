#ifndef MAIN_H
#define MAIN_H


#include <stdlib.h>
#include <stdarg.h>



/**
 * struct flags - the struct containing flags to be activated
 * when a flag specifier is passed to _printf()
 * @pls: flag for '+'
 * @spc: flag for ' '
 * @hsh: flag for '#'
 */

typedef struct flags

{
int pls;
int spc;
int hsh;
} flags_t;



/**
 * struct handler - struct to choose the right function
 * @c: the format specifier
 * @f: the pointer to the correct printing function
 */

typedef struct handler

{
char c;
int (*f)(va_list ap, flags_t *f);
} ph;



/* print numbers */
int print_int(va_list l, flags_t *f);
void print_number(int n);
int print_unsigned(va_list l, flags_t *f);
int count_digit(int i);



/* print bases */
int print_hex(va_list l, flags_t *f);
int print_hex_caps(va_list l, flags_t *f);
int print_binary(va_list l, flags_t *f);
int print_octal(va_list l, flags_t *f);


/* converter */
char *convert(unsigned long int num, int base, int lowercase);


/* _printf */
int _printf(const char *format, ...);


/* get print */
int (*get_print(char s))(va_list, flags_t *);



/* get flag */
int get_flag(char s, flags_t *f);



/* print alpha */
int print_string(va_list l, flags_t *f);
int print_char(va_list l, flags_t *f);


/* write functions */
int _putchar(char c);
int _puts(char *str);


/* print custom specifiers */
int print_rot13(va_list l, flags_t *f);
int print_rev(va_list l, flags_t *f);
int print_bigS(va_list l, flags_t *f);


/* print address */
int print_address(va_list l, flags_t *f);


/* print percent */
int print_percent(va_list l, flags_t *f);



#endif
