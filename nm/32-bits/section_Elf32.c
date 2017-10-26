/*
** section_Elf32.c for section_Elf32 in /home/nasrat_v/Dev/rendu/tek2/Systeme-Unix/Memoire/PSU_2016_nmobjdump/32-bits
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Mon Feb 20 05:08:36 2017 Valentin Nasraty
** Last update Wed Feb 22 22:50:24 2017 Valentin Nasraty
*/

#include "../nm.h"

char		*_32_addrEnd_Ehdr(t_elf32 *elf)
{
  return ((char*)elf->ehdr + elf->file.size);
}

int	   	_32_init_Ehdr(t_elf32 *elf)
{
  void		*ptr;

  if ((ptr =
       mmap(NULL, elf->file.size, PROT_READ, MAP_SHARED, elf->file.fd, 0))
      == MAP_FAILED)
    return (-1);
  elf->ehdr = (Elf32_Ehdr*)ptr;
  return (0);
}

int		_32_init_Shdr(t_elf32 *elf)
{
  if (((char*)elf->ehdr + elf->ehdr->e_shoff) > _32_addrEnd_Ehdr(elf))
    return (-1);
  elf->shdr = (Elf32_Shdr*)((char*)elf->ehdr + elf->ehdr->e_shoff);
  return (_32_init_Shdr_strTab(elf));
}

int		_32_init_Sym(t_elf32 *elf, int index)
{
  if (((char*)elf->ehdr + elf->shdr[index].sh_offset) > _32_addrEnd_Ehdr(elf))
    return (-1);
  elf->sym = (Elf32_Sym*)((char*)elf->ehdr + elf->shdr[index].sh_offset);
  return (_32_init_Sym_strTab(elf, index));
}
