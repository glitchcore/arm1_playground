.text
start:

ldr r0, initial
ldr r1, increment

ldr r2, =array
ldr r3, size

add r3, r2, r3, LSL #2

loop:
	str r0, [r2]
	add r0, r0, r1
	add r2, r2, #4
	cmp r2, r3
blt loop

end_loop:
nop
b end_loop

initial: .word 0x06
increment: .word 0x02

size: .word 10
array: .skip 40
