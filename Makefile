##
## EPITECH PROJECT, 2022
## B-PDG-300-NAN-3-1-PDGD04am-alexandre.guillard
## File description:
## Makefile
##

MAIN =

SRC = strlen.asm \
		strchr.asm \
		strrchr.asm \
		memset.asm \
		memcpy.asm \
		strcmp.asm \
		strncmp.asm \
		strcspn.asm \

SRC_T =

OBJ = $(MAIN:%.c=%.o) $(SRC:%.asm=%.o)

OBJ_T = $(SRC_T:%.c=%.o) $(SRC:%.asm=%.o) 

NAME = libasm.so

NAME_T = unit_tests

CC = gcc

CFLAGS = -std=gnu17 -Wall -Wextra -g -ldl

ASM = nasm

ASMFLAGS = -f elf64

LD = ld

LDFLAGS = -fpic -shared

LSFLAGS = ar rc

LIB = -L./ -lasm

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
	$(CC) $(OBJ_T) -lcriterion --coverage -o $(NAME_T) $(LIB) -ldl

tests_run: $(NAME_T)
	./$(NAME_T)
	gcovr --exclude tests -b

#