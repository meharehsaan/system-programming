; System call in assembly

SECTION .data
    msg db "A System call using assembly", 0xa
    lenmsg equ $ - msg

SECTION .text
    global _start
_start:

    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, lenmsg
    syscall          ; systemcall

; exit syscall

    mov rax, 60
    mov rdi, 1
    syscall 