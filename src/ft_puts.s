section .text
    global _ft_puts
    extern _ft_strlen

_ft_puts:
    mov rsi, rdi ; save start pointer
    call _ft_strlen

    mov rdi, rsi    ; reset start pointer

    mov rdx, rax                      ; LEN
    mov rax, 0x2000004                ; write
    mov rsi, rdi                      ; message
    mov rdi, 1                        ; stdout
    syscall                           ; write

    ; ajout du '\n'
    mov rdx, 1                        ; LEN
    mov rax, 0x2000004                ; write
    mov rdi, 1                        ; stdout
    lea rsi, [rel newline]
    syscall

end:
    ret

section .data
    newline db '', 10
