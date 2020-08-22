/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** parse label before linked to instructions
*/

#include <stdlib.h>
#include <stdbool.h>
#include "instruction.h"
#include "operator_abstract.h"
#include "lib.h"

bool is_label_char(char c, parsing_infos_t *parsing_infos)
{
    int i = 0;

    while (LABEL_CHARS[i]) {
        if (LABEL_CHARS[i++] is c)
            return true;
    }
    my_printf("%s, line %i: Invalid label name.\n",
        parsing_infos->compiled_file, parsing_infos->actual_line);
    return false;
}

bool label_name_already_taken(char *label, instruction_t **instructions,
                                parsing_infos_t *parsing_infos)
{
    for (int i = 0; instructions[i]; i++) {
        if (instructions[i]->label and
            my_strcmp(label, instructions[i]->label)) {
            my_printf("%s, line %i: Multiple definition of the same label.\n",
                parsing_infos->compiled_file, parsing_infos->actual_line);
            return true;
        }
    }
    return false;
}

bool fill_label_field_if_valid(char *label, instruction_t ***instructions,
                                parsing_infos_t *parsing_infos)
{
    label[my_strlen(label) - 1] = 0;
    for (int i = 0; label[i]; i++)
        if (not is_label_char(label[i], parsing_infos))
            return false;
    if (label_name_already_taken(label, *instructions, parsing_infos))
        return false;
    (*instructions)[parsing_infos->nb_instruction]->label = my_strdup(label);
    return true;
}
