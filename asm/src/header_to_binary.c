/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** header to binary
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "operator_abstract.h"
#include "instruction.h"

void get_prog_size(header_t *header, instruction_t **instructions)
{
    for (int i = 0; instructions[i]; i++)
        header->prog_size += instructions[i]->size;
}

void print_header(header_t *header, FILE *binary_file)
{
    int magic_nb = reverse_bytes(header->magic);
    int null_byte = 0;

    fwrite(&magic_nb, sizeof(int), 1, binary_file);
    fwrite(&header->prog_name, sizeof(char), PROG_NAME_LENGTH, binary_file);
    for (int i = 0; i < 4; i++)
        fwrite(&null_byte, sizeof(char), 1, binary_file);
    header->prog_size = reverse_bytes(header->prog_size);
    fwrite(&header->prog_size, sizeof(int), 1, binary_file);
    fwrite(&header->comment, sizeof(char), COMMENT_LENGTH, binary_file);
    for (int i = 0; i < 4; i++)
        fwrite(&null_byte, sizeof(char), 1, binary_file);
}
