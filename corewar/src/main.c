/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** main.c
*/

#include "corewar.h"

void check_parsing(argchamp_t **argchamp)
{
    my_printf("nb de champion = %d\n", argchamp[0]->nb);
    my_printf("nb de dump = %d\n", argchamp[0]->dump);
    for (int i = 1; i <= argchamp[0]->nb; i++) {
        my_printf("parsing -n number of champion = %d\n", argchamp[i]->flag_n);
        my_printf("parsing -a number of flag a = %d\n", argchamp[i]->flag_a);
        my_printf("parsing number of champion = %d\n",
        argchamp[i]->champnumber);
        my_printf("file descriptor : -%s-\n", argchamp[i]->file);
    }
}

int main(int argc, char *argv[])
{
    vm_t *vm = NULL;
    champions_t **champs = NULL;
    argchamp_t **argchamp = NULL;

    argchamp = my_parsing(argc, argv);
    vm = init_vm(argv);
    champs = init_champions(argv);
    place_champions(champs, vm);
    boucle_game(champs, vm);
    return 0;
}
