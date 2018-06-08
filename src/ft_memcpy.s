section .text
	global _ft_memcpy

_ft_memcpy:
	cmp rcx, 0
	je done_zero
	xor rcx, rcx 			; Met a zero le compteur

	mov rax, rsi 			; Value a modifier
	mov rcx, rdx			; nombre d iteration
	rep movsb				; iteration
	jmp done

done_zero:
	mov rax, rdi
	ret

done:
	ret

result:
	mov rax, rdx
	ret