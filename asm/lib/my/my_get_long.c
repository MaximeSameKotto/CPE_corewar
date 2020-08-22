/*
** EPITECH PROJECT, 2019
** corewar asm
** File description:
** get long
*/

long my_get_long(char const *str)
{
    long nega = 1;
    long result = 0;
    long i = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            nega = nega * -1;
        i++;
    }
    while (str[i] <= '9' && str[i] >= '0') {
        result *= 10;
        result += str[i] - 48;
        i++;
    }
    return (result * nega);
}
