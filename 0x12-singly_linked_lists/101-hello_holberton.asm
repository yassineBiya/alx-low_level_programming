SECTION .data
hh:	db "Hello, Holberton", 0	; Null-terminated string to print
frmt:	db "%s", 10, 0			; The format string

SECTION .text 
extern printf					; Declare the external reference to printf
global main						; Entry point of the program

main:
	mov esi, hh
	mov edi, frmt
	mov eax, 0
	call printf

	mov eax, 0
	ret
