# nm_objdump
A simple implementation of GNU shell commands: Nm and Objdump.

These are very useful tools for programmers working on compiling tools, or for programmers working on binary security.

# NM
GNU nm lists the symbols from object files objfile…. If no object files are listed as arguments, nm assumes the file a.out.

For each symbol, nm shows:
    
- The symbol value, in the radix selected by options (see below), or hexadecimal by default.
- The symbol type. At least the following types are used; others are, as well, depending on the object file format. If lowercase, the symbol is usually local; if uppercase, the symbol is global (external). There are however a few lowercase symbols that are shown for special global symbols (u, v and w).
- The symbol name.
    
See man nm for more informations.

# OBJDUMP
GNU objdump displays information about one or more object files. 

The options control what particular information to display. This information is mostly useful to programmers who are working on       
the compilation tools, as opposed to programmers who just want their program to compile and work.
    
 See man objdump for more informations.

# Compile
    make

