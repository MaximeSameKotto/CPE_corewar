##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

.SILENT:

all:
	make --no-print-directory -C ./asm/
	make --no-print-directory -C ./corewar/

clean:
	make --no-print-directory -C ./asm/ clean
	make --no-print-directory -C ./corewar/ clean

fclean: clean
	make --no-print-directory -C ./asm/ fclean
	make --no-print-directory -C ./corewar/ fclean

re: fclean all
