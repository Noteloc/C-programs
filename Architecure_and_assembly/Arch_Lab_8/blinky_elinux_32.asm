.globl main
.extern printf
.extern GPIOSetup
.extern delay
.extern GPIOWrite
.extern pinMode
.extern sleep

.align 4
.text
main:
	push {sp, lr}
	ldr r0, =setup
	bl printf
	
	ldr r0, =pins
	ldr r1, =dir
	sub r2, r1, r0
	mov r4, #4
	udiv r2, r2, r4
	mov r5, r2	// backup size of pins
	bl GPIOSetup
	cmp r0, #0
	mov r4, r0
	bne exit

	mov r6, #7	// Light the LEDS with LSB
outer_loop:
	mov r9, #0
	ldr r8, =pins
inner_loop:
	ldr r0, [r8], #4 
	and r7, r6, #1
	mov r1, r7
	push {r2, r3, r4, r5, r6, r7, r8, r9}
	bl GPIOWrite
	pop {r2, r3, r4, r5, r6, r7, r8, r9}
	cmp r0, #1
	mov r4, r0
	beq exit
	cmp r9, #12
	add r9, r9, #4
	bne inner_loop
	push {r2, r3, r4, r5, r6, r7, r8, r9}
	mov r0, #1
	bl sleep
	pop {r2, r3, r4, r5, r6, r7, r8, r9}
	sub r6, r6, #1
	cmp r6, #-1 
	bne outer_loop

	mov r4, r5	// r5 contains backup of number of pins
	ldr r2, =pins
	mov r3, #0
unexport:
	ldr r0, [r2, #4]!
	mov r6, r0
	push {r2, r3, r4, r5}
	bl GPIOUnexport
	pop {r2, r3, r4, r5}
	cmp r0, #0
	bne error
	add r3, r3, #1
	cmp r3, #4
	bne unexport
	b exit
error:
	ldr r0, =ErrMsg
	mov r1, r6
	bl printf
	b exit
exit:
	mov r7, #1
	mov r0, r4
	svc #0
.data
	setup:	.asciz	"Raspberry Pi Setup\n"
	ErrMsg:	.asciz	"Error\n"
	pins:	.word	4, 17, 27, 5
	dir:	.word	1, 1, 1, 1
	delayMs:.int	500
