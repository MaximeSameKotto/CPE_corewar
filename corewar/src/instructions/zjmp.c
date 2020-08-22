/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** zjmp.c
*/

#include "corewar.h"

void zjmp(vm_t *vm, champions_t **champ, pc_t *pc, int i)
{
    int *ad = malloc(sizeof(int) * DIR_SIZE);

    if (champ[i]->carry) {
        my_memcpy_rev(ad, vm->memory + pc->adress + 1, IND_SIZE);
        pc->adress += *ad;
    } else
        pc->adress += 5;
    champ[i]->carry = !(champ[i]->carry);
}