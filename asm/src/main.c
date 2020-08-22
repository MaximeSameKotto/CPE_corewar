/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** main file
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "operator_abstract.h"
#include "instruction.h"

void print_instructions(instruction_t **instructions, FILE *binary_file)
{
    int next_instruction_address = 0;

    for (int i = 0; instructions[i]; i++) {
        if (not instructions[i]->op)
            continue;
        instructions[i]->address = next_instruction_address;
        fwrite(&instructions[i]->op->code, 1, 1, binary_file);
        if (not is_special_op(instructions[i]->op))
            print_parameters_types(instructions[i], binary_file);
        print_params(instructions, binary_file, i);
        next_instruction_address += instructions[i]->size;
    }
}

void print_binary_to_file(instruction_t **instructions, header_t *header,
                            char *file_name)
{
    FILE *binary_file = fopen(concate(file_name, ".cor"), "w+");

    get_prog_size(header, instructions);
    print_header(header, binary_file);
    print_instructions(instructions, binary_file);
    fclose(binary_file);
}

int compile(FILE *to_compile, char *file_name)
{
    instruction_t ***instructions = init_instructions();
    header_t *header = init_header();
    parsing_infos_t *parsing_infos = init_parsing_infos(file_name);

    if (not get_header_data(header, parsing_infos, to_compile))
        return 84;
    fclose(to_compile);
    to_compile = fopen(file_name, "r");
    if (not parse_instructions(to_compile, instructions, parsing_infos))
        return 84;
    for (int i = 0; (*instructions)[i]; i++)
        if (not is_valid_adressing_label((*instructions)[i],
            parsing_infos, *instructions))
            return 84;
    fclose(to_compile);
    if (my_strstr(file_name, ".s"))
        file_name[my_strlen(file_name) - 2] = 0;
    print_binary_to_file(*instructions, header, file_name);
    return 0;
}

int main(int argc, char *argv[])
{
    FILE *to_compile = NULL;

    if (argc isnt 2)
        return 84;
    if (not (to_compile = fopen(argv[1], "r"))) {
        my_printf("Error in function open: No such file or directory.\n");
        return 84;
    }
    return compile(to_compile, argv[1]);
}
