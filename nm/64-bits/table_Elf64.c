/*
** table_Elf64.c for table_Elf64 in /home/nasrat_v/Dev/rendu/tek2/Systeme-Unix/Memoire/PSU_2016_nmobjdump
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Sat Feb 18 11:32:49 2017 Valentin Nasraty
** Last update Thu Feb 23 23:46:27 2017 Valentin Nasraty
*/

#include "../nm.h"

void		_64_print_asciiSym(t_elf64 *elf, int cnt, char type)
{
  if (elf->sym[cnt].st_value != 0)
    printf("%016lx %c %s\n", elf->sym[cnt].st_value, type,
	   _64_Sym_strTab(elf, elf->sym[cnt].st_name));
  else if (elf->sym[cnt].st_value == 0 && type == 'T')
    printf("0000000000000000 %c %s\n", type,
	   _64_Sym_strTab(elf, elf->sym[cnt].st_name));
  else
    printf("                 %c %s\n", type,
	   _64_Sym_strTab(elf, elf->sym[cnt].st_name));
}

int		_64_print_SymTable(t_elf64 *elf, int index)
{
  char		type;
  unsigned int	cnt;

  cnt = 0;
  if (_64_init_Sym(elf, index) == -1)
    {
      print_error(elf->error.file_truncated);
      return (-1);
    }
  while (cnt < (elf->shdr[index].sh_size / elf->shdr[index].sh_entsize))
    {
      type = _64_print_SymType(elf, cnt);
      if (elf->sym[cnt].st_name != 0 && type != 'a')
      	_64_print_asciiSym(elf, cnt, type);
      cnt += 1;
    }
  return (0);
}

int		_64_print_ShdrTable(t_elf64 *elf)
{
  unsigned int 	index;
  unsigned int	is_there_symbol;

  index = 0;
  is_there_symbol = 0;
  if (_64_init_Shdr(elf) == -1)
    {
      print_error(elf->error.file_truncated);
      return (-1);
    }
  if (elf->file.nb_file > 1)
    printf("\n%s:\n", elf->file.filepath);
  while (index < elf->ehdr->e_shnum)
    {
      if (elf->shdr[index].sh_type == SHT_SYMTAB)
	{
	  is_there_symbol += 1;
	  if (_64_print_SymTable(elf, index) == -1)
	    return (-1);
	}
      index += 1;
    }
  if (is_there_symbol == 0 && index > 0)
    print_error(elf->error.no_symbols);
  return (0);
}
