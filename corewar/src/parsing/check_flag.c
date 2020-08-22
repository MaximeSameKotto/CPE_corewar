/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** check_flag
*/

#include "corewar.h"

int check_flag_help(int ac, char **av)
{
    if (ac == 2 && (my_strcmp("-h", av[1]) == 1)) {
        my_printf("USAGE\n    ./corewar [-dump nbr_cycle] [[-n prog_number] ");
        my_printf("[-a load_address] prog_name] ...\n\nDESCRIPTION\n");
        my_printf("    -dump nbr_cycle dumps the memory after the nbr_cycle ");
        my_printf("execution (if the round isn’t\n     already over) with the");
        my_printf(" following format: 32 bytes/line in hexadecimal ");
        my_printf("(A0BCDEFE1DD3...)\n");
        my_printf("    -n prog_number sets the next program’s number. By ");
        my_printf("default, the first free number\n     in the parameter ");
        my_printf("order\n    -a load_address sets the next program’s ");
        my_printf("loading address. When no address is\n     specified,");
        my_printf(" optimize the addresses so that the processes are as far\n");
        my_printf("     away from each other as possible. The addresses are");
        my_printf(" MEM_SIZE modulo.\n");
        my_exit("", 0, 0);
    }
    return 0;
}

int check_flag_a(char **av, int ac, int i)
{
    if (i == ac - 1)
        my_exit("You must put a number after -a\n", 84, 31);
    for (int a = 0; av[i+1][a] != 0; a++) {
        if (!(av[i+1][a] >= '0' && av[i+1][a] <= '9'))
            my_exit("You must put a valid number after -a\n", 84, 37);
    }
    if (my_getnbr(av[i+1]) >= MEM_SIZE || my_getnbr(av[i+1]) < 0)
        my_exit("Program is out of the memory\n", 84, 29);
    return 0;
}

int check_flag_n(char **av, int ac, int i)
{
    if (i == ac - 1)
        my_exit("You must put a number after -n\n", 84, 31);
    for (int a = 0; av[i+1][a] != 0; a++) {
        if (!(av[i+1][a] >= '0' && av[i+1][a] <= '9'))
            my_exit("You must put a valid number after -n\n", 84, 37);
    }
    if (my_getnbr(av[i+1]) <= 0)
        my_exit("You must put a valid number after -n\n", 84, 37);
    return 0;
}

int check_dump(char **av, argchamp_t **argchamp)
{
    if (my_strcmp("-dump", av[1]) == 1) {
        for (int i = 0; av[2][i] != 0; i++) {
            if (!(av[2][i] >= '0' && av[2][i] <= '9'))
                my_exit("Invalid nbr_cycle for dump\n", 84, 27);
        }
        if (my_getnbr(av[2]) < 0 || my_getnbr(av[2]) > 2000000)
            my_exit("Invalid nbr_cycle for dump\n", 84, 27);
        argchamp[0]->dump = my_getnbr(av[2]);
        return 3;
    }
    return 1;
}
