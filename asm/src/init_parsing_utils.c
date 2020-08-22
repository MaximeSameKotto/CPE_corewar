/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** parsing utils init
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "instruction.h"

parsing_infos_t *init_parsing_infos(char *compiled_file)
{
    parsing_infos_t *parsing_infos = malloc(sizeof(parsing_infos_t));

    parsing_infos->actual_line = 1;
    parsing_infos->empty_line = 0;
    parsing_infos->compiled_file = compiled_file;
    parsing_infos->comment_found = false;
    parsing_infos->name_found = false;
    parsing_infos->nb_instruction = 0;
    return parsing_infos;
}

header_t *init_header(void)
{
    header_t *header = malloc(sizeof(header_t));

    header->magic = 0xea83f3;
    header->prog_size = 0;
    my_memset(header->prog_name, '\0', PROG_NAME_LENGTH);
    my_memset(header->comment, '\0', COMMENT_LENGTH);
    return header;
}

instruction_t ***init_instructions(void)
{
    instruction_t ***instructions = malloc(sizeof(instruction_t **));

    *instructions = malloc(sizeof(instruction_t *));
    (*instructions)[0] = NULL;
    return instructions;
}
