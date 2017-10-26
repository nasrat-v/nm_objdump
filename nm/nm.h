/*
** nm.h for nm in /home/nasrat_v/Dev/rendu/tek2/Systeme-Unix/Memoire/PSU_2016_nmobjdump
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Sat Feb 18 04:00:34 2017 Valentin Nasraty
** Last update Thu Feb 23 23:49:27 2017 Valentin Nasraty
*/

#ifndef __NM_H__
# define __NM_H__

#include <elf.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

typedef struct	s_strtab
{
  char		*shdr_tab;
  char		*sym_tab;
}		t_strtab;

typedef struct	s_file
{
  int		fd;
  int		nb_file;
  unsigned int 	size;
  char		*filepath;
}		t_file;

typedef struct	s_error
{
  char		*no_symbols;
  char		*no_such_file;
  char		*file_truncated;
  char		*file_permission;
  char		*format_not_recognized;
}		t_error;

/**************************************
 *
 *	ARCHITECTURE 64 BITS
 *
 *************************************/

typedef struct	s_elf64
{
  Elf64_Ehdr	*ehdr;
  Elf64_Shdr	*shdr;
  Elf64_Sym	*sym;
  t_file	file;
  t_strtab	strtab;
  t_error	error;
}		t_elf64;

// SECTION ELF64
char		*_64_addrEnd_Ehdr(t_elf64 *elf);
int		_64_init_Ehdr(t_elf64 *elf);
int		_64_init_Shdr(t_elf64 *elf);
int		_64_init_Sym(t_elf64 *elf, int index);

// TABLE ELF64
void		_64_print_asciiSym(t_elf64 *elf, int cnt, char type);
int		_64_print_SymTable(t_elf64 *elf, int index);
int		_64_print_ShdrTable(t_elf64 *elf);

// TYPE ELF64
char		_64_print_SymType(t_elf64 *elf, int index);
char		_64_print_SymType_suite(t_elf64 *elf, int index);
char		_64_print_SymType_sec_suite(t_elf64 *elf, int index);

// STRING TABLE ELF64
int		_64_init_Shdr_strTab(t_elf64 *elf);
int		_64_init_Sym_strTab(t_elf64 *elf, int index);
char		*_64_Shdr_strTab(t_elf64 *elf, int to_print);
char		*_64_Sym_strTab(t_elf64 *elf, int to_print);

// FILE ELF64
void		_64_init_Elf_filePath(char *filepath, t_elf64 *elf);
int		_64_file_is_empty(t_elf64 *elf);
int		_64_open_Elf_file(t_elf64 *elf);

// ERROR ELF64
void		print_error(char *str);
char		*my_strcat(char *src, char *crs);
char		*_64_init_error_filePath(t_elf64 *elf, char *msg);
int		_64_init_error(t_elf64 *elf);

/**************************************
 *
 *	ARCHITECTURE 32 BITS
 *
 *************************************/

typedef struct	s_elf32
{
  Elf32_Ehdr	*ehdr;
  Elf32_Shdr	*shdr;
  Elf32_Sym	*sym;
  t_file	file;
  t_strtab	strtab;
  t_error	error;
}		t_elf32;

// SECTION ELF32
char		*_32_addrEnd_Ehdr(t_elf32 *elf);
int		_32_init_Ehdr(t_elf32 *elf);
int		_32_init_Shdr(t_elf32 *elf);
int		_32_init_Sym(t_elf32 *elf, int index);

// TABLE ELF32
void		_32_print_asciiSym(t_elf32 *elf, int cnt, char type);
int		_32_print_SymTable(t_elf32 *elf, int index);
int		_32_print_ShdrTable(t_elf32 *elf);

// TYPE ELF32
char		_32_print_SymType(t_elf32 *elf, int index);
char		_32_print_SymType_suite(t_elf32 *elf, int index);
char		_32_print_SymType_sec_suite(t_elf32 *elf, int index);

// STRING TABLE ELF32
int		_32_init_Shdr_strTab(t_elf32 *elf);
int		_32_init_Sym_strTab(t_elf32 *elf, int index);
char		*_32_Shdr_strTab(t_elf32 *elf, int to_print);
char		*_32_Sym_strTab(t_elf32 *elf, int to_print);

// FILE ELF32
void		_32_init_Elf_filePath(char *filepath, t_elf32 *elf);
int		_32_file_is_empty(t_elf32 *elf);
int		_32_open_Elf_file(t_elf32 *elf);

// ERROR ELF32
char		*_32_init_error_filePath(t_elf32 *elf, char *msg);
int		_32_init_error(t_elf32 *elf);

/**************************************
 *
 *	ARCHITECTURE 64 ET 32 BITS
 *
 *************************************/

// CORE ARCHITECURE
int		core_64bits(t_elf64 *elf, int nb_file);
int		core_32bits(char *filepath, int nb_file);
int		is_32_64_bits(t_elf64 *elf);

// NM
int		init_file(char *filepath, t_elf64 *elf);
int		core(char *filepath, int nb_file);
int		main(int ac, char **av);

#endif /* !__NM_H__ */
