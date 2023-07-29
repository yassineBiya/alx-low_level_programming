global main

section .text
main:
  mov rax, 0x40050A ; address of "Hello, Holberton!\n" string
  mov rdi, 1 ; stdout
  mov rsi, 1 ; number of bytes to write
  syscall ; write string to stdout
  mov rax, 0 ; return 0
  ret
