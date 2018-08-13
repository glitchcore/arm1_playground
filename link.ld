GROUP (
    libnosys.a
)

ENTRY(start)

SECTIONS {
    .text :
    {
        . = ALIGN(4);
        *(.irq);
        *(.text)
        . = ALIGN(4);
    }

    .data :
    {
        . = ALIGN(4);
        *(.data)    
        . = ALIGN(4);
        _estack = . + 120;     
    }
    .bss :
    {
        . = ALIGN(4);
         __bss_start__ = .;
        *(.bss)
        . = ALIGN(4);
        __bss_end__ = .;
    }
}