/*
** nm.c for nm in /home/nasrat_v/Dev/rendu/tek2/Systeme-Unix/Memoire/PSU_2016_nmobjdump
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Sat Feb 18 11:33:00 2017 Valentin Nasraty
** Last update Thu Feb 23 23:12:57 2017 Valentin Nasraty
*/

#include "nm.h"

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

int		core(char *filepath, int nb_file)
{
  t_elf64	elf64;

  if (init_file(filepath, &elf64) == -1)
    return (1);
  else if (is_32_64_bits(&elf64) == 2)
    {
      if (core_64bits(&elf64, nb_file) == 1)
	return (1);
    }
  else if (is_32_64_bits(&elf64) == 1)
    {
      if (core_32bits(filepath, nb_file) == 1)
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
    err = core("a.out", 0);
  else
    {
      while (av[++i])
	err = core(av[i], (ac - 1));
    }
  return (err);
}
