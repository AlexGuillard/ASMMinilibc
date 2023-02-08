##
## EPITECH PROJECT, 2022
## B-PDG-300-NAN-3-1-PDGD04am-alexandre.guillard
## File description:
## Makefile
##

MAIN =

SRC = strlen.asm

SRC_T = 

OBJ = $(MAIN:%.c=%.o) $(SRC:%.asm=%.o)

OBJ_T = $(SRC:%.asm=%.o) $(SRC_T.c=.o)

NAME = libasm.so

NAME_T = unit_tests

CC = gcc

CFLAGS = -std=gnu17 -Wall -Wextra -g -ldl

ASM = nasm

ASMFLAGS = -f elf64

LD = ld

LDFLAGS = -fpic -shared

LSFLAGS = ar rc

all: $(NAME)

%.o: %.asm
	$(ASM) $(ASMFLAGS) $<

$(NAME): $(OBJ)
	$(LD) $(LDFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_T)
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_T)

re: fclean all

$(NAME_T): fclean all $(OBJ_T)
	gcc $(SRC_T) -lcriterion --coverage -o $(NAME_T)

tests_run: $(NAME_T)
	./$(NAME_T)
	gcovr --exclude tests -b