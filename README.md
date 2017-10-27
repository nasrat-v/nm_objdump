# nm_objdump
A simple implementation of GNU shell commands: Nm and Objdump.

- These commands disassemble executable files, relocatable object files, core files, and shared objects in a Unix environnement
- These are very useful tools for programmers working on compiling tools
- Or for programmers working on binary security.


# Nm command
GNU nm lists the symbols from object files objfile…. If no object files are listed as arguments, nm assumes the file a.out.

For each symbol, nm shows:
    
- The symbol value, in the radix selected by options (see below), or hexadecimal by default
- The symbol type. At least the following types are used; others are, as well, depending on the object file format. If lowercase, the symbol is usually local; if uppercase, the symbol is global (external). There are however a few lowercase symbols that are shown for special global symbols (u, v and w)
- The symbol name
    
See man nm for more informations.

# Objdump command
GNU objdump displays information about one or more object files. 

- Display summary information from the overall header of each of the objfile files
- Display the full contents of any sections requested. By default all non-empty sections are displayed

See man objdump for more informations.
 
 # Format
 These tools use the C ELF structure (Executable and Linking Format). See man elf.
 
x86-64 and i386 architecture are both supported.
 

# Compile
    make

