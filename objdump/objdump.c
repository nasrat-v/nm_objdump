/*
** objdump.c for objdump.c in /home/nasrat_v/Dev/rendu/tek2/Systeme-Unix/Memoire/PSU_2016_nmobjdump/objdump
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Tue Feb 21 15:55:03 2017 Valentin Nasraty
** Last update Thu Feb 23 22:49:17 2017 Valentin Nasraty
*/

#include "objdump.h"

int		init_file(char *filepath, t_elf64 *elf)
{
  _64_init_Elf_filePath(filepath, elf);
  if (_64_init_error(elf) == -1)
    return (-1);
  if (_64_open_Elf_file(elf) == -1)
    return (-1);
  if (_64_init_Ehdr(elf) == -1)
    {
      close(elf->file.fd);
      return (-1);
    }
  return (0);
}

int		core(char *filepath)
{
  t_elf64	elf64;

  if (init_file(filepath, &elf64) == -1)
    return (1);
  else if (is_32_64_bits(&elf64) == 2)
    {
      if (core_64bits(&elf64) == 1)
	return (1);
    }
  else if (is_32_64_bits(&elf64) == 1)
    {
      if (core_32bits(filepath) == 1)
	return (1);
    }
  else
    return (1);
  return (0);
}

int		main(int ac, char **av)
{
  int		i;
  int		err;

  i = 0;
  err = 0;
  if (ac == 1)
    err = core("a.out");
  else
    {
      while (av[++i])
	err = core(av[i]);
    }
  return (err);
}
