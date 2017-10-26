/*
** file_Elf32.c for file_Elf32 in /home/nasrat_v/Dev/rendu/tek2/Systeme-Unix/Memoire/PSU_2016_nmobjdump/objdump/32-bits
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Wed Feb 22 20:46:25 2017 Valentin Nasraty
** Last update Thu Feb 23 22:46:00 2017 Valentin Nasraty
*/

#include "../objdump.h"

void		_32_init_Elf_filePath(char *filepath, t_elf32 *elf)
{
  if (filepath != NULL)
    elf->file.filepath = filepath;
  else
    elf->file.filepath = "a.out";
}

int		_32_file_is_empty(t_elf32 *elf)
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

int		_32_open_Elf_file(t_elf32 *elf)
{
  if (_32_file_is_empty(elf) == 1)
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
