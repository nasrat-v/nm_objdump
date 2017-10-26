/*
** core_architecture.c for core_architecture in /home/nasrat_v/Dev/rendu/tek2/Systeme-Unix/Memoire/PSU_2016_nmobjdump
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Mon Feb 20 10:15:33 2017 Valentin Nasraty
** Last update Thu Feb 23 23:14:26 2017 Valentin Nasraty
*/

#include "nm.h"

int		core_64bits(t_elf64 *elf, int nb_file)
{
  elf->file.nb_file = nb_file;
  if (_64_print_ShdrTable(elf) == -1)
    {
      close(elf->file.fd);
      return (1);
    }
  close(elf->file.fd);
  return (0);
}

int		core_32bits(char *filepath, int nb_file)
{
  t_elf32	elf;

  elf.file.nb_file = nb_file;
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
