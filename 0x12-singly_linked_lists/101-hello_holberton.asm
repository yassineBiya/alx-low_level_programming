section .data
	hello db 'Hello, Holberton', 0x0A  ; Null-terminated string to print
	hello_len equ $ - hello           ; Length of the string

section .text
	global _start

_start:
	; --- Write the string to the standard output (file descriptor 1) ---
	mov rax, 1                      ; syscall number for sys_write (1)
	mov rdi, 1                      ; file descriptor 1 (stdout)
	mov rsi, hello                  ; pointer to the string to print
	mov rdx, hello_len              ; length of the string
	syscall                         ; invoke syscall

	; --- Exit the program ---
	mov rax, 60                     ; syscall number for sys_exit (60)
	xor rdi, rdi                    ; exit code 0
	syscall                         ; invoke syscall
