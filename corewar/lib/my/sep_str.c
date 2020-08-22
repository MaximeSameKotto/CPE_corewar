/*
** EPITECH PROJECT, 2019
** sep_str
** File description:
** lib func
*/

#include <stdlib.h>
#include "my.h"

char **sep_str(char *str, char separator)
{
    char **sep_strings = malloc(sizeof(char *) * 3);
    int i = 0;

    sep_strings[2] = NULL;
    for (; str[i] && str[i] != separator; i++);
    sep_strings[0] = my_strndup(str, i++);
    sep_strings[1] = my_strndup(str + i, my_strlen(str + i));
    return sep_strings;
}
