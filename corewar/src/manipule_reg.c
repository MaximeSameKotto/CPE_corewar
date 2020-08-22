/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** manipule_reg.c
*/

#include "corewar.h"

void put_in_register(int reg[REG_SIZE], int data[REG_SIZE])
{
    for (int i = 0; i < REG_SIZE; i++)
        reg[i] = data[i];
}

void put_out_register(int reg[REG_SIZE], vm_t *vm, int ad)
{
    for (int i = 0; i < REG_SIZE; i++)
        vm->memory[ad + i] = reg[i];
}