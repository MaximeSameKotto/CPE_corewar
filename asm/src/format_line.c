/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** format instruction line
*/

#include <stdio.h>
#include <stdlib.h>
#include "instruction.h"
#include "op.h"
#include "operator_abstract.h"
#include "lib.h"

char *get_instruction_line(FILE *to_compile, int *end_of_file, char *line)
{
    char *next_line = NULL;
    size_t len = 0;

    do {
        *end_of_file = getline(&next_line, &len, to_compile);
        if (*end_of_file is -1)
            return line;
        if ((next_line[my_strlen(next_line) - 1 is LABEL_CHAR]
            or sep_str(next_line, ' ')[0][my_strlen(next_line) - 1]
            is LABEL_CHAR)) {
            fseek(to_compile, -my_strlen(next_line), SEEK_CUR);
            return line;
        }
    } while (not clean_line(next_line) and *end_of_file != -1);
    return line;
}

char *format_line(char *line, FILE *to_compile)
{
    int end_of_file = 0;

    line = clean_line(line);
    if (not line or my_strcmp(sep_str(line, ' ')[0], ".name")
        or my_strcmp(sep_str(line, ' ')[0], ".comment"))
        return NULL;
    if (line[my_strlen(line) - 1] is LABEL_CHAR)
        line = get_instruction_line(to_compile, &end_of_file, line);
    if (end_of_file is -1 and not line)
        return NULL;
    return line;
}
