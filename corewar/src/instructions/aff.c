/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** aff
*/

#include "corewar.h"

void aff(vm_t *vm, champions_t **champ, pc_t *pc, int i)
{
    int aff = vm->memory[pc->adress + 1];

    my_printf("%c", (long) (champ[i]->reg[aff - 1]) % 256);
    pc->adress += 2;
}