/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** header parsing file
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "operator_abstract.h"
#include "instruction.h"

static bool fill_name_if_valid(char *name, header_t *header,
                        parsing_infos_t *parsing_infos)
{
    if (parsing_infos->name_found) {
        my_printf("%s, line %i: The name can only be defined once.\n",
            parsing_infos->compiled_file, parsing_infos->actual_line);
        return false;
    }
    if (parsing_infos->actual_line - parsing_infos->empty_line isnt 1) {
        my_printf(
            "%s, line %i: The name of your program must be the first line.\n",
            parsing_infos->compiled_file, parsing_infos->actual_line);
        return false;
    }
    if (header_field_valid(name, PROG_NAME_LENGTH, "name", parsing_infos)) {
        my_memcpy(header->prog_name, name, my_strlen(name));
        parsing_infos->name_found = true;
        return true;
    } else {
        return false;
    }
}

static int fill_comment_if_valid(char *comment, header_t *header,
                            parsing_infos_t *parsing_infos)
{
    if (parsing_infos->comment_found) {
        my_printf("%s, line %i: The comment can only be defined once.\n",
            parsing_infos->compiled_file, parsing_infos->actual_line);
        return false;
    }
    if (parsing_infos->actual_line - parsing_infos->empty_line isnt 2) {
        my_printf("%s, line %i: The comment must be just after the name.\n",
            parsing_infos->compiled_file, parsing_infos->actual_line);
        return false;
    }
    if (header_field_valid(comment, COMMENT_LENGTH,
        "comment", parsing_infos)) {
        my_memcpy(header->comment, comment, my_strlen(comment));
        parsing_infos->comment_found = true;
        return true;
    } else {
        return false;
    }
}

bool fill_header_from_line(char *line, header_t *header,
                            parsing_infos_t *parsing_infos)
{
    char **parsed_line = sep_str(line, ' ');

    if (my_strcmp(parsed_line[0], NAME_CMD_STRING))
        return fill_name_if_valid(parsed_line[1], header, parsing_infos);
    else if (my_strcmp(parsed_line[0], COMMENT_CMD_STRING))
        return fill_comment_if_valid(parsed_line[1], header, parsing_infos);
    my_printf("%s, line %i: Invalid instruction.\n",
        parsing_infos->compiled_file, parsing_infos->actual_line);
    return false;
}

bool get_header_data(header_t *header, parsing_infos_t *parsing_infos,
                    FILE *to_compile)
{
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, to_compile) isnt -1) {
        line = clean_line(line);
        if (line and line[0] is '.' and
            not fill_header_from_line(line, header, parsing_infos))
            return false;
        else if (not line)
            parsing_infos->empty_line++;
        parsing_infos->actual_line++;
        if (parsing_infos->comment_found and parsing_infos->name_found)
            break;
    }
    if (field_missing(parsing_infos))
        return false;
    return true;
}
