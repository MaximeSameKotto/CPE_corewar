/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** manipulation of bytes
*/

#include <stdlib.h>
#include <stdio.h>
#include "operator_abstract.h"
#include "corewar.h"

int reverse_bytes(int nb)
{
    int reversed_bytes = 0;
    int index = 0;
    int next_byte = 0;

    for (; index < 4; ++index) {
        next_byte = (nb >> BITS_PER_BYTES * index) & 0xff;
        reversed_bytes = reversed_bytes | next_byte
            << (BITS_PER_BYTES * 3 - BITS_PER_BYTES * index);
    }
    return reversed_bytes;
}

params_t **get_type_of_instruction(pc_t *pc, vm_t *vm)
{
    params_t **params = malloc(sizeof(params_t *) * 3);
    char to_decode = vm->memory[(pc->adress + 1) % MEM_SIZE];

    for (int i = 0; i < 3; i++)
        params[i] = malloc(sizeof(params_t));
    params[0]->type = 0b00000011 & to_decode >> 6;
    params[0]->size = (params[0]->type == 1) ? 1 : params[0]->size;
    params[0]->size = (params[0]->type == 2) ? DIR_SIZE : params[0]->size;
    params[0]->size = (params[0]->type == 3) ? IND_SIZE : params[0]->size;
    params[1]->type = 0b00000011 & to_decode >> 4;
    params[1]->size = (params[1]->type == 1) ? 1 : params[1]->size;
    params[1]->size = (params[1]->type == 2) ? DIR_SIZE : params[1]->size;
    params[1]->size = (params[1]->type == 3) ? IND_SIZE : params[1]->size;
    params[2]->type = 0b00000011 & to_decode >> 2;
    params[2]->size = (params[2]->type == 1) ? 1 : params[2]->size;
    params[2]->size = (params[2]->type == 2) ? DIR_SIZE : params[2]->size;
    params[2]->size = (params[2]->type == 3) ? IND_SIZE : params[2]->size;
    return params;
}
