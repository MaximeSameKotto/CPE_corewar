/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** lld
*/

#include "corewar.h"

void lld(vm_t *vm, champions_t **champ, pc_t *pc, int i)
{
    params_t **types = get_type_of_instruction(pc, vm);
    int *reg = malloc(sizeof(int) * 4);
    int *ad = malloc(sizeof(int) * 4);
    int *res = malloc(sizeof(int) * 4);

    if (types[0]->type == 3) {
        my_memcpy_rev(reg, vm->memory + pc->adress + 2 + IND_SIZE, 1);
        my_memcpy_rev(ad, vm->memory + pc->adress + 2, IND_SIZE);
        my_memcpy(res, vm->memory + pc->adress + *ad, REG_SIZE);
        my_memcpy(champ[i]->reg[*reg - 1], res, REG_SIZE);
        pc->adress += 3 + IND_SIZE;
    } else if (types[0]->type == 2) {
        my_memcpy_rev(reg, vm->memory + pc->adress + 2 + DIR_SIZE, 1);
        my_memcpy_rev(ad, vm->memory + pc->adress + 2, DIR_SIZE);
        my_memcpy(champ[i]->reg[*reg - 1], ad, REG_SIZE);
        pc->adress += 3 + DIR_SIZE;
    }
    champ[i]->carry = !(champ[i]->carry);
}