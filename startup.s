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
ldr sp, estack
ldr fp, estack
mov r7, #0
bl main
mov r7, #0xFE00
loop:
nop
nop
b loop

estack: .word _estack

error_handler:
nop
nop
nop
b error_handler
