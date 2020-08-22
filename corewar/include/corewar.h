/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** corewar.h
*/

#ifndef COREWAR_H
#define COREWAR_H

#include "op.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/file.h>
#include <stdbool.h>
#include <stdlib.h>
#include "lib.h"

#define HEADER_SIZE (sizeof(char) * (PROG_NAME_LENGTH + 16 + COMMENT_LENGTH))
#define BITS_PER_BYTES 8

typedef struct pc
{
    int adress;
    struct pc *next;
    int cycles;
    const op_t *instruction;
} pc_t;

typedef struct params
{
    int type;
    int size;
} params_t;

typedef struct champions
{
    header_t *header;
    int reg[REG_NUMBER][REG_SIZE];
    pc_t *pc;
    bool carry;
    bool live;
    bool in_game;
    char *code;
} champions_t;

typedef struct vm {
    int memory[MEM_SIZE];
    int nb_cycle;
    int to_die;
    int ref_to_die;
    int lives;
    int nb_champ;
    int dump;
} vm_t;

typedef struct argchamp
{
    int dump;
    int nb;
    int champnumber;
    int flag_n;
    int flag_a;
    char *file;
}argchamp_t;

champions_t **init_champions(char *argv[]);
vm_t *init_vm(char *argv[]);
int get_nb_champ(char *argv[]);
void place_champions(champions_t **champs, vm_t *vm);
void add_new_pc(pc_t **pc, int adress);
void get_instruction(vm_t *vm, pc_t *pc);
params_t **get_type_of_instruction(pc_t *pc, vm_t *vm);
void stand_or_exec(pc_t *pc, vm_t *vm, champions_t ***champions, int i);
void put_in_register(int reg[REG_SIZE], int data[REG_SIZE]);
void put_out_register(int reg[REG_SIZE], vm_t *vm, int ad);
argchamp_t **my_parsing(int ac, char **av);
int check_flag_n(char **av, int ac, int i);
int check_flag_a(char **av, int ac, int i);
int check_flag(argchamp_t **argchamp, int i, int ac, char **av);
int check_flag_help(int ac, char **av);
int check_champ(int ac, char **av);
int check_dump(char **av, argchamp_t **argchamp);
void my_exit(char *message, int status, int len);
void boucle_game(champions_t **champions, vm_t *vm);
int reverse_bytes(int nb);
void print_mem(vm_t *vm);

#endif