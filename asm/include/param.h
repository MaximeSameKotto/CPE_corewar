/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** param header
*/

#ifndef PARAM_H
#define PARAM_H
#include <stdbool.h>
#include <stdio.h>
#include "op.h"
#include "instruction.h"

struct param {
    int type;
    char *param;
};

typedef struct param param_t;
typedef struct instruction instruction_t;
typedef struct parsing_infos parsing_infos_t;

bool parse_op_arguments(char *args, instruction_t ***instructions,
                        parsing_infos_t *parsing_infos);
bool fill_param_is_valid_register(char *arg, parsing_infos_t *parsing_infos,
                                    int i, instruction_t *instruc);
bool fill_param_if_direct_valid(char *arg, parsing_infos_t *parsing_infos,
                                    int i, instruction_t ***instrucs);

#endif /* ifndef PARAM_H */
