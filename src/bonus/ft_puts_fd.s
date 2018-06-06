section .text
    global _ft_puts_fd
    extern _ft_strlen

_ft_puts_fd:
    ; on save la string
    mov r12, rsi
    mov rsi, rdi
    call _ft_strlen

    ; on reinit la string a sa valeur de depart
    mov rdi, rsi

    mov rdx, rax                      ; LEN
    mov rax, 0x2000004                ; write
    mov rsi, rdi                      ; message
    mov rdi, r12                      ; stdoutm
    syscall                           ; write

    ; ajout du '\n'
    mov rdx, 1
    mov rax, 0x2000004
    lea rsi, [rel newline]
    syscall

end:
    ret

section .data
    newline db '', 10
