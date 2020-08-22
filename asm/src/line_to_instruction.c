/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** line to instruction
*/

#include <stdlib.h>
#include <stdbool.h>
#include "instruction.h"
#include "operator_abstract.h"
#include "lib.h"

void init_instruction(instruction_t ***instructions,
                    parsing_infos_t *parsing_info)
{
    *instructions = realloc(*instructions, sizeof(instruction_t *)
        * (parsing_info->nb_instruction + 2));
    (*instructions)[parsing_info->nb_instruction + 1] = NULL;
    (*instructions)[parsing_info->nb_instruction] =
        malloc(sizeof(instruction_t));
    (*instructions)[parsing_info->nb_instruction]->label = NULL;
    (*instructions)[parsing_info->nb_instruction]->op = NULL;
    (*instructions)[parsing_info->nb_instruction]->params = NULL;
    (*instructions)[parsing_info->nb_instruction]->size = 1;
}

bool get_op(char *op_name, instruction_t ***instructions,
            parsing_infos_t *parsing_infos)
{
    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (my_strcmp(op_name, op_tab[i].mnemonique)) {
            (*instructions)[parsing_infos->nb_instruction]->op = &op_tab[i];
            return true;
        }
    }
    my_printf("%s, line %i: Invalid instruction.\n",
        parsing_infos->compiled_file, parsing_infos->actual_line);
    return false;
}

bool is_special_op(const op_t *op)
{
    return my_strcmp(op->mnemonique, "zjmp") or
        my_strcmp(op->mnemonique, "fork") or
        my_strcmp(op->mnemonique, "lfork") or
        my_strcmp(op->mnemonique, "live");
}

void get_instruction_size(instruction_t *actual_ins)
{
    if (not is_special_op(actual_ins->op))
        actual_ins->size += 1;
    for (int i = 0; i < actual_ins->op->nbr_args; i++) {
        if (actual_ins->params[i]->type is T_DIR and
            not is_special_op_padding(actual_ins->op))
            actual_ins->size += DIR_SIZE;
        else if (actual_ins->params[i]->type is T_DIR)
            actual_ins->size += 2;
        if (actual_ins->params[i]->type is T_IND)
            actual_ins->size += IND_SIZE;
        if (actual_ins->params[i]->type is T_REG)
            actual_ins->size += 1;
    }
}

bool line_to_instruction(char *line, instruction_t ***instructions,
                        parsing_infos_t *parsing_infos)
{
    char **parsed_instruction = sep_str(line, ' ');
    bool label_found = false;

    init_instruction(instructions, parsing_infos);
    if (find_char(parsed_instruction[0], LABEL_CHAR) >= 0) {
        label_found = true;
        if (not fill_label_field_if_valid(parsed_instruction[0],
            instructions, parsing_infos))
            return false;
    }
    if (label_found)
        parsed_instruction = sep_str(parsed_instruction[1], ' ');
    if (not get_op(parsed_instruction[0], instructions, parsing_infos))
        return false;
    if (not parse_op_arguments(parsed_instruction[1],
        instructions, parsing_infos))
        return false;
    get_instruction_size((*instructions)[parsing_infos->nb_instruction]);
    parsing_infos->nb_instruction++;
    return true;
}
