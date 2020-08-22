/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** add.c
*/

#include "corewar.h"

void add(vm_t *vm, champions_t **champ, pc_t *pc, int i)
{
    int *reg = malloc(sizeof(int) * REG_SIZE);
    int *reg_to_add = malloc(sizeof(int) * REG_SIZE);
    int *res = malloc(sizeof(int) * REG_SIZE);
    int *tmp = malloc(sizeof(int) * REG_SIZE);

    my_memcpy_rev(reg, vm->memory + pc->adress + 2, 1);
    my_memcpy_rev(reg_to_add, vm->memory + pc->adress + 3, 1);
    my_memcpy_rev(res, vm->memory + pc->adress + 4, 1);
    *tmp = *(champ[i]->reg[*reg - 1]) + *(champ[i]->reg[*reg_to_add - 1]);
    my_memcpy(champ[i]->reg[*res - 1], tmp, REG_SIZE);
    pc->adress += 5;
    champ[i]->carry = !(champ[i]->carry);
}