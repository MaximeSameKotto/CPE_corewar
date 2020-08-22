/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** lfork
*/

#include "corewar.h"

champions_t **dup_champ_lf(champions_t **champ, vm_t *vm, int adress, int ref)
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
    add_new_pc(&(new[i]->pc), adress);
    new[vm->nb_champ + 1] = 0;
    vm->nb_champ++;
    return new;
}

champions_t **my_lfork(vm_t *vm, champions_t **champ, pc_t *pc, int i)
{
    int *ad = malloc(sizeof(int) * DIR_SIZE);
    champions_t **new;

    my_memcpy_rev(ad, vm->memory + pc->adress + 1, IND_SIZE);
    new = dup_champ_lf(champ, vm, *ad, i);
    pc->adress += 3;
    return new;
}