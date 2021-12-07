; Intel Code written for NASM Assembler
extern printf
extern exit
global main
	hello: db "Hello World",0xa,0x0
section .text
main:
	lea rdi, [hello]
	xor rax, rax
	call printf
	
	mov rdi, 0
	xor rax, rax
	call exit
