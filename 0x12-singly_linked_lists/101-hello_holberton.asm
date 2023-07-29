section .data
msg:	db "Hello, Holberton", 0  ; Null-terminated string to print

section .text
	extern printf                 ; Declare the external reference to printf
	global main                   ; Entry point of the program

main:
	; --- Prepare the arguments for printf ---
	mov rdi, hello                ; Set the format string (1st argument) to hello
	xor rax, rax                  ; Clear rax to indicate that there are no SSE arguments
	call printf                   ; Call printf with the format string

	; --- Exit the program ---
	xor rdi, rdi                  ; Set the exit code to 0
	mov rax, 60                   ; syscall number for sys_exit (60)
	syscall                       ; Invoke the syscall to exit
