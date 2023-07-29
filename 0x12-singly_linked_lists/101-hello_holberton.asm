SECTION .data
hh:	db "Hello, Holberton", 0
frmt:	db "%s", 10, 0

	SECTION .text
	extern printf
	global main
main:
	mov esi, hh
	mov edi, frmt
	mov eax, 0
	call printf

	ret
