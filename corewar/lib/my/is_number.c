/*
** EPITECH PROJECT, 2019
** is number
** File description:
** is number
*/

#include <stdbool.h>

bool is_number(char *string)
{
    int i = 0;

    if (string[0] == '-')
        string += 1;
    for (; string[i]; i++)
        if (string[i] > '9' || string[i] < '0')
            return false;
    if (!i)
        return false;
    return true;
}
