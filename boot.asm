; boot.asm - Boot sector for RiadOS4
; Assemble with: nasm -f bin boot.asm -o boot.bin

[BITS 16]
[ORG 0x7C00]

start:
    cli                 ; Clear interrupts just in case

    ; Set up stack
    xor ax, ax
    mov ds, ax
    mov ss, ax
    mov sp, 0x7C00

    ; Clear screen (text mode)
    mov ah, 0x00
    mov al, 0x03
    int 0x10

    ; Display boot message
    mov si, boot_msg
.print_loop:
    lodsb
    or al, al
    jz .done_print
    mov ah, 0x0E
    mov bh, 0x00
    mov bl, 0x07
    int 0x10
    jmp .print_loop

.done_print:
    ; Jump to kernel at 0x1000
    jmp 0x0000:0x1000

; Data
boot_msg db "idrjfpois zujng intoAHHHHHHHHHH4..igotcorruptedeeeeeeeeeeeeedeergrannys.", 0

; Padding to 510 bytes
times 510 - ($ - $$) db 0
dw 0xAA55  ; Boot signature
