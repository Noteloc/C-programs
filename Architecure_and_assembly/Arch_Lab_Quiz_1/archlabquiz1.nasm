global _start
section .text

_start:
        mov eax, [num1] ; move the value in num1 to eax
        mov edx, [num2] ; move the value in num2 to edx
        add eax, edx    ; add the values of edx and eax and store in eax

        l1:                 ; start position for loop
        sub eax, 0x00000002 ; subtract 0x00000002 from eax
        cmp eax, 0          ; compare 0 with eax, if not 0 then the ZF = 0, if eax is 0 set ZF = 1
        jne l1              ; if ZF = 0 then jump tp l1:

        xor edx, edx        ; clear the edx register

        mov rax, 60    ; System call number for exit function
        mov rdi, 0     ; Parameter pass to exit function
        syscall        ; interrupt

section .data
        num1: dd 0x80000001
        num2: dd 0x80000005