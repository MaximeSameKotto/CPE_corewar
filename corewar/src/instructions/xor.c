/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** and.c
*/

#include "corewar.h"

int *get_xor_operator(pc_t *pc, vm_t *vm, champions_t **champ, int i)
{
    int *and = malloc(sizeof(int) * DIR_SIZE);
    params_t **types = get_type_of_instruction(pc, vm);

    if (types[0]->type == 2) {
        my_memcpy_rev(and, vm->memory + pc->adress + 2, DIR_SIZE);
    } if (types[0]->type == 3) {
        my_memcpy_rev(and, vm->memory + pc->adress + 2, IND_SIZE);
        my_memcpy(and, vm->memory + pc->adress + *and % IDX_MOD, REG_SIZE);
    } if (types[0]->type == 1) {
        my_memcpy(and, champ[i]->reg[vm->memory[pc->adress + 2] - 1], REG_SIZE);
    }
    return and;
}

void xor(vm_t *vm, champions_t **champ, pc_t *pc, int i)
{
    params_t **types = get_type_of_instruction(pc, vm);
    int *and = get_xor_operator(pc, vm, champ, i);
    int *to_re = malloc(sizeof(int) * DIR_SIZE);
    int *tmp = malloc(sizeof(int) * DIR_SIZE);

    if (types[1]->type == 3) {
        my_memcpy_rev(to_re, vm->memory + pc->adress + 2 +
        types[0]->size, IND_SIZE);
        my_memcpy(to_re, vm->memory + pc->adress + *to_re % IDX_MOD, REG_SIZE);
        pc->adress += IND_SIZE + types[0]->size + 2;
    } if (types[1]->type == 2) {
        my_memcpy_rev(to_re, (vm->memory + pc->adress + 2 +
        types[0]->size), DIR_SIZE);
        pc->adress += DIR_SIZE + types[0]->size + 2;
    } if (types[1]->type == 1) {
        my_memcpy(to_re, champ[i]->reg[vm->memory[pc->adress +
        2 + types[0]->size] - 1], REG_SIZE);
        pc->adress += 1 + types[0]->size + 2;
    }
    *tmp = *and ^ *to_re;
    my_memcpy(champ[i]->reg[(int) vm->memory[pc->adress] - 1], tmp, REG_SIZE);
}