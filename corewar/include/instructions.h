/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instructions.h
*/

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "corewar.h"

void live(vm_t *vm, champions_t **champ, pc_t *pc);
void ld(vm_t *vm, champions_t **champ, pc_t *pc, int i);
void st(vm_t *vm, champions_t **champ, pc_t *pc, int i);
void add(vm_t *vm, champions_t **champ, pc_t *pc, int i);
void sub(vm_t *vm, champions_t **champ, pc_t *pc, int i);
void and(vm_t *vm, champions_t **champ, pc_t *pc, int i);
void or(vm_t *vm, champions_t **champ, pc_t *pc, int i);
void xor(vm_t *vm, champions_t **champ, pc_t *pc, int i);
void zjmp(vm_t *vm, champions_t **champ, pc_t *pc, int i);
void ldi(vm_t *vm, champions_t **champ, pc_t *pc, int i);
void sti(vm_t *vm, champions_t **champ, pc_t *pc, int i);
champions_t **my_fork(vm_t *vm, champions_t **champ, pc_t *pc, int i);
void lld(vm_t *vm, champions_t **champ, pc_t *pc, int i);
void lldi(vm_t *vm, champions_t **champ, pc_t *pc, int i);
champions_t **my_lfork(vm_t *vm, champions_t **champ, pc_t *pc, int i);
void aff(vm_t *vm, champions_t **champ, pc_t *pc, int i);

#endif