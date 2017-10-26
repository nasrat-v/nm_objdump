/*
** flags_Elf64.c for flags_Elf64 in /home/nasrat_v/Dev/rendu/tek2/Systeme-Unix/Memoire/PSU_2016_nmobjdump/objdump/64-bits
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Wed Feb 22 15:56:53 2017 Valentin Nasraty
** Last update Thu Feb 23 22:22:50 2017 Valentin Nasraty
*/

#include "../objdump.h"

void		_64_detect_sym_flags(t_elf64 *elf)
{
  unsigned int	index;

  index = 0;
  while (index < elf->ehdr->e_shnum)
    {
      if ((elf->shdr[index].sh_type == SHT_SYMTAB) ||
	  (elf->shdr[index].sh_type == SHT_DYNSYM))
	{
	  elf->flags.all_flags |= HAS_SYMS;
	}
      index += 1;
    }
}

void		_64_detect_all_flags(t_elf64 *elf)
{
  if (elf->ehdr->e_type == BFD_NO_FLAGS)
    elf->flags.all_flags |= BFD_NO_FLAGS;
  if (elf->ehdr->e_type == HAS_RELOC)
    elf->flags.all_flags |= HAS_RELOC;
  if (elf->ehdr->e_type == EXEC_P)
    elf->flags.all_flags |= EXEC_P;
  if (elf->ehdr->e_type == HAS_LINENO)
    elf->flags.all_flags |= HAS_LINENO;
  if (elf->ehdr->e_type == HAS_DEBUG)
    elf->flags.all_flags |= HAS_DEBUG;
  _64_detect_sym_flags(elf);
  if (elf->ehdr->e_type == HAS_LOCALS)
    elf->flags.all_flags |= HAS_LOCALS;
  if (elf->ehdr->e_type == ET_DYN)
    elf->flags.all_flags |= DYNAMIC;
  if (elf->ehdr->e_type == WP_TEXT)
    elf->flags.all_flags |= WP_TEXT;
  if (elf->ehdr->e_phnum > 0)
    elf->flags.all_flags |= D_PAGED;
}

void		_64_print_flags(t_elf64 *elf)
{
  int		i;
  int		nb_flags;

  i = 0;
  nb_flags = 0;
  while (elf->flags.flags_tab[i])
    {
      if (elf->flags.all_flags & ((int)pow(2, i)))
	{
	  if (nb_flags == 0)
	    printf("%s", elf->flags.flags_tab[i + 1]);
	  else
	    printf(", %s", elf->flags.flags_tab[i + 1]);
	  nb_flags += 1;
	}
      i += 1;
    }
}

int		_64_print_header(t_elf64 *elf)
{
  if (_64_set_flagsTab(elf) == -1)
    return (-1);
  _64_detect_all_flags(elf);
  printf("\n%s:     file format elf64-x86-64\n", elf->file.filepath);
  printf("architecture: i386:x86-64, flags 0x%08x:\n", elf->flags.all_flags);
  if (elf->flags.all_flags == 0)
    printf("BFD_NO_FLAGS");
  else
    _64_print_flags(elf);
  printf("\nstart address 0x%016lx\n\n", elf->ehdr->e_entry);
  return (0);
}

int		_64_set_flagsTab(t_elf64 *elf)
{
  elf->flags.all_flags = 0;
  if ((elf->flags.flags_tab = malloc(sizeof(char*) * 11)) == NULL)
    return (-1);
  elf->flags.flags_tab[0] = "BFD_NO_FLAGS";
  elf->flags.flags_tab[1] = "HAS_RELOC";
  elf->flags.flags_tab[2] = "EXEC_P";
  elf->flags.flags_tab[3] = "HAS_LINENO";
  elf->flags.flags_tab[4] = "HAS_DEBUG";
  elf->flags.flags_tab[5] = "HAS_SYMS";
  elf->flags.flags_tab[6] = "HAS_LOCALS";
  elf->flags.flags_tab[7] = "DYNAMIC";
  elf->flags.flags_tab[8] = "WP_TEXT";
  elf->flags.flags_tab[9] = "D_PAGED";
  elf->flags.flags_tab[10] = NULL;
  return (0);
}
