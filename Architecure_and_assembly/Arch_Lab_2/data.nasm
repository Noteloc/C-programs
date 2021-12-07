global _start
section .text

_start:
        mov al, [mem1]      ; moving the contents of mem1 into the register al
        mov ebx, [mem2]     ; moving the contents of mem2 into the register ebx
        mov cx, 0x9a83      ; moving the value 0x9a83 into the register cx
        mov word [mem3], cx ; moving the contents of cx into mem3 (word means its moving 2 bytes)
        mov ecx, [mem4]     ; moving the contents of mem4 into the register ecx


        mov rax, 60    ; System call number for exit function
        mov rdi, 0     ; Parameter pass to exit function
        syscall        ; interrupt

section .data
        mem1: db 0x12       ; assigning mem1 the byte data 0x12
        mem2: dd 0x12345678 ; assigning mem2 the double word data 0x12345678
        mem3: dw 0x1234     ; assigning mem3 the word data 0x1234
        mem4: dq 0x123456789; assigning mem4 the quad word data 0x123456789