/*
** table_Elf64.c for table_Elf64 in /home/nasrat_v/Dev/rendu/tek2/Systeme-Unix/Memoire/PSU_2016_nmobjdump/objdump/64-bits
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Tue Feb 21 16:00:21 2017 Valentin Nasraty
** Last update Thu Feb 23 22:50:54 2017 Valentin Nasraty
*/

#include "../objdump.h"

void		_64_print_hexaSection(unsigned int size,
				      unsigned int next_addr,
				      unsigned char *octet)
{
  unsigned int 	i;

  i = 0;
  while (i < __ADDR_ALIGNEMENT__)
    {
      if (i % (__ADDR_ALIGNEMENT__ / 4) == 0)
	printf(" ");
      if ((i + next_addr) < size)
	printf("%02x", octet[i + next_addr]);
      else
      	printf("  ");
      i += 1;
    }
  printf("  ");
}

void		_64_print_asciiSection(unsigned int size,
				       unsigned int next_addr,
				       unsigned char *octet)
{
  unsigned int	i;

  i = 0;
  while (i < __ADDR_ALIGNEMENT__)
    {
      if ((i + next_addr) < size)
	{
	  if (octet[i + next_addr] >= ' ' && octet[i + next_addr] <= '~')
	    printf("%c", octet[i + next_addr]);
	  else
	    printf(".");
	}
      else
	printf(" ");
      i += 1;
    }
  printf("\n");
}

int		_64_print_contentsSection(t_elf64 *elf, int index)
{
  unsigned int	next_addr;
  unsigned char	*octet;

  next_addr = 0;
  if (((char*)elf->ehdr + elf->shdr[index].sh_offset) > _64_addrEnd_Ehdr(elf))
    return (-1);
  octet = (unsigned char*)((char*)elf->ehdr + elf->shdr[index].sh_offset);
  printf("Contents of section %s:\n",
	 _64_Shdr_strTab(elf, elf->shdr[index].sh_name));
  while (next_addr < elf->shdr[index].sh_size)
    {
      printf(" %04lx", (elf->shdr[index].sh_addr + next_addr));
      _64_print_hexaSection(elf->shdr[index].sh_size, next_addr, octet);
      _64_print_asciiSection(elf->shdr[index].sh_size, next_addr, octet);
      next_addr += __ADDR_ALIGNEMENT__;
    }
  return (0);
}

int		_64_filter_section(t_elf64 *elf, int index)
{
  if ((elf->shdr[index].sh_type != SHT_NULL && elf->shdr[index].sh_size != 0
       && elf->shdr[index].sh_type != SHT_NOBITS &&
       elf->shdr[index].sh_type != SHT_SYMTAB &&
       elf->shdr[index].sh_type != SHT_STRTAB &&
       elf->shdr[index].sh_type != SHT_RELA) ||
      (elf->shdr[index].sh_type == SHT_STRTAB &&
       (elf->shdr[index].sh_flags & SHF_ALLOC)) ||
      (elf->shdr[index].sh_type == SHT_RELA &&
       (elf->shdr[index].sh_flags & SHF_ALLOC)))
    return (0);
  return (1);
}

int		_64_print_ShdrTable(t_elf64 *elf)
{
  unsigned int 	index;

  index = 0;
  if (_64_init_Shdr(elf) == -1)
    {
      print_error(elf->error.file_truncated);
      return (-1);
    }
  if (_64_print_header(elf) == -1)
    return (-1);
  while (index < elf->ehdr->e_shnum)
    {
      if (_64_filter_section(elf, index) == 0)
	{
	  if (_64_print_contentsSection(elf, index) == -1)
	    return (-1);
	}
      index += 1;
    }
  return (0);
}
