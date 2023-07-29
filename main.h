#ifndef MAIN_H
#define MAIN_H



#include <stdio.h>

#include <unistd.h>



#define UNUSED(x) (void)(x)

#define BUFF_SIZE 1024



/* FLAGS */

#define F_MINUS 1

#define F_PLUS 2

#define F_ZERO 4

#define F_HASH 8

#define F_SPACE 16



/* SIZES */

#define S_LONG 2

#define S_SHORT 1



/**
 * struct fmt - Struct op
 *
 * @fmts: The format.

 * @fnc: The function associated.

 */

struct fmt
{

char fmts;
int (*fnc)(va_list, char[], int, int, int, int);
};





/**
 * typedef struct fmt fmt_t - Struct op
 *

 * @fmts: The format.

 * @fm_t: The function associated.

 */

typedef struct fmt fmt_t;



int _printf(const char *format, ...);

int handle_print(const char *fmts, int *ind,

		 va_list list, char buffer[], int flags, int width, int precision, int size);



/****************** FUNCTIONS ******************/



/* printing characters and strings */

int print_character(va_list list, char array[],

	       int flags, int width, int precision, int size);

int print_strg(va_list type, char buffers[],

		 int flag, int width, int value, int sizes);

int percent_sign(va_list type, char array[],

		  int flag, int width, int value, int sizes);



/* printing numbers */

int print_integer(va_list list, char array[],

	      int flags, int width, int digit, int sizes);

int print_binr(va_list types, char array[],

		 int flag, int width, int value, int number);

int no_sign(va_list list, char array[],

		   int flags, int width, int value, int size);

int print_eight(va_list type, char array[],

		int flag, int width, int value, int sizes);

int print_six(va_list list, char buffer[],

		      int flags, int width, int digit, int sizes);

int print_hexa_caps(va_list list, char buffer[], int flags, int width, int precision, int size);



int print_hex(va_list list, char rep[],
	       char array[], int flag, char flag_character, int width,
	      int value, int sizes);



/* Function to print non printable characters */

int print_non_printable(va_list types, char buffer[],

			int flags, int width, int precision, int size);



/* Funcion to print memory address */

int print_pointer(va_list types, char buffer[],

		  int flags, int width, int precision, int size);



/* handling other specifiers */

int print_flags(const char *string, int *i);

int get_width(const char *format, int *i, va_list list);

int get_value(const char *frmt, int *i, va_list list);

int get_size(const char *format, int *i);



/*Function to print string in reverse*/

int print_reverse(va_list list, char buffer[], int flags, int width, int precision, int size);


/*Function to print a string in rot 13*/

int rot13_string(va_list list, char array[],

		      int flag, int width, int digit, int size);



/* width handler */

int handle_write_char(char c, char buffer[],

		      int flags, int width, int precision, int size);

int write_number(int is_positive, int indx, char buffer[],

		 int flags, int width, int precision, int size);

int write_num(int indx, char bff[], int flags, int width, int precision,

	      int length, char pdn, char extra_ch);

int write_pointer(char buffer[], int indx, int length,

		  int width, int flags, char pdn, char extra_ch, int padd_start);



int write_unsgnd(int is_negative, int indx,

		 char buffer[],

		 int flags, int width, int prec, int size);



/****************** UTILS ******************/

int is_printable(char);

int append_hexa_code(char, char[], int);

int is_digit(char);



long int convert_size_number(long int num, int size);

long int convert_size_unsgnd(unsigned long int num, int size);




#endif
