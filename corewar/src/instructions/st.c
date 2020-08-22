/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** st.c
*/

#include "corewar.h"

void st(vm_t *vm, champions_t **champ, pc_t *pc, int i)
{
    params_t **types = get_type_of_instruction(pc, vm);
    int reg = vm->memory[(pc->adress + 2)];
    int *ad = malloc(sizeof(int) * DIR_SIZE);

    if (types[1]->type == 2) {
        my_memcpy_rev(ad, vm->memory + pc->adress + 2, DIR_SIZE);
        my_memcpy(champ[i]->reg[reg - 1], ad, REG_SIZE);
        pc->adress += 3 + DIR_SIZE;
    } if (types[1]->type == 3) {
        my_memcpy_rev(ad, vm->memory + pc->adress + 3, IND_SIZE);
        my_memcpy(vm->memory + pc->adress +
        *ad % IDX_MOD, champ[i]->reg[reg - 1], REG_SIZE);
        pc->adress += 3 + IND_SIZE;
    } if (types[1]->type == 1) {
        *ad = vm->memory[(pc->adress + 3)];
        my_memcpy(champ[i]->reg[*ad - 1], champ[i]->reg[reg - 1], REG_SIZE);
        pc->adress += 4;
    }
}