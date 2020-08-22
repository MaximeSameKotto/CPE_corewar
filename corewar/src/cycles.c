/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** cycles.c
*/

#include "instructions.h"
#include "corewar.h"

void exec_pc_second(pc_t **pc, vm_t *vm, champions_t ***champions, int i)
{
    if ((*pc)->instruction->code == 8) {
        xor(vm, *champions, *pc, i);
        (*champions)[i]->carry = !((*champions)[i]->carry);
    }
    if ((*pc)->instruction->code == 9)
        zjmp(vm, *champions, *pc, i);
    if ((*pc)->instruction->code == 10)
        ldi(vm, *champions, *pc, i);
    if ((*pc)->instruction->code == 11)
        sti(vm, *champions, *pc, i);
    if ((*pc)->instruction->code == 12)
        *champions = my_fork(vm, *champions, *pc, i);
    if ((*pc)->instruction->code == 13)
        lld(vm, *champions, *pc, i);
    if ((*pc)->instruction->code == 14)
        lldi(vm, *champions, *pc, i);
    if ((*pc)->instruction->code == 15)
        *champions = my_lfork(vm, *champions, *pc, i);
    if ((*pc)->instruction->code == 16)
        aff(vm, *champions, *pc, i);
}

void exec_pc(pc_t **pc, vm_t *vm, champions_t ***champions, int i)
{
    if ((*pc)->instruction->code == 1)
        live(vm, *champions, *pc);
    if ((*pc)->instruction->code == 2)
        ld(vm, *champions, *pc, i);
    if ((*pc)->instruction->code == 3)
        st(vm, *champions, *pc, i);
    if ((*pc)->instruction->code == 4)
        add(vm, *champions, *pc, i);
    if ((*pc)->instruction->code == 5)
        sub(vm, *champions, *pc, i);
    if ((*pc)->instruction->code == 6) {
        and(vm, *champions, *pc, i);
        (*champions)[i]->carry = !((*champions)[i]->carry);
    }
    if ((*pc)->instruction->code == 7) {
        or(vm, *champions, *pc, i);
        (*champions)[i]->carry = !((*champions)[i]->carry);
    }
    exec_pc_second(pc, vm, champions, i);
}

void stand_or_exec(pc_t *pc, vm_t *vm, champions_t ***champions, int i)
{
    for (; pc != 0; pc = pc->next) {
        if (pc->cycles == 0) {
            if (pc->instruction == 0)
                get_instruction(vm, pc);
            if (pc->instruction == 0) {
                pc->adress++;
                break;
            } else
                exec_pc(&pc, vm, champions, i);
            print_mem(vm);
            get_instruction(vm, pc);
        } else
            pc->cycles--;
        if (pc->adress >= MEM_SIZE)
            pc->adress -= MEM_SIZE;
    }
}