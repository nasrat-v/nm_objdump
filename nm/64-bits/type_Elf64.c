/*
** type_Elf64.c for type_Elf64 in /home/nasrat_v/Dev/rendu/tek2/Systeme-Unix/Memoire/PSU_2016_nmobjdump/nm/64-bits
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Thu Feb 23 23:44:48 2017 Valentin Nasraty
** Last update Thu Feb 23 23:58:08 2017 Valentin Nasraty
*/

#include "../nm.h"

char		_64_print_SymType(t_elf64 *elf, int index)
{
  char		c;

  if (ELF64_ST_BIND(elf->sym[index].st_info) == STB_GNU_UNIQUE)
    c = 'u';
  else if (ELF64_ST_BIND(elf->sym[index].st_info) == STB_WEAK)
    {
      c = 'W';
      if (elf->sym[index].st_shndx == SHN_UNDEF)
        c = 'w';
    }
  else if (ELF64_ST_BIND(elf->sym[index].st_info)
	   == STB_WEAK && ELF64_ST_TYPE(elf->sym[index].st_info) == STT_OBJECT)
    {
      c = 'V';
      if (elf->sym[index].st_shndx == SHN_UNDEF)
        c = 'v';
    }
  else if (elf->sym[index].st_shndx == SHN_UNDEF)
    c = 'U';
  else
    return (_64_print_SymType_suite(elf, index));
  if (ELF64_ST_BIND(elf->sym[index].st_info) == STB_LOCAL && c != '?')
    c += 32;
  return (c);
}

char		_64_print_SymType_suite(t_elf64 *elf, int index)
{
  char		c;

  if (elf->sym[index].st_shndx == SHN_ABS)
    c = 'A';
  else if (elf->sym[index].st_shndx == SHN_COMMON)
    c = 'C';
  else if (elf->shdr[elf->sym[index].st_shndx].sh_type == SHT_NOBITS
       && elf->shdr[elf->sym[index].st_shndx].sh_flags ==
	   (SHF_ALLOC | SHF_WRITE))
    c = 'B';
  else if (elf->shdr[elf->sym[index].st_shndx].sh_type == SHT_PROGBITS
       && elf->shdr[elf->sym[index].st_shndx].sh_flags == SHF_ALLOC)
    c = 'R';
  else
    return (_64_print_SymType_sec_suite(elf, index));
  if (ELF64_ST_BIND(elf->sym[index].st_info) == STB_LOCAL && c != '?')
    c += 32;
  return (c);
}

char		_64_print_SymType_sec_suite(t_elf64 *elf, int index)
{
  char		c;

  if (elf->shdr[elf->sym[index].st_shndx].sh_type == SHT_PROGBITS
      && elf->shdr[elf->sym[index].st_shndx].sh_flags ==
      (SHF_ALLOC | SHF_WRITE))
    c = 'D';
  else if (elf->shdr[elf->sym[index].st_shndx].sh_type == SHT_PROGBITS
	   && elf->shdr[elf->sym[index].st_shndx].sh_flags ==
	   (SHF_ALLOC | SHF_EXECINSTR))
    c = 'T';
  else if (elf->shdr[elf->sym[index].st_shndx].sh_type == SHT_DYNAMIC)
    c = 'D';
  else
    c = ('t' - 32);
  if (ELF64_ST_BIND(elf->sym[index].st_info) == STB_LOCAL && c != '?')
    c += 32;
  return (c);
}
