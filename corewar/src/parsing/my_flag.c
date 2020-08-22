/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** my_flag
*/

#include "corewar.h"

void init_champ_file(argchamp_t **argchamp, int itab, int *i, char **av)
{
    argchamp[itab]->file = malloc(sizeof(char) * my_strlen(av[*i]) + 1);
    for (int a = 0; av[*i][a] != 0; a++) {
        argchamp[itab]->file[a] = av[*i][a];
    }
    argchamp[itab]->file[my_strlen(av[*i])] = 0;
    (*i)++;
}

void init_a_champ(argchamp_t **argchamp, int itab, int *i, char **av)
{
    argchamp[itab]->flag_a = my_getnbr(av[(*i)+1]);
    (*i) += 2;
}

void init_n_champ(argchamp_t **argchamp, int itab, int *i, char **av)
{
    argchamp[itab]->flag_n = my_getnbr(av[(*i)+1]);
    (*i) += 2;
}

int check_flag(argchamp_t **argchamp, int i, int ac, char **av)
{
    int itab = 1;

    for (; i < ac; itab++) {
        if (my_strcmp("-n", av[i]) == 1) {
            check_flag_n(av, ac, i);
            init_n_champ(argchamp, itab, &i, av);
        }
        if (my_strcmp("-a", av[i]) == 1) {
            check_flag_a(av, ac, i);
            init_a_champ(argchamp, itab, &i, av);
        }
        if (my_strlen(av[i]) > 3 && av[i][my_strlen(av[i]) - 1] == 'r' &&
        av[i][my_strlen(av[i]) - 2] == 'o' && av[i][my_strlen(av[i]) - 3]
        == 'c' && av[i][my_strlen(av[i]) - 4] == '.') {
            init_champ_file(argchamp, itab, &i, av);
        }
        else
            my_exit("Wrong file extension. It must be a .cor file\n", 84, 45);
    }
    return 0;
}