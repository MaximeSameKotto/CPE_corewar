/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** live.c
*/

#include "corewar.h"

void live(vm_t *vm, champions_t **champ, pc_t *pc)
{
    int *nb = malloc(sizeof(int) * 4);

    vm->lives++;
    my_memcpy_rev(nb, (vm->memory + pc->adress + 1), 4);
    champ[*nb - 1]->live = true;
    if (pc->adress >= MEM_SIZE) {
        pc->adress -= MEM_SIZE;
        pc->adress += 5;
    } else
        pc->adress += 5;
    free(nb);
}