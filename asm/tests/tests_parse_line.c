/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** unit test func
*/

#include  <criterion/criterion.h>
#include  <criterion/redirect.h>
#include  <fcntl.h>
#include  <unistd.h>
#include "../include/instruction.h"
#include "../include/param.h"
#include "../include/lib.h"

FILE *two_names = NULL;
FILE *no_comment = NULL;
FILE *same_label_name = NULL;
instruction_t ***instructions = NULL;
header_t *header = NULL;
parsing_infos_t *parsing_infos = NULL;

void open_file(void)
{
    instructions = init_instructions();
    header = init_header();
    parsing_infos = init_parsing_infos("test");
    two_names = fopen("./two_names", "r");
    no_comment = fopen("./no_comment.s", "r");
    same_label_name = fopen("./same_name_label.s", "r");
}

void close_file(void)
{
    if (two_names != NULL)
        fclose(two_names);
    if (no_comment != NULL)
        fclose(no_comment);
}

Test(asm, comment, .init = open_file, .fini = close_file)
{
    char *line = my_strdup("# comment mll\n");

    line_to_instruction(line, instructions, parsing_infos);
    cr_assert_not(parsing_infos->nb_instruction);
}

Test(asm, comment2, .init = open_file, .fini = close_file)
{
    char *line = my_strdup("  # comment   mll#\n");
    int i = 0;

    line_to_instruction(line, instructions, parsing_infos);
    for (int i = 0; instructions[i]; i++);
    cr_assert_not(i);
}

Test(asm, labelled_instruction, .init = open_file, .fini = close_file)
{
    char *line = my_strdup("label: live  %1 \n");

    line_to_instruction(line, instructions, parsing_infos);
    cr_assert_str_eq((*instructions)[0]->label, "label");
    cr_assert_str_eq((*instructions)[0]->op->mnemonique, "live");
}

Test(asm, labelled_instruction2, .init = open_file, .fini = close_file)
{
    char *line = my_strdup("label: live %1\n");

    line_to_instruction(line, instructions, parsing_infos);
    cr_assert_str_eq((*instructions)[0]->label, my_strdup("label"));
    cr_assert_str_eq((*instructions)[0]->op->mnemonique, my_strdup("live"));
    cr_assert_str_eq((*instructions)[0]->params[0]->param, my_strdup("1"));
    cr_assert_eq((*instructions)[0]->params[0]->type, T_DIR);
}

Test(asm, new_line_labelled_instruction, .init = open_file, .fini = close_file)
{
    char *line = my_strdup("label: ldi 3,%4,r1 \n");

    line = clean_line(line);
    line_to_instruction(line, instructions, parsing_infos);
    cr_assert_str_eq((*instructions)[0]->label, my_strdup("label"));
    cr_assert_str_eq((*instructions)[0]->op->mnemonique, my_strdup("ldi"));
    cr_assert_str_eq((*instructions)[0]->params[0]->param, my_strdup("3"));
    cr_assert_eq((*instructions)[0]->params[0]->type, T_IND);
    cr_assert_str_eq((*instructions)[0]->params[1]->param, my_strdup("4"));
    cr_assert_eq((*instructions)[0]->params[1]->type, T_DIR);
    cr_assert_str_eq((*instructions)[0]->params[2]->param, my_strdup("1"));
    cr_assert_eq((*instructions)[0]->params[2]->type, T_REG);
}

Test(asm, comment_endline, .init = open_file, .fini = close_file)
{
    char *line = my_strdup("label: ldi 3,%4,r1 # comment\n");

    line_to_instruction(line, instructions, parsing_infos);
    cr_assert_str_eq((*instructions)[0]->label, my_strdup("label"));
    cr_assert_str_eq((*instructions)[0]->op->mnemonique, my_strdup("ldi"));
    cr_assert_str_eq((*instructions)[0]->params[0]->param, my_strdup("3"));
    cr_assert_eq((*instructions[0])->params[0]->type, T_IND);
    cr_assert_str_eq((*instructions[0])->params[1]->param, my_strdup("4"));
    cr_assert_eq((*instructions)[0]->params[1]->type, T_DIR);
    cr_assert_str_eq((*instructions)[0]->params[2]->param, my_strdup("1"));
    cr_assert_eq((*instructions)[0]->params[2]->type, T_REG);
}

Test(asm, unlabelled_instruction, .init = open_file, .fini = close_file)
{
    char *line = my_strdup("live  %1\n");

    line_to_instruction(line, instructions, parsing_infos);
    cr_assert_str_eq((*instructions[0])->op->mnemonique, my_strdup("live"));
    cr_assert_str_eq((*instructions[0])->params[0]->param, my_strdup("1"));
    cr_assert_eq((*instructions[0])->params[0]->type, T_DIR);
}

Test(asm, wrong_label_chars, .init = open_file, .fini = close_file)
{
    char *line = my_strdup("la!bel: \n ldi 3,%4,r1 \n");
    int error = line_to_instruction(line, instructions, parsing_infos);

    cr_assert_eq(error, false);
}

Test(asm, misplaced_character, .init = open_file, .fini = close_file)
{
    char *line = my_strdup("label : \n %ldi 3,%4,r1 \n");
    int error = line_to_instruction(line, instructions, parsing_infos);

    cr_assert_eq(error, false);
}

Test(asm, misplaced_character2, .init = open_file, .fini = close_file)
{
    char *line = my_strdup("label : \n ldi 3,%4,r1, \n");
    int error = line_to_instruction(line, instructions, parsing_infos);

    cr_assert_eq(error, false);
}

Test(asm, misplaced_character3, .init = open_file, .fini = close_file)
{
    char *line = my_strdup("ldi 3!,%4,r1 \n");
    int error = line_to_instruction(line, instructions, parsing_infos);

    cr_assert_eq(error, false);
}

Test(asm, misplaced_character4, .init = open_file, .fini = close_file)
{
    char *line = my_strdup(":ldi 3,%4,r1 \n");
    int error = line_to_instruction(line, instructions, parsing_infos);

    cr_assert_eq(error, false);
}

Test(asm, missing_instruction, .init = open_file, .fini = close_file)
{
    char *line = my_strdup("label: 3,%4,r1\n");
    int error = line_to_instruction(line, instructions, parsing_infos);

    cr_assert_eq(error, false);
}

Test(asm, unknown_instruction, .init = open_file, .fini = close_file)
{
    char *line = my_strdup("forky r3,r4,r1\n");
    int error = line_to_instruction(line, instructions, parsing_infos);

    cr_assert_eq(error, false);
}

Test(asm, instruction_wrong_params, .init = open_file, .fini = close_file)
{
    char *line = my_strdup("label :  live  \n");
    int error = line_to_instruction(line, instructions, parsing_infos);

    cr_assert_eq(error, false);
}

Test(asm, instruction_wrong_params2, .init = open_file, .fini = close_file)
{
    char *line = my_strdup("label :  live  %1 %2\n");
    int error = line_to_instruction(line, instructions, parsing_infos);

    cr_assert_eq(error, false);
}

Test(asm, two_label_same_line, .init = open_file, .fini = close_file)
{
    char *line = my_strdup("label :labls: live  %1 %2\n");
    int error = line_to_instruction(line, instructions, parsing_infos);

    cr_assert_eq(error, false);
}

Test(asm, instruction_wrong_params3, .init = open_file, .fini = close_file)
{
    char *line = my_strdup("ld 32 , %2\n");
    int error = line_to_instruction(line, instructions, parsing_infos);

    cr_assert_eq(error, false);
}

Test(asm, bad_parameters, .init = open_file, .fini = close_file)
{
    char *line = my_strdup("add r3,%4,r1\n");
    int error = line_to_instruction(line, instructions, parsing_infos);

    cr_assert_eq(error, false);
}

Test(asm, bad_parameters2, .init = open_file, .fini = close_file)
{
    char *line = my_strdup("fork t5, r3,%4,r1\n");
    int error = line_to_instruction(line, instructions, parsing_infos);

    cr_assert_eq(error, 0);
}

Test(asm, , .init = open_file, .fini = close_file)
{
    char *line = NULL;
    size_t len = 0;
    int error = 0;

    while (getline(&line, &len, two_names) != -1)
        if ((error = get_header_data(header, parsing_infos,
            same_label_name) == false))
            break;
    cr_assert_eq(error, false);
}
