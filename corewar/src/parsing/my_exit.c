/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** my_exit
*/

#include "corewar.h"

void my_exit(char *message, int status, int len)
{
    if (message == NULL)
        exit (status);
    write(2, message, len);
    exit(status);
}