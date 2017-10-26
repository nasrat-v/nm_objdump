/*
** error_Elf64.c for error_Elf64 in /home/nasrat_v/Dev/rendu/tek2/Systeme-Unix/Memoire/PSU_2016_nmobjdump/nm/64-bits
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Wed Feb 22 20:37:07 2017 Valentin Nasraty
** Last update Thu Feb 23 23:51:15 2017 Valentin Nasraty
*/

#include "../nm.h"

void	print_error(char *error_msg)
{
  write(2, error_msg, strlen(error_msg));
}

char	*my_strcat(char *src, char *crs)
{
  char	*s;
  int	i;
  int	c;

  i = -1;
  c = -1;
  if ((s = malloc(sizeof(char) * (strlen(src) + strlen(crs) + 1))) == NULL)
    return (NULL);
  while (src[++i])
    s[i] = src[i];
  while (crs[++c])
    {
      s[i] = crs[c];
      i += 1;
    }
  s[i] = '\0';
  return (s);
}

char	*_64_init_error_filePath(t_elf64 *elf, char *msg)
{
  char	*error_var;

  if (strcmp(msg, "No such file\n") == 0)
    {
      if ((error_var = my_strcat(strdup("nm: '"), elf->file.filepath)) == NULL)
	return (NULL);
      if ((error_var = my_strcat(error_var, strdup("': "))) == NULL)
	return (NULL);
    }
  else
    {
      if ((error_var = my_strcat(strdup("nm: "), elf->file.filepath)) == NULL)
	return (NULL);
      if ((error_var = my_strcat(error_var, strdup(": "))) == NULL)
	return (NULL);
    }
  return (my_strcat(error_var, strdup(msg)));
}

int	_64_init_error(t_elf64 *elf)
{
  if ((elf->error.no_symbols =
       _64_init_error_filePath(elf, "no symbols\n")) == NULL)
    return (-1);
  if ((elf->error.no_such_file =
       _64_init_error_filePath(elf, "No such file\n")) == NULL)
    return (-1);
  if ((elf->error.file_truncated =
       _64_init_error_filePath(elf, "File truncated\n")) == NULL)
    return (-1);
  if ((elf->error.file_permission =
       _64_init_error_filePath(elf, "Permission denied\n")) == NULL)
    return (-1);
  if ((elf->error.format_not_recognized =
       _64_init_error_filePath(elf, "File format not recognized\n")) == NULL)
    return (-1);
  return (0);
}
