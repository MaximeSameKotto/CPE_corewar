/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** is valid adressing method
*/

#include <stdlib.h>
#include <stdbool.h>
#include "instruction.h"
#include "operator_abstract.h"
#include "lib.h"

bool label_exist(char *label, instruction_t **instructions,
                                parsing_infos_t *parsing_infos)
{
    for (int i = 0; instructions[i]; i++) {
        if (instructions[i]->label and
            my_strcmp(label + 1, instructions[i]->label))
            return true;
    }
    my_printf("%s, line %i: Undefined label.\n",
        parsing_infos->compiled_file, parsing_infos->actual_line);
    return false;
}

bool is_valid_adressing_label(instruction_t *instruction,
                            parsing_infos_t *parsing_infos,
                            instruction_t **instructions)
{
    if (not instruction->op)
        return true;
    for (int i = 0; i < instruction->op->nbr_args; i++) {
        if (instruction->params[i]->param[0] is LABEL_CHAR
            and not label_exist(
            instruction->params[i]->param, instructions, parsing_infos))
            return false;
    }
    return true;
}

bool is_valid_adressing(char *arg)
{
    if (is_number(arg))
        return true;
    if (find_char(arg, LABEL_CHAR) is 0)
        return true;
    return false;
}

bool fill_param_is_valid_register(char *arg, parsing_infos_t *parsing_infos,
                                    int i, instruction_t *instruc)
{
    if (my_getnbr(arg + 1) > 0 and my_getnbr(arg + 1) < REG_NUMBER) {
        instruc->params[i] = malloc(sizeof(param_t));
        instruc->params[i]->param = my_strdup(arg + 1);
        instruc->params[i]->type = T_REG;
        return true;
    }
    my_printf("%s, line %i: Invalid register number.\n",
        parsing_infos->compiled_file, parsing_infos->actual_line);
    return false;
}

bool fill_param_if_direct_valid(char *arg, parsing_infos_t *parsing_infos,
                                    int i, instruction_t ***instrucs)
{
    int index = parsing_infos->nb_instruction;

    if (is_valid_adressing(arg + 1)) {
        (*instrucs)[index]->params[i] = malloc(sizeof(param_t));
        (*instrucs)[index]->params[i]->param = my_strdup(arg + 1);
        (*instrucs)[index]->params[i]->type = T_DIR;
        return true;
    }
    my_printf("%s, line %i: The argument given to the instruction is invalid"
        ".\n", parsing_infos->compiled_file, parsing_infos->actual_line);
    return false;
}
