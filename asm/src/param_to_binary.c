/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** param to binary
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "operator_abstract.h"
#include "instruction.h"

void print_parameters_types(instruction_t *instruction, FILE *binary_file)
{
    int reg_type = 1;
    int direct_type = 2;
    int ind_type = 3;
    char coded_byte = 0;

    for (int i = 0; i < instruction->op->nbr_args; i++) {
        coded_byte <<= 2;
        if (instruction->params[i]->type is T_REG)
            coded_byte |= reg_type;
        if (instruction->params[i]->type is T_DIR)
            coded_byte |= direct_type;
        if (instruction->params[i]->type is T_IND)
            coded_byte |= ind_type;
    }
    for (int i = instruction->op->nbr_args; i < 4; i++)
        coded_byte <<= 2;
    fwrite(&coded_byte, sizeof(char), 1, binary_file);
}

int get_label_address(char *label, instruction_t **instructions, int i)
{
    int address = 0;

    for (int j = 0; instructions[j]; j++) {
        if (my_strcmp(instructions[j]->label, label))
            break;
        address += instructions[j]->size;
    }
    return address - instructions[i]->address;
}

bool is_special_op_padding(const op_t *op)
{
    return my_strcmp(op->mnemonique, "zjmp")
        or my_strcmp(op->mnemonique, "fork")
        or my_strcmp(op->mnemonique, "sti")
        or my_strcmp(op->mnemonique, "lfork")
        or my_strcmp(op->mnemonique, "lldi")
        or my_strcmp(op->mnemonique, "ldi");
}

int get_param_size(param_t *param, const op_t *op)
{
    if (param->type is T_REG)
        return 1;
    if (param->type is T_DIR and not is_special_op_padding(op))
        return DIR_SIZE;
    else if (param->type is T_DIR)
        return 2;
    if (param->type is T_IND)
        return IND_SIZE;
    return 1;
}

void print_params(instruction_t **instructions, FILE *binary_file, int i)
{
    instruction_t *instruction = instructions[i];
    int param_value = 0;
    param_t *param = NULL;

    for (int j = 0; j < instruction->op->nbr_args; j++) {
        param = instruction->params[j];
        if (param->param[0] is LABEL_CHAR)
            param_value = get_label_address(param->param + 1, instructions, i);
        else
            param_value = my_get_long(instruction->params[j]->param);
        param_value = reverse_bytes(param_value);
        param_value >>= sizeof(int) * BITS_PER_BYTES
            - get_param_size(param, instruction->op) * BITS_PER_BYTES;
        fwrite(&param_value, get_param_size(
            param, instruction->op), 1, binary_file);
    }
}
