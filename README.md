# st-libasm (2020/11/02)

## INFO
An assembly (or assembler) language, often abbreviated asm, is a low-level programming language for a computer, or other programmable device, in which there is a very strong (but often not one-to-one) correspondence between the language and the architecture’s machine code instructions. Each assembly language is specific to a particular computer architecture. In contrast, most high-level programming languages are generally portable across multiple architectures but require interpreting or compiling. Assembly language may also be called symbolic machine code.

## TASK
- You must write 64 bits ASM. Beware of the "calling convention".
- You can’t do inline ASM, you must do ’.s’ files.
- You must compile your assembly code with nasm.
- You must use the Intel syntax, not the AT&T.
- The library must be called libasm.a.
- You must submit a main that will test your functions and that will compile with your library to show that it’s functional.
- You must rewrite the following functions in asm:

  ft_strlen
  ft_strcpy
  ft_strcmp
  ft_write
  ft_read
  ft_strdup (you can call to malloc)
 
- You must check for errors during syscalls and properly set them when needed
- Your code must set the variable errno properly.
- For that, you are allowed to call the extern ___error or errno_location.

## MAKE
make

make test

## Additional Information
  man 3 strlen
  man 3 strcpy
  man 3 strcmp
  man 2 write
  man 2 read
  man 3 strdup
