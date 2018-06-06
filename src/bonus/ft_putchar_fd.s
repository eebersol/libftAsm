section .text
	global _ft_putchar_fd

_ft_putchar_fd:
	
	push rbp 				; save pointer stack
	mov rbp, rsp			; init new stack pointer

	mov byte [rbp-4], al	; move on first octet of param
	lea rax, [rbp-4]		; save on rax

	mov rdx, 1 				; input len
	mov rdi, rsi 			; stdout
	mov rsi, rax 			; input content
	mov rax, 0x2000004      ; syscall value (write)
    syscall                 ; write

	leave 					; restore stack
	ret