/*
** core_architecture.c for core_architecture in /home/nasrat_v/Dev/rendu/tek2/Systeme-Unix/Memoire/PSU_2016_nmobjdump/objdump
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Tue Feb 21 16:10:21 2017 Valentin Nasraty
** Last update Thu Feb 23 22:42:47 2017 Valentin Nasraty
*/

#include "objdump.h"

int		core_64bits(t_elf64 *elf)
{
  if (_64_print_ShdrTable(elf) == -1)
    {
      close(elf->file.fd);
      return (1);
    }
  close(elf->file.fd);
  return (0);
}

int		core_32bits(char *filepath)
{
  t_elf32	elf;

  _32_init_Elf_filePath(filepath, &elf);
  if (_32_init_error(&elf) == -1)
    return (1);
  if (_32_open_Elf_file(&elf) == -1)
    return (1);
  if (_32_init_Ehdr(&elf) == -1)
    {
      close(elf.file.fd);
      return (1);
    }
  if (_32_print_ShdrTable(&elf) == -1)
    {
      close(elf.file.fd);
      return (1);
    }
  close(elf.file.fd);
  return (0);
}

int		is_32_64_bits(t_elf64 *elf)
{
  if (elf->ehdr->e_ident[1] == 'E' &&
      elf->ehdr->e_ident[2] == 'L' &&
      elf->ehdr->e_ident[3] == 'F')
    {
      if (elf->ehdr->e_ident[4] != 0)
	return (elf->ehdr->e_ident[4]);
    }
  print_error(elf->error.format_not_recognized);
  return (-1);
}
