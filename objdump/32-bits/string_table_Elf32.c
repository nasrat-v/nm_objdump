/*
** string_table_Elf32.c for string_table_Elf32 in /home/nasrat_v/Dev/rendu/tek2/Systeme-Unix/Memoire/PSU_2016_nmobjdump/objdump/32-bits
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Wed Feb 22 20:48:28 2017 Valentin Nasraty
** Last update Wed Feb 22 20:48:45 2017 Valentin Nasraty
*/

#include "../objdump.h"

int		_32_init_Shdr_strTab(t_elf32 *elf)
{
  if (elf->ehdr->e_shstrndx == SHN_UNDEF)
    return (-1);
  if (((char*)elf->ehdr + elf->shdr[elf->ehdr->e_shstrndx].sh_offset) >
	   _32_addrEnd_Ehdr(elf))
    return (-1);
  elf->strtab.shdr_tab = (char*)elf->ehdr +
    elf->shdr[elf->ehdr->e_shstrndx].sh_offset;
  return (0);
}

int		_32_init_Sym_strTab(t_elf32 *elf, int index)
{
  if (((char*)elf->ehdr + elf->shdr[elf->shdr[index].sh_link].sh_offset) >
      _32_addrEnd_Ehdr(elf))
    return (-1);
  elf->strtab.sym_tab = (char*)elf->ehdr +
    elf->shdr[elf->shdr[index].sh_link].sh_offset;
  return (0);
}

char		*_32_Shdr_strTab(t_elf32 *elf, int to_print)
{
  return (&elf->strtab.shdr_tab[to_print]);
}

char		*_32_Sym_strTab(t_elf32 *elf, int to_print)
{
  return (&elf->strtab.sym_tab[to_print]);
}
