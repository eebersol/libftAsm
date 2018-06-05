section .text
	global _ft_bzero

_ft_bzero:
	xor rcx, rcx ; Met a zero le compteur

loop:
	cmp rcx, rsi ; je compare mon index avec le param index
	jge done
	mov byte [rdi + rcx], 0
	inc rcx
	jmp loop

done:
	ret