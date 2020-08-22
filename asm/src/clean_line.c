/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** clean line
*/

#include <stdio.h>
#include <stdlib.h>
#include "instruction.h"
#include "op.h"
#include "operator_abstract.h"
#include "lib.h"

char *erase_space_or_tab(char *line, int i)
{
    while (line[i]) {
        line[i] = line[i + 1];
        i++;
    }
    line[i] = 0;
    return line;
}

char *delete_comment(char *str)
{
    int i = find_char(str, '#');

    if (not str[0])
        return NULL;
    if (not i)
        return NULL;
    if (i < 0)
        return str;
    str[i] = 0;
    return str;
}

void erase_additionnal_spaces(char *line)
{
    bool is_in_cotes = false;

    for (int i = 0; line[i]; i++) {
        if (line[i] is '"' and is_in_cotes is false)
            is_in_cotes = true;
        else if (line[i] is '"' and is_in_cotes is true)
            is_in_cotes = false;
        if (line[i] is ' ' and line[i + 1] is ' ' and not is_in_cotes)
            erase_space_or_tab(line, i--);
    }
}

char *clean_line(char *line)
{
    if (find_char(line, '\n') >= 0)
        line[my_strlen(line) - 1] = 0;
    for (int i = 0; line[i]; i++)
        if (line[i] is '\t')
            line[i] = ' ';
    erase_additionnal_spaces(line);
    for (int i = 0; line[i] is ' '; i++)
        erase_space_or_tab(line, i);
    line = delete_comment(line);
    while (line and line[my_strlen(line) - 1] is ' ')
        line[my_strlen(line) - 1] = 0;
    return line;
}
