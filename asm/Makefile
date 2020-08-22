##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	= 	gcc

SRC	= 	src/main.c	\
		src/line_to_instruction.c	\
		src/parse_header.c	\
		src/clean_line.c	\
		src/init_parsing_utils.c	\
		src/parse_label_initialisation.c	\
		src/header_field_error_handling.c	\
		src/is_valid_adressing.c	\
		src/parse_params.c	\
		src/op.c	\
		src/header_to_binary.c	\
		src/param_to_binary.c	\
		src/bytes_manipulation_utils.c	\
		src/parse_instructions.c	\
		src/format_line.c	\

OBJ	=	$(SRC:.c=.o)

NAME 	=	asm

LDFLAGS	=	-L ./lib/my -lmy

CFLAGS	=	-Wall -Wextra -I ./include -g

TEST	=	./src/clean_line.c	\
			src/line_to_instruction.c	\
			src/parse_header.c	\
			src/init_pasing_utils.c	\
			src/parse_label_initialisation.c	\
			src/header_field_error_handling.c	\
			src/is_valid_adressing.c	\
			src/parse_params.c	\
			src/op.c	\
			src/header_to_binary.c	\
			src/param_to_binary.c	\
			src/bytes_manipulation_utils.c	\
			src/parse_instructions.c	\
			./tests/tests_parse_line.c	\

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
