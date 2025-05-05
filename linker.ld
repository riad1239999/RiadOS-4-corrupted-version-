/* Advanced linker script for RiadOS4 kernel */

ENTRY(_start)

SECTIONS
{
    /* Start kernel at 1MB */
    . = 1M;

    /* Code/text section */
    .text ALIGN(4K) : AT(ADDR(.text))
    {
        *(.multiboot)
        *(.text*)
        *(.rodata*)
    }

    /* Read/write data */
    .data ALIGN(4K) : AT(ADDR(.data))
    {
        *(.data*)
    }

    /* Uninitialized data (zeroed at boot) */
    .bss ALIGN(4K) : AT(ADDR(.bss))
    {
        *(COMMON)
        *(.bss*)
    }

    /* Stack space at the end of kernel image */
    .stack ALIGN(4K) :
    {
        stack_bottom = .;
        . = . + 0x4000; /* 16 KB stack */
        stack_top = .;
    }

    /* Export stack symbols */
    PROVIDE(_stack_bottom = stack_bottom);
    PROVIDE(_stack_top = stack_top);
}
