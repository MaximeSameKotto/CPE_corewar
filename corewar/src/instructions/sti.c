/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** sti.c
*/

#include "corewar.h"

void sti(vm_t *vm, champions_t **champ, pc_t *pc, int i)
{
    params_t **types = get_type_of_instruction(pc, vm);
    int reg = vm->memory[pc->adress + 2];
    int *ad = malloc(sizeof(int) * DIR_SIZE);
    int *res = malloc(sizeof(int) * DIR_SIZE);
    int *to_res = malloc(sizeof(int) * DIR_SIZE);

    my_memcpy_rev(ad, vm->memory + pc->adress + 3, 2);
    my_memcpy_rev(to_res, vm->memory + pc->adress + 5, 2);
    *res = *ad + *to_res;
    my_memcpy(vm->memory + pc->adress + *res %
    IDX_MOD, champ[i]->reg[reg - 1], REG_SIZE);
    pc->adress += 7;
}