/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** fork.c
*/

#include "corewar.h"

champions_t **dup_champ(champions_t **champ, vm_t *vm, int adress, int ref)
{
    champions_t **new = malloc(sizeof(champions_t *) * (vm->nb_champ + 1));
    int i = 0;

    for (; i < vm->nb_champ; i++) {
        new[i] = malloc(sizeof(champions_t));
        new[i] = champ[i];
    }
    new[i] = malloc(sizeof(champions_t));
    new[i]->header = champ[ref]->header;
    new[i]->in_game = true;
    new[i]->live = false;
    new[i]->carry = false;
    add_new_pc(&(new[i]->pc), adress % IDX_MOD);
    new[vm->nb_champ + 1] = 0;
    vm->nb_champ++;
    return new;
}

champions_t **my_fork(vm_t *vm, champions_t **champ, pc_t *pc, int i)
{
    int *ad = malloc(sizeof(int) * DIR_SIZE);
    champions_t **new;

    my_memcpy_rev(ad, vm->memory + pc->adress + 1, IND_SIZE);
    new = dup_champ(champ, vm, *ad, i);
    pc->adress += 3;
    return new;
}