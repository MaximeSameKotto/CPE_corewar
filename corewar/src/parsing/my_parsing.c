/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** my_parsing
*/

#include "corewar.h"

void init_tab_champ(argchamp_t **argchamp, int nb)
{
    argchamp[0] = malloc(sizeof(argchamp_t));
    argchamp[0]->dump = -1;
    argchamp[0]->nb = -1;
    for (int i = 1; i <= nb + 1; i++) {
        argchamp[i] = malloc(sizeof(argchamp_t));
        argchamp[i]->champnumber = i;
        argchamp[i]->flag_a = -1;
        argchamp[i]->flag_n = -1;
    }
    argchamp[nb + 1] = NULL;
}

argchamp_t **my_parsing(int ac, char **av)
{
    int nbchamp = 0;
    int i = 0;
    argchamp_t **argchamp = NULL;

    check_flag_help(ac, av);
    nbchamp = check_champ(ac, av);
    argchamp = malloc(sizeof(argchamp_t *) * (nbchamp + 2));
    init_tab_champ(argchamp, nbchamp);
    i = check_dump(av, argchamp);
    argchamp[0]->nb = nbchamp;
    check_flag(argchamp, i, ac, av);
    return argchamp;
}