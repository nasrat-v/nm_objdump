/*
** error_Elf32.c for error_Elf32 in /home/nasrat_v/Dev/rendu/tek2/Systeme-Unix/Memoire/PSU_2016_nmobjdump/objdump/32-bits
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Wed Feb 22 20:44:56 2017 Valentin Nasraty
** Last update Thu Feb 23 22:48:40 2017 Valentin Nasraty
*/

#include "../objdump.h"

char	*_32_init_error_filePath(t_elf32 *elf, char *msg)
{
  char	*error_var;

  if (strcmp(msg, "No such file\n") == 0)
    {
      if ((error_var = my_strcat(strdup("objdump: '"),
				 elf->file.filepath)) == NULL)
	return (NULL);
      if ((error_var = my_strcat(error_var, strdup("': "))) == NULL)
	return (NULL);
    }
  else
    {
      if ((error_var = my_strcat(strdup("objdump: "),
				 elf->file.filepath)) == NULL)
	return (NULL);
      if ((error_var = my_strcat(error_var, strdup(": "))) == NULL)
	return (NULL);
    }
  return (my_strcat(error_var, strdup(msg)));
}

int	_32_init_error(t_elf32 *elf)
{
  if ((elf->error.no_symbols =
       _32_init_error_filePath(elf, "no symbols\n")) == NULL)
    return (-1);
  if ((elf->error.no_such_file =
       _32_init_error_filePath(elf, "No such file\n")) == NULL)
    return (-1);
  if ((elf->error.file_truncated =
       _32_init_error_filePath(elf, "File truncated\n")) == NULL)
    return (-1);
  if ((elf->error.file_permission =
       _32_init_error_filePath(elf, "Permission denied\n")) == NULL)
    return (-1);
  if ((elf->error.format_not_recognized =
       _32_init_error_filePath(elf, "File format not recognized\n")) == NULL)
    return (-1);
  return (0);
}
