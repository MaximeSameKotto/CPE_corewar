/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** parse params
*/

#include <stdlib.h>
#include <stdbool.h>
#include "instruction.h"
#include "param.h"
#include "operator_abstract.h"
#include "lib.h"

bool argument_number_issue(char **parsed_args, instruction_t *actual_ins,
                            parsing_infos_t *parsing_infos)
{
    int i = 0;

    for (; parsed_args[i]; i++);
    if (i > MAX_ARGS_NUMBER or i > actual_ins->op->nbr_args) {
        my_printf("%s, line %i: Too many arguments given to the instruction."
            "\n", parsing_infos->compiled_file, parsing_infos->actual_line);
        return true;
    }
    if (i < actual_ins->op->nbr_args) {
        my_printf("%s, line %i: The argument given to the instruction is inval"
            "id.\n", parsing_infos->compiled_file, parsing_infos->actual_line);
        return true;
    }
    return false;
}

bool get_argument(char *arg, instruction_t ***instructions,
                parsing_infos_t *parsing_infos, int i)
{
    instruction_t *actual_ins =
        (*instructions)[parsing_infos->nb_instruction];

    if (is_valid_adressing(arg)) {
        actual_ins->params[i] = malloc(sizeof(param_t));
        actual_ins->params[i]->param = my_strdup(arg);
        actual_ins->params[i]->type = T_IND;
        return true;
    }
    if (arg[0] is 'r')
        return fill_param_is_valid_register(arg, parsing_infos,
            i, actual_ins);
    if (arg[0] is DIRECT_CHAR)
        return fill_param_if_direct_valid(arg, parsing_infos,
            i, instructions);
    my_printf("%s, line %i: The argument given to the instruction is invalid"
        ".\n", parsing_infos->compiled_file, parsing_infos->actual_line);
    return false;
}

bool parse_params(char **parsed_args, instruction_t ***instructions,
                parsing_infos_t *parsing_infos)
{
    for (int i = 0; parsed_args[i]; i++) {
        parsed_args[i] = clean_line(parsed_args[i]);
        if (not get_argument(parsed_args[i], instructions, parsing_infos, i))
            return false;
    }
    return true;
}

bool params_match_op_args(instruction_t *instruc,
                            parsing_infos_t *parsing_infos)
{
    const op_t *op = instruc->op;

    for (int i = 0; i < op->nbr_args; i++) {
        if (not (op->type[i] & instruc->params[i]->type)) {
            my_printf("%s, line %i: The argument"
                " given to the instruction is invalid.\n",
                parsing_infos->compiled_file, parsing_infos->actual_line);
            return false;
        }
    }
    return true;
}

bool parse_op_arguments(char *args, instruction_t ***instructions,
                        parsing_infos_t *parsing_infos)
{
    char **parsed_args = my_str_to_word_array(args, SEPARATOR_CHAR);
    instruction_t *actual_ins =
        (*instructions)[parsing_infos->nb_instruction];

    if (argument_number_issue(parsed_args, actual_ins, parsing_infos))
        return false;
    actual_ins->params = malloc(sizeof(param_t *)
        * (actual_ins->op->nbr_args + 1));
    if (not parse_params(parsed_args, instructions, parsing_infos))
        return false;
    if (not params_match_op_args(actual_ins, parsing_infos))
        return false;
    return true;
}
