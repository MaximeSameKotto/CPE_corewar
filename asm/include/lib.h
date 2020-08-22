/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** lib header
*/

#ifndef LIB_H_
#define LIB_H_
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

int my_strlen(char *str);
int find_char(char *str, char c);
char *my_strdup(char const *src);
char **my_str_to_word_array(char const *str, char delim);
int my_strcmp(char *s1, char *s2);
void *my_memcpy(void *to_fill, void *to_cpy, size_t len);
int my_printf(const char *str, ...);
int my_fprintf(FILE *stream, const char *str, ...);
void *my_memset(void *to_fill, int byte, size_t n);
char *my_strndup(char *str, int len);
char **sep_str(char *str, char separator);
char *concate(char *dest, char *src);
int my_getnbr(char const *str);
bool is_number(char *string);
void *my_calloc(int size);
int get_u_nb_size(unsigned int arg);
void my_fputchar(FILE *stream, char c);
char *my_strstr(char *str, char const *to_find);
long my_get_long(char const *str);

#endif /* ifndef LIB_H_ */
