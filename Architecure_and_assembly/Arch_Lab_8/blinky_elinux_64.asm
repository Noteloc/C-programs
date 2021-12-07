.data
	setup:	.asciz	"Raspberry Pi Setup\n"
	ErrMsg:	.asciz	"Error\n"
	pins:	.word	4, 17, 27, 5
	dir:	.word	1, 1, 1, 1
	delayMs:.int	500
	OUTPUT = 1
.align 4
.globl main
.extern printf
.extern GPIOSetup
.extern delay
.extern GPIOWrite
.extern pinMode
.extern usleep

.text
main:
	stp x29, x30, [sp, -0x10]!
	ldr x0, =setup
	bl printf
	
	adr x0, pins
	adr x1, dir
	sub x2, x1, x0
	mov x4, 4
	udiv x2, x2, x4
	mov x5, x2	// backup size of pins
	bl GPIOSetup
	cmp x0, 0
	mov w4, w0
	bne exit

	mov w6, 7	// Light the LEDS with LSB
outer_loop:
	mov x9, 0
	adr x8, pins
inner_loop:
	ldr w0, [x8], 4 
	and w7, w6, 1
	mov w1, w7
	stp x2, x3, [sp, -16]!
	stp x4, x5, [sp, -16]!
	stp x6, x7, [sp, -16]!
	stp x8, x9, [sp, -16]!
	bl GPIOWrite
	ldp x8, x9, [sp], 16
	ldp x6, x7, [sp], 16
	ldp x4, x5, [sp], 16
	ldp x2, x3, [sp], 16
	cmp x0, 1
	mov w4, w0
	beq exit
	cmp w9, 12
	add w9, w9, 4
	bne inner_loop
	stp x2, x3, [sp, -16]!
	stp x4, x5, [sp, -16]!
	stp x6, x7, [sp, -16]!
	stp x8, x9, [sp, -16]!
	mov x0, 1
	bl sleep
	ldp x8, x9, [sp], 16
	ldp x6, x7, [sp], 16
	ldp x4, x5, [sp], 16
	ldp x2, x3, [sp], 16
	sub w6, w6, 1
	cmp w6, -1
	bne outer_loop

	mov x4, x5	// x5 contains backup of number of pins
	adr x2, pins
	mov x3, 0
unexport:
	ldr x0, [x2, 4]!
	mov x6, x0
	stp x2, x3, [sp, -16]!
	stp x4, x5, [sp, -16]!
	bl GPIOUnexport
	ldp x4, x5, [sp], 16
	ldp x2, x3, [sp], 16
	cmp x0, 0
	bne error
	add x3, x3, 1
	cmp x3, 4
	bne unexport
	b exit
error:
	ldr x0, =ErrMsg
	mov x1, x6
	bl printf
	b exit
exit:
	mov w8, 93
	mov w0, w4
	svc 0
