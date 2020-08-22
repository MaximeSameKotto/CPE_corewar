/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** init_champions.c
*/

#include "corewar.h"

int get_nb_champ(char *argv[])
{
    int i = 1;
    int tmp = 0;

    for (; argv[i] != 0; i++) {
        if (argv[i][0] != '-')
            tmp++;
    }
    return tmp;
}

void add_new_champ(champions_t **champ, char *file)
{
    FILE *f = fopen(file, "r");

    *champ = malloc(sizeof(champions_t));
    (*champ)->header = malloc(sizeof(header_t));
    fread(&((*champ)->header->magic), 4, 1, f);
    (*champ)->header->magic = reverse_bytes((*champ)->header->magic);
    fread((*champ)->header->prog_name, PROG_NAME_LENGTH, 1, f);
    fseek(f, 4, SEEK_CUR);
    fread(&(*champ)->header->prog_size, 4, 1, f);
    (*champ)->header->prog_size = reverse_bytes((*champ)->header->prog_size);
    fread((*champ)->header->comment, COMMENT_LENGTH, 1, f);
    fseek(f, 4, SEEK_CUR);
    (*champ)->code = malloc(sizeof(char) * (*champ)->header->prog_size);
    fread((*champ)->code, (*champ)->header->prog_size, 1, f);
    (*champ)->live = false;
    (*champ)->in_game = true;
    (*champ)->carry = false;
}

champions_t **init_champions(char *argv[])
{
    champions_t **champions;
    int nb_champ = get_nb_champ(argv);

    champions = malloc(sizeof(champions_t *) * (nb_champ + 1));
    champions[nb_champ] = 0;
    for (int i = 1; argv[i] != 0; i++) {
        if (argv[i][0] != '-') {
            add_new_champ(&champions[i - 1], argv[i]);
        }
    }
    return champions;
}
