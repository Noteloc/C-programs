# ARM Code written for GAS Assembler
.extern scanf
.extern printf
.extern exit
.data
    hello: .asciz "Enter a string: "
    input: .space 30
    format: .asciz "%s"
    output: .asciz "Output: %s\n"

.global main
.align 4
.text
main:
    ldr x0, =[hello]
    bl printf

    ldr x0, =[format]
    ldr x1, =[input]
    bl scanf

    ldr x1, =[input]
    ldr x0, =[output]
    bl printf

    mov x0, 0
    b exit