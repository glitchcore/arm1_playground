.text
start:

mov r0, #0xff
mov r1, #0xff00
mov r2, #0xff0000

/* b single_op */
/* b many_op */
/* b shift */
b immed

single_op:
	add r3, r0, r1
	add r4, r1, r2
	add r3, r2, r0
	add r4, r0, r1
	add r3, r1, r2
	add r4, r2, r0

	add r3, r0, r1
	add r4, r1, r2
	add r3, r2, r0
	add r4, r0, r1
	add r3, r1, r2
	add r4, r2, r0

	add r3, r0, r1
	add r4, r1, r2
	add r3, r2, r0
	add r4, r0, r1
	add r3, r1, r2
	add r4, r2, r0

	add r3, r0, r1
	add r4, r1, r2
	add r3, r2, r0
	add r4, r0, r1
	add r3, r1, r2
	add r4, r2, r0

	add r3, r0, r1
	add r4, r1, r2
	add r3, r2, r0
	add r4, r0, r1
	add r3, r1, r2
	add r4, r2, r0
b single_op

many_op:
	add r3, r0, r1
	sub r4, r1, r2
	rsb r3, r2, r0
	and r4, r0, r1
	eor r3, r1, r2
	orr r4, r2, r0

	add r3, r0, r1
	sub r4, r1, r2
	rsb r3, r2, r0
	and r4, r0, r1
	eor r3, r1, r2
	orr r4, r2, r0

	add r3, r0, r1
	sub r4, r1, r2
	rsb r3, r2, r0
	and r4, r0, r1
	eor r3, r1, r2
	orr r4, r2, r0

	add r3, r0, r1
	sub r4, r1, r2
	rsb r3, r2, r0
	and r4, r0, r1
	eor r3, r1, r2
	orr r4, r2, r0

	add r3, r0, r1
	sub r4, r1, r2
	rsb r3, r2, r0
	and r4, r0, r1
	eor r3, r1, r2
	orr r4, r2, r0
b many_op

shift:
	add r3, r0, r1, LSL #1
	sub r4, r1, r2, LSL #2
	rsb r3, r2, r0, LSL #3
	and r4, r0, r1, LSL #4
	eor r3, r1, r2, LSL #5
	orr r4, r2, r0, LSL #6

	add r3, r0, r1, LSL #1
	sub r4, r1, r2, LSL #2
	rsb r3, r2, r0, LSL #3
	and r4, r0, r1, LSL #4
	eor r3, r1, r2, LSL #5
	orr r4, r2, r0, LSL #6

	add r3, r0, r1, LSL #1
	sub r4, r1, r2, LSL #2
	rsb r3, r2, r0, LSL #3
	and r4, r0, r1, LSL #4
	eor r3, r1, r2, LSL #5
	orr r4, r2, r0, LSL #6

	add r3, r0, r1, LSL #1
	sub r4, r1, r2, LSL #2
	rsb r3, r2, r0, LSL #3
	and r4, r0, r1, LSL #4
	eor r3, r1, r2, LSL #5
	orr r4, r2, r0, LSL #6

	add r3, r0, r1, LSL #1
	sub r4, r1, r2, LSL #2
	rsb r3, r2, r0, LSL #3
	and r4, r0, r1, LSL #4
	eor r3, r1, r2, LSL #5
	orr r4, r2, r0, LSL #6
b shift

immed:
	mov r0, #1
	mov r0, #2
	mov r0, #3
	mov r0, #4
	mov r0, #5
	mov r0, #6
	mov r0, #7
	mov r0, #8
	mov r0, #9
	mov r0, #10
	mov r0, #11
	mov r0, #12
	mov r0, #13
	mov r0, #14
	mov r0, #15
	mov r0, #16
	mov r0, #17
	mov r0, #18
	mov r0, #19
b immed
