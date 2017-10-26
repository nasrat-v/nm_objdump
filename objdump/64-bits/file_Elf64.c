/*
** file_Elf64.c for file_Elf64 in /home/nasrat_v/Dev/rendu/tek2/Systeme-Unix/Memoire/PSU_2016_nmobjdump/objdump/64-bits
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Tue Feb 21 15:58:45 2017 Valentin Nasraty
** Last update Thu Feb 23 22:51:12 2017 Valentin Nasraty
*/

#include "../objdump.h"

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
