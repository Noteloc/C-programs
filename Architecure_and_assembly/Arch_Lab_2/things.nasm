global _start
section .text

_start:
        mov eax, 0x48
        mov edx, [mem1]
        mov ecx, edx
        sub ecx, edx
        add [mem1], eax

        mov rax, 60    ; System call number for exit function
        mov rdi, 0     ; Parameter pass to exit function
        syscall        ; interrupt

section .data
        mem1: dw 0x1234