.text
start:

mov r0, #0xff
mov r1, #0xff00
mov r2, #0xff0000

/* b single_op */
b many_op

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
