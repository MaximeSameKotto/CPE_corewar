/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** lldi
*/

#include "corewar.h"

void lldi(vm_t *vm, champions_t **champ, pc_t *pc, int i)
{
    params_t **types = get_type_of_instruction(pc, vm);
    int *ad = malloc(sizeof(int) * DIR_SIZE);
    int *res = malloc(sizeof(int) * DIR_SIZE);
    int *to_res = malloc(sizeof(int) * DIR_SIZE);

    if (types[0]->type == 2)
        my_memcpy_rev(ad, vm->memory + pc->adress + 2, IND_SIZE);
    if (types[0]->type == 3) {
        my_memcpy_rev(ad, vm->memory + pc->adress + 2, IND_SIZE);
        my_memcpy(ad, vm->memory + pc->adress + *ad, IND_SIZE);
    } if (types[1]->type == 3) {
        my_memcpy_rev(to_res, vm->memory +
        pc->adress + 2 + types[0]->size, IND_SIZE);
        my_memcpy(to_res, vm->memory + pc->adress + *ad, IND_SIZE);
    } if (types[1]->type == 2)
        my_memcpy_rev(to_res, vm->memory + pc->adress + 2 + types[0]->size, 2);
    *res = *ad + *to_res;
    my_memcpy(champ[i]->reg[vm->memory[pc->adress + 2 + types[0]->size
    + types[1]->size]], vm->memory + pc->adress + *res, REG_SIZE);
    pc->adress += 7;
}