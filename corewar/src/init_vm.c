/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** init_vm.c
*/

#include "corewar.h"

void place_champions(champions_t **champs, vm_t *vm)
{
    int split_curs = (MEM_SIZE) / vm->nb_champ;
    int tmp = split_curs;

    for (int i = 0; i < vm->nb_champ; i++) {
        champs[i]->pc = NULL;
        if (i == 0) {
            add_new_pc(&(champs[i]->pc), 0);
            for (int y = 0; y < champs[i]->header->prog_size; y++)
                vm->memory[y] = champs[i]->code[y];
        } else {
            add_new_pc(&(champs[i]->pc), tmp);
            for (int y = 0; y < champs[i]->header->prog_size; y++, tmp++)
                vm->memory[tmp] = champs[i]->code[y];
            tmp = split_curs;
            tmp += split_curs;
        }
    }
}

vm_t *init_vm(char *argv[])
{
    vm_t *vm = malloc(sizeof(vm_t));

    my_memset(vm->memory, 0, MEM_SIZE);
    vm->lives = 0;
    vm->nb_cycle = 0;
    vm->to_die = CYCLE_TO_DIE;
    vm->ref_to_die = CYCLE_TO_DIE;
    vm->nb_champ = get_nb_champ(argv);
    return vm;
}