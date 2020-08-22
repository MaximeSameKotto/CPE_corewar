/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** manipulation of bytes
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "operator_abstract.h"
#include "instruction.h"

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
