global _start
section .text

_start:
        mov al,0x1     ; move the value 0x1 into register al
        sub al,0x3     ; subtract the value of 0x3 from the value in al and store the result in al

        jns exit_with_10 ; jump if SF = 0 to exit_with_10

        mov rax, 60    ; System call number for exit function
        mov rdi, 0     ; Parameter pass to exit function
        syscall        ; interrupt

        exit_with_10:   ; jump to here

        mov rax, 60     ; System call number for exit function
        mov rdi, 10     ; Parameter pass to exit function, 10
        syscall         ; interrupt

section .data