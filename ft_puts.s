
global _ft_puts
extern _ft_strlen

section .text

_ft_puts:  
    call _ft_strlen
    mov rdx, rax                      ; LEN
    mov rax, 0x2000004                ; write
    mov rsi, rdi                      ; message
    mov rdi, 1                        ; stdoutm
    syscall

    mov rdx, 1
    mov rax, 0x2000004
    lea rsi, [rel newline]
    syscall
       

end:
    ret

section .data
    newline db '', 10