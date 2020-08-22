/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** pc_management.c
*/

#include "corewar.h"

void add_new_pc(pc_t **pc, int adress)
{
    pc_t *element = malloc(sizeof(pc_t));

    element->adress = adress;
    element->cycles = 0;
    element->next = *pc;
    element->instruction = 0;
    *pc = element;
}

void get_instruction_third(vm_t *vm, pc_t *pc)
{
    if (vm->memory[pc->adress] == 13) {
        pc->cycles = 10;
        pc->instruction = &op_tab[12];
    } if (vm->memory[pc->adress] == 14) {
        pc->cycles = 50;
        pc->instruction = &op_tab[13];
    } if (vm->memory[pc->adress] == 15) {
        pc->cycles = 1000;
        pc->instruction = &op_tab[14];
    } if (vm->memory[pc->adress] == 16) {
        pc->cycles = 2;
        pc->instruction = &op_tab[15];
    }
}

void get_instruction_second(vm_t *vm, pc_t *pc)
{
    if (vm->memory[pc->adress] == 7) {
        pc->cycles = 6;
        pc->instruction = &op_tab[6];
    } if (vm->memory[pc->adress] == 8) {
        pc->cycles = 6;
        pc->instruction = &op_tab[7];
    } if (vm->memory[pc->adress] == 9) {
        pc->cycles = 20;
        pc->instruction = &op_tab[8];
    } if (vm->memory[pc->adress] == 10) {
        pc->cycles = 25;
        pc->instruction = &op_tab[9];
    } if (vm->memory[pc->adress] == 11) {
        pc->cycles = 25;
        pc->instruction = &op_tab[10];
    } if (vm->memory[pc->adress] == 12) {
        pc->cycles = 800;
        pc->instruction = &op_tab[11];
    }
    get_instruction_third(vm, pc);
}

void get_instruction(vm_t *vm, pc_t *pc)
{
    if (vm->memory[pc->adress] == 1) {
        pc->cycles = 10;
        pc->instruction = &op_tab[0];
    } if (vm->memory[pc->adress] == 2) {
        pc->cycles = 5;
        pc->instruction = &op_tab[1];
    } if (vm->memory[pc->adress] == 3) {
        pc->cycles = 5;
        pc->instruction = &op_tab[2];
    } if (vm->memory[pc->adress] == 4) {
        pc->cycles = 10;
        pc->instruction = &op_tab[3];
    } if (vm->memory[pc->adress] == 5) {
        pc->cycles = 10;
        pc->instruction = &op_tab[4];
    } if (vm->memory[pc->adress] == 6) {
        pc->cycles = 6;
        pc->instruction = &op_tab[5];
    }
    get_instruction_second(vm, pc);
}