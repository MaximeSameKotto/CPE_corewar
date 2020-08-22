/*
** EPITECH PROJECT, 2019
** memcpy
** File description:
** memcpy
*/

#include <unistd.h>

void *my_memcpy(int *to_fill, int *to_cpy, size_t len)
{
    int *to_fill_ptr = to_fill;
    int *to_cpy_ptr = to_cpy;

    while (len--)
        *to_fill_ptr++ = *to_cpy_ptr++;
    return to_fill_ptr;
}

void *my_memcpy_rev(int *to_fill, int *to_cpy, size_t len)
{
    int *to_fill_ptr = to_fill;
    int *to_cpy_ptr = to_cpy + (len - 1);

    while (len--)
        *to_fill_ptr++ = *to_cpy_ptr--;
    return to_fill_ptr;
}
