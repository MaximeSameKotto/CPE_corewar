/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** game.c
*/

#include "corewar.h"

bool champions_are_alive(champions_t **champions, vm_t *vm)
{
    int i = 0;

    if (vm->nb_cycle == 0)
        return 1;
    for (; champions[i] != 0; i++) {
        if (champions[i]->in_game == true)
            i++;
    }
    return i;
}

void is_die(champions_t **champions, vm_t *vm)
{
    for (int i = 0; champions[i] != 0; i++) {
        if (vm->to_die == 0 && champions[i]->live == false)
            champions[i]->in_game = false;
    }
    if (vm->to_die == 0)
        vm->to_die = vm->ref_to_die;
    if (vm->lives >= NBR_LIVE) {
        vm->lives = 0;
        vm->ref_to_die = vm->ref_to_die - CYCLE_DELTA;
    }
}

void print_mem(vm_t *vm)
{
    for (int i = 0; i != MEM_SIZE; i++) {
        my_printf("%x ", vm->memory[i]);
    }
    my_printf("\n\n\n");
}

void execute_cycle(champions_t ***champions, vm_t *vm)
{
    for (int i = 0; (*champions)[i] != 0; i++) {
        if ((*champions)[i]->in_game != false)
            stand_or_exec((*champions)[i]->pc, vm, champions, i);
    }
}

void boucle_game(champions_t **champions, vm_t *vm)
{
    int i = 0;
    while (champions_are_alive(champions, vm) != 0) {
        is_die(champions, vm);
        execute_cycle(&champions, vm);
        vm->to_die--;
        vm->nb_cycle++;
        i++;
    }
}