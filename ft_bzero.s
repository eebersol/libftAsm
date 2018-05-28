section .text
	global _ft_bzero


_ft_bzero:
	mov r10, rsi ; Recupere le parametre n
	xor rcx, rcx ; Met a zero le compteur

next:
	cmp rcx, r10
	jge done
	mov byte[rdi + rcx], 0
	inc rcx
	jmp next

done:
	ret