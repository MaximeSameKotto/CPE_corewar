/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** check_champ
*/

#include "corewar.h"

void open_champ(char *av)
{
    int fd = 0;
    char buf[2];
    int fr = 0;

    fd = open(av, O_RDONLY);

    if (fd < 0)
        my_exit("Unable to open a champion\n", 84, 26);
    fr = read(fd, buf, 2);
    close(fd);
    if (fr < 0)
        my_exit("Unable to open a champion\n", 84, 26);
}

int check_champ(int ac, char **av)
{
    int nb = 0;

    for (int i = 0; i < ac; i++) {
        if (my_strlen(av[i]) > 3 && av[i][my_strlen(av[i]) - 1] == 'r' &&
        av[i][my_strlen(av[i]) - 2] == 'o' && av[i][my_strlen(av[i]) - 3]
        == 'c' && av[i][my_strlen(av[i]) - 4] == '.') {
            open_champ(av[i]);
            nb++;
        }
    }
    if (nb < 2)
        my_exit("You must put minimum 2 champions\n", 84, 33);
    if (nb > 4)
        my_exit("We take 4 champions max\n", 84, 24);
    return nb;
}