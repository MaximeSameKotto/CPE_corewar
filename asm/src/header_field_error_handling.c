/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** header field error handling
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "operator_abstract.h"
#include "instruction.h"

bool field_missing(parsing_infos_t *parsing_infos)
{
    if (parsing_infos->actual_line - parsing_infos->empty_line is 1) {
        my_printf("%s, The file is empty.\n", parsing_infos->compiled_file);
        return true;
    }
    if (not parsing_infos->name_found) {
        my_printf("%s, line %i: No name specified.\n",
            parsing_infos->compiled_file, parsing_infos->actual_line);
        return true;
    }
    return false;
}

bool header_field_valid(char *field, int max_length, char *field_name,
                        parsing_infos_t *parsing_infos)
{
    if (field[0] isnt '"' or field[my_strlen(field) - 1] isnt '"') {
        my_printf("%s, line %i: Syntax Error.\n",
            parsing_infos->compiled_file, parsing_infos->actual_line);
        return false;
    }
    if (my_strlen(field) > max_length) {
        my_printf("%s, line %i: The program %s is too long.\n",
            parsing_infos->compiled_file, parsing_infos->actual_line,
            field_name);
        return false;
    }
    field[my_strlen(field) - 1] = 0;
    for (int i = 0; field[i]; i++)
        field[i] = field[i + 1];
    return true;
}
