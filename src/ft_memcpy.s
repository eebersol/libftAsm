section .text
	global _ft_memcpy
	extern _ft_strlen

_ft_memcpy:
	mov rdx, rcx			; On save la len 
	xor rcx, rcx 			; Met a zero le compteur
	mov rax, [rsi + rcx] 	; Value a modifier
	mov rcx, rdx			; nombre d iteration
	cld						; type diteration
	rep stosb				; iteration

done:
	ret