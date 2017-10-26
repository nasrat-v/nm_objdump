/*
** file.c for file in /home/nasrat_v/Dev/rendu/tek2/Systeme-Unix/Memoire/PSU_2016_nmobjdump
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Sat Feb 18 11:19:59 2017 Valentin Nasraty
** Last update Thu Feb 23 23:51:30 2017 Valentin Nasraty
*/

#include "../nm.h"

void		_64_init_Elf_filePath(char *filepath, t_elf64 *elf)
{
  if (filepath != NULL)
    elf->file.filepath = filepath;
  else
    elf->file.filepath = "a.out";
}

int		_64_file_is_empty(t_elf64 *elf)
{
  struct stat	st;

  if (stat(elf->file.filepath, &st) == 0)
    {
      if (st.st_size > 0)
	return (0);
      return (1);
    }
  return (-1);
}

int		_64_open_Elf_file(t_elf64 *elf)
{
  if (_64_file_is_empty(elf) == 1)
    return (-1);
  if ((elf->file.fd = open(elf->file.filepath, O_RDONLY)) == -1)
    {
      if (errno == EACCES)
	print_error(elf->error.file_permission);
      else
	print_error(elf->error.no_such_file);
      return (-1);
    }
  elf->file.size = lseek(elf->file.fd, 0, SEEK_END);
  return (0);
}
