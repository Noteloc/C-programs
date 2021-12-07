global _start
section .text

_start:
        mov rax, 0x5    ; Moving the value of 0x5 into the register rax
        stc             ; set the carry flag (cy) to 1
        adc rax, 0x1    ; add the value of 0x1 and the one stored in rax with the carry flag and store it in rax

        mov rax, 60    ; System call number for exit function
        mov rdi, 0     ; Parameter pass to exit function
        syscall        ; interrupt

section .data