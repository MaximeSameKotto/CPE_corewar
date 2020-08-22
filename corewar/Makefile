##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	= 	gcc

SRC	=	src/main.c 						\
		src/parsing/my_parsing.c 		\
		src/parsing/check_flag.c 		\
		src/parsing/check_champ.c		\
		src/parsing/my_exit.c 			\
		src/parsing/my_flag.c 			\
		src/init_champions.c 			\
		src/init_vm.c 					\
		src/bytes_manipulation_utils.c 	\
		src/instructions.c 				\
		src/pc_management.c 			\
		src/op.c 						\
		src/manage_champions.c 			\
		src/game.c 						\
		src/cycles.c 					\
		src/manipule_reg.c 				\
		src/instructions/live.c 		\
		src/instructions/ld.c 			\
		src/instructions/st.c 			\
		src/instructions/add.c 			\
		src/instructions/sub.c 			\
		src/instructions/and.c 			\
		src/instructions/or.c 			\
		src/instructions/xor.c		 	\
		src/instructions/zjmp.c 		\
		src/instructions/ldi.c 			\
		src/instructions/sti.c 			\
		src/instructions/fork.c			\
		src/instructions/lldi.c 		\
		src/instructions/lld.c			\
		src/instructions/lfork.c		\
		src/instructions/aff.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	corewar

LDFLAGS	=	-L ./lib/my -lmy

CFLAGS	=	-Wall -Wextra -I ./include -g

TEST	=

LIBMY   = lib/my/libmy.a

TEST_OBJ =	$(TEST:.c=.o)

RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

.SILENT:

all: $(NAME)

$(NAME): libmy msg $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)
	printf "\n$(GREEN)[✓]$(NC)\x1B[32mExecutable $(NAME) ready !\x1B[37m\n"

%.o : %.c
	printf "\e[38;5;27m▒▒\e[0m"
	gcc -o $@ -c -I ./include $(CFLAGS) $^

libmy:
	make --no-print-directory -C ./lib/my/

msg:
	@printf "\n\x1B[38;5;27mCompiling $(NAME)...\n\x1b[37m"


test_run: CFLAGS += --coverage
test_run: LDFLAGS += -lcriterion --coverage
test_run: $(TEST_OBJ)
	$(CC) -o unit_tests $(TEST_OBJ) $(LDFLAGS)
	./unit_tests

clean:
	make --no-print-directory -C ./lib/my/ clean
	rm -f $(OBJ)
	printf "$(RED)[-]$(NC).o files deleted\n"
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	make --no-print-directory -C ./lib/my/ fclean
	rm -f $(NAME)
	printf "$(RED)[-]$(NC)Executable $(NAME) deleted\n"
	rm -f *.gcno
	rm -f ./tests/*.gcno
	rm -f *.gcda
	rm -f ./tests/*.gcda
	rm -f ./tests/*.o
	rm -f unit_tests

re: fclean all
