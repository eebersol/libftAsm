section .bss
    user_input resb 256

section .text
	global _ft_cat
	extern _ft_strlen
	extern _ft_memset

_ft_cat:
	;prepare buffer
	lea rdi, [rel user_input]
	mov rsi, 0
	mov rdx, 256
	call _ft_memset

	mov rax, 0x2000003			; read
	mov rdi, 0					; input
	lea rsi, [rel user_input]	; buffer address
	mov rdx, 256				; buffer size
	syscall 					; execute read

	cmp rax, 0
	je end

	mov rdx, rax                      ; len
    mov rax, 0x2000004                ; write
    lea rsi, [rel user_input]         ; user_input
    mov rdi, 1                        ; stdout
    syscall							; execute read

	jmp _ft_cat

end:
	leave
	ret