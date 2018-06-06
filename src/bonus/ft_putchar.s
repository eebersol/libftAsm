section .text
	global _ft_putchar

_ft_putchar:
	
	push rbp 				; save pointer stack
	mov rbp, rsp			; init new stack pointer

	mov byte [rbp-4], al	; move on first octet of param
	lea rax, [rbp-4]		; save on rax

	mov rdx, 1 				; input len
	mov rsi, rax 			; input content
	mov rax, 0x2000004      ; syscall value (write)
	mov rdi, 1 				; stdout
    syscall                 ; write

	leave 					; restore stack
	ret