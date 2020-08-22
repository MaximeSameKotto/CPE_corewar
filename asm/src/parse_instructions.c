/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** parse_instructions
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "op.h"
#include "operator_abstract.h"
#include "instruction.h"
#include "param.h"
#include "string.h"

void init_empty_instruction(instruction_t ***instructions,
                            parsing_infos_t *parsing_info,
                            char *line)
{
    line[my_strlen(line) - 1] = 0;
    *instructions = realloc(*instructions, sizeof(instruction_t *)
        * (parsing_info->nb_instruction + 2));
    (*instructions)[parsing_info->nb_instruction + 1] = NULL;
    (*instructions)[parsing_info->nb_instruction] =
        malloc(sizeof(instruction_t));
    (*instructions)[parsing_info->nb_instruction]->label = my_strdup(line);
    (*instructions)[parsing_info->nb_instruction]->op = NULL;
    (*instructions)[parsing_info->nb_instruction]->params = NULL;
    (*instructions)[parsing_info->nb_instruction]->size = 0;
    parsing_info->nb_instruction++;
}

bool parse_instructions(FILE *to_compile, instruction_t ***instructions,
                        parsing_infos_t *parsing_infos)
{
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, to_compile) isnt -1) {
        line = format_line(line, to_compile);
        if (line and line[my_strlen(line) - 1] is LABEL_CHAR)
            init_empty_instruction(instructions, parsing_infos, line);
        else if (line and
            not line_to_instruction(line, instructions, parsing_infos))
            return false;
        if (not line)
            parsing_infos->empty_line++;
        parsing_infos->actual_line++;
    }
    return true;
}
