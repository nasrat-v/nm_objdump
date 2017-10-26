##
## Makefile for Makefile in /home/nasrat_v/Dev/rendu/tek2/Systeme-Unix/Memoire/PSU_2016_nmobjdump
## 
## Made by Valentin Nasraty
## Login   <valentin.nasraty@epitech.eu>
## 
## Started on  Tue Feb 14 13:43:14 2017 Valentin Nasraty
## Last update Fri Feb 24 00:14:20 2017 Valentin Nasraty
##

SRC_NM		= nm/nm.c \
		  nm/core_architecture.c \
		  nm/64-bits/file_Elf64.c \
		  nm/64-bits/string_table_Elf64.c \
		  nm/64-bits/section_Elf64.c \
		  nm/64-bits/table_Elf64.c \
		  nm/64-bits/error_Elf64.c \
		  nm/64-bits/type_Elf64.c \
		  nm/32-bits/file_Elf32.c \
		  nm/32-bits/string_table_Elf32.c \
		  nm/32-bits/section_Elf32.c \
		  nm/32-bits/table_Elf32.c \
		  nm/32-bits/error_Elf32.c \
		  nm/32-bits/type_Elf32.c

SRC_OBJ		= objdump/objdump.c \
		  objdump/core_architecture.c \
		  objdump/64-bits/error_Elf64.c \
		  objdump/64-bits/file_Elf64.c \
		  objdump/64-bits/flags_Elf64.c \
		  objdump/64-bits/section_Elf64.c \
		  objdump/64-bits/string_table_Elf64.c \
		  objdump/64-bits/table_Elf64.c \
		  objdump/32-bits/error_Elf32.c \
		  objdump/32-bits/file_Elf32.c \
		  objdump/32-bits/flags_Elf32.c \
		  objdump/32-bits/section_Elf32.c \
		  objdump/32-bits/string_table_Elf32.c \
		  objdump/32-bits/table_Elf32.c

OBJ_NM		= $(SRC_NM:.c=.o)

OBJ_OBJ		= $(SRC_OBJ:.c=.o)

CC		= gcc

RM		= rm -f

MATH		= -lm

NAME_NM		= my_nm

NAME_OBJ	= my_objdump

CFLAGS		= -W -Werror -Wextra -Wall -pedantic -std=gnu99

all:		clean nm objdump

$(NAME_NM):	$(OBJ_NM)
		$(CC) -o $(NAME_NM) $(OBJ_NM) $(MATH)

$(NAME_OBJ):	$(OBJ_OBJ)
		$(CC) -o $(NAME_OBJ) $(OBJ_OBJ) $(MATH)

nm:		$(NAME_NM)

objdump:	$(NAME_OBJ)

clean:
		$(RM) $(OBJ_NM) $(OBJ_OBJ)

fclean:		clean
		$(RM) $(NAME_NM) $(NAME_OBJ)

re:		fclean all
