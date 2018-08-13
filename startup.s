.section .irq
b start // Reset
b error_handler // Undefined_Instruction_Trap
b error_handler // Software Interrupt
b error_handler // Abort (Prefetch)
b error_handler // Abort (Data)
b error_handler // Address Exception
b error_handler // Normal Interrupt (IRQ)
b error_handler // Fast Interrupt (FIRQ)

.text

.global start
start:
mov     r2, #12
/* movs    pc, r2 */

ldr sp, estack
ldr fp, estack
bl main
mov r7, #0xFE00
b test_s

estack: .word _estack

.global test_s
test_s:
mov r2, #33
ldr r5, tty_ptr
ldr r3, [r5]
ldr r4, hello_string_ptr
loop:
nop
nop
nop
ldr r2, [r4]
and r2, r2, #0xff
str r2, [r3]
add r4, r4, #1
b loop

error_handler:
nop
nop
nop
b error_handler

tty_ptr: .word tty
hello_string_ptr: .word hello_string
