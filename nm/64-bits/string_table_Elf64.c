/*
** string_table_Elf64.c for string_table_Elf64 in /home/nasrat_v/Dev/rendu/tek2/Systeme-Unix/Memoire/PSU_2016_nmobjdump
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Sat Feb 18 11:33:53 2017 Valentin Nasraty
** Last update Tue Feb 21 19:37:15 2017 Valentin Nasraty
*/

#include "../nm.h"

int		_64_init_Shdr_strTab(t_elf64 *elf)
{
  if (elf->ehdr->e_shstrndx == SHN_UNDEF)
    return (-1);
  if (((char*)elf->ehdr + elf->shdr[elf->ehdr->e_shstrndx].sh_offset) >
	   _64_addrEnd_Ehdr(elf))
    return (-1);
  elf->strtab.shdr_tab = (char*)elf->ehdr +
    elf->shdr[elf->ehdr->e_shstrndx].sh_offset;
  return (0);
}

int		_64_init_Sym_strTab(t_elf64 *elf, int index)
{
  if (((char*)elf->ehdr + elf->shdr[elf->shdr[index].sh_link].sh_offset) >
      _64_addrEnd_Ehdr(elf))
    return (-1);
  elf->strtab.sym_tab = (char*)elf->ehdr +
    elf->shdr[elf->shdr[index].sh_link].sh_offset;
  return (0);
}

char		*_64_Shdr_strTab(t_elf64 *elf, int to_print)
{
  return (&elf->strtab.shdr_tab[to_print]);
}

char		*_64_Sym_strTab(t_elf64 *elf, int to_print)
{
  return (&elf->strtab.sym_tab[to_print]);
}
