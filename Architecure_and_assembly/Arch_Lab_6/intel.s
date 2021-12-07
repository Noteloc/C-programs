# Intel Code written for GAS Assembler
.intel_syntax noprefix
.extern printf
.extern exit
.globl main
	hello: .ascii "Hello World\n\0"
.text
main:
	lea rdi, [hello]
	xor rax, rax
	call printf
	
	mov rdi, 0
	xor rax, rax
	call exit