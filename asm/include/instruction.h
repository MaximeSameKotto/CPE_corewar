/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** instruction header
*/

#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <stdbool.h>
#include <stdio.h>
#include "op.h"
#include "param.h"

struct instruction {
    char *label;
    int address;
    int size;
    const op_t *op;
    param_t **params;
};

struct parsing_infos {
    char *compiled_file;
    bool name_found;
    bool comment_found;
    int nb_instruction;
    int actual_line;
    int empty_line;
};

#define BITS_PER_BYTES 8

typedef struct instruction instruction_t;
typedef struct parsing_infos parsing_infos_t;

instruction_t ***init_instructions(void);
header_t *init_header(void);
parsing_infos_t *init_parsing_infos(char *compiled_file);
char *clean_line(char *line);
bool field_missing(parsing_infos_t *parsing_infos);
bool is_special_op(const op_t *op);
bool is_valid_adressing(char *arg);
bool is_special_op_padding(const op_t *op);
char *format_line(char *line, FILE *to_compile);
int reverse_bytes(int nb);
void print_params(instruction_t **instructions, FILE *binary_file, int i);
void print_parameters_types(instruction_t *instruction, FILE *binary_file);
void get_prog_size(header_t *header, instruction_t **instructions);
void print_header(header_t *header, FILE *binary_file);
bool parse_instructions(FILE *to_compile,
                        instruction_t ***instructions,
                        parsing_infos_t *parsing_infos);
bool is_valid_adressing_label(instruction_t *instruction,
                            parsing_infos_t *parsing_infos,
                            instruction_t **instructions);
bool fill_label_field_if_valid(char *label,
                            instruction_t ***instructions,
                            parsing_infos_t *parsing_infos);
bool get_header_data(header_t *header,
                    parsing_infos_t *parsing_infos,
                    FILE *to_compile);
bool header_field_valid(char *field,
                        int max_length,
                        char *field_name,
                        parsing_infos_t *parsing_infos);
void init_instruction(instruction_t ***instructions,
                    parsing_infos_t *parsing_info);
bool line_to_instruction(char *line,
                        instruction_t ***instructions,
                        parsing_infos_t *parsing_infos);

#endif
