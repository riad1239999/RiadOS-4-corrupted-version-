; kernel.asm - Boot transition to 32-bit protected mode and jump to kernel_main
; Assemble with: nasm -f elf kernel.asm -o kernel.o

[BITS 16]
[ORG 0x1000]

section .text
global _start
_start:
    cli                         ; Disable interrupts

    ; Load the Global Descriptor Table (GDT)
    lgdt [gdt_descriptor]

    ; Enable protected mode (set PE bit in CR0)
    mov eax, cr0
    or eax, 1
    mov cr0, eax

    ; Far jump to flush instruction queue and enter 32-bit mode
    jmp CODE_SEG:init_pm

; === 32-bit Protected Mode Entry Point ===
[BITS 32]
init_pm:
    ; Set up segment registers
    mov ax, DATA_SEG
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; Set up stack
    mov esp, stack_top

    ; Print welcome (if BIOS printing is implemented, this is optional)
    ; Otherwise, skip to kernel_main

    ; Call the C++ kernel's main function
    extern kernel_main
    call kernel_main

.hang:
    jmp .hang                   ; Halt forever if kernel_main returns

; === GDT Setup ===
gdt_start:
    dq 0x0000000000000000       ; Null descriptor
    dq 0x00CF9A000000FFFF       ; Code segment: base=0, limit=4GB, exec/read
    dq 0x00CF92000000FFFF       ; Data segment: base=0, limit=4GB, read/write
gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start

; Segment selectors
CODE_SEG equ 0x08
DATA_SEG equ 0x10

; === Stack Space ===
section .bss
align 16
stack_bottom:
    resb 4096                   ; 4 KB stack
stack_top:
