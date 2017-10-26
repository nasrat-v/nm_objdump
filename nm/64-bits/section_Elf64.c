/*
** section_Elf64.c for section_Elf64 in /home/nasrat_v/Dev/rendu/tek2/Systeme-Unix/Memoire/PSU_2016_nmobjdump
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Sat Feb 18 11:36:00 2017 Valentin Nasraty
** Last update Thu Feb 23 23:50:47 2017 Valentin Nasraty
*/

#include "../nm.h"

char		*_64_addrEnd_Ehdr(t_elf64 *elf)
{
  return ((char*)elf->ehdr + elf->file.size);
}

int	  	_64_init_Ehdr(t_elf64 *elf)
{
  void		*ptr;

  if ((ptr =
       mmap(NULL, elf->file.size, PROT_READ, MAP_SHARED, elf->file.fd, 0))
      == MAP_FAILED)
    return (-1);
  elf->ehdr = (Elf64_Ehdr*)ptr;
  return (0);
}

int		_64_init_Shdr(t_elf64 *elf)
{
  if (((char*)elf->ehdr + elf->ehdr->e_shoff) > _64_addrEnd_Ehdr(elf))
    return (-1);
  elf->shdr = (Elf64_Shdr*)((char*)elf->ehdr + elf->ehdr->e_shoff);
  return (_64_init_Shdr_strTab(elf));
}

int		_64_init_Sym(t_elf64 *elf, int index)
{
  if (((char*)elf->ehdr + elf->shdr[index].sh_offset) > _64_addrEnd_Ehdr(elf))
    return (-1);
  elf->sym = (Elf64_Sym*)((char*)elf->ehdr + elf->shdr[index].sh_offset);
  return (_64_init_Sym_strTab(elf, index));
}
