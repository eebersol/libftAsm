
section .data
    null_str    db      "(null)",0xa
    null_len    equ     $-null_str
    newline     db '',  0xa

section .text
    global _ft_puts
    extern _ft_strlen

_ft_puts:
    cmp rdi, 0
    je endBis
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
    jmp end

endBis:
    mov rdx, null_len                 ;   null_len
    mov rax, 0x2000004                ; write
    mov rdi, 1                        ; stdout
    m lea rsi, [rel null_str]         ;   null_str,
    syscall
    jmp end

end:
    mov rax,10
    ret