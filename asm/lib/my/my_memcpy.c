/*
** EPITECH PROJECT, 2019
** memcpy
** File description:
** memcpy
*/

#include <unistd.h>

void *my_memcpy(void *to_fill, void *to_cpy, size_t len)
{
    char *to_fill_ptr = to_fill;
    char *to_cpy_ptr = to_cpy;

    while (len--)
        *to_fill_ptr++ = *to_cpy_ptr++;
    return to_fill_ptr;
}
