/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** manage_champions.C
*/

#include "corewar.h"

int my_lentab(champions_t **tab)
{
    int i = 0;

    for (; tab[i] != 0; i++);
    return i;
}