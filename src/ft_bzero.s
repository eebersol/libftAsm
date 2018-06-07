section .text
	global _ft_bzero

_ft_bzero:
	xor rcx, rcx 				; Met a zero le registre rcx (compteur)

loop:
	cmp rcx, rsi 				; je compare mon compteur avec l index
	jge done					; si ils sont egaux fin du loop
	mov byte [rdi + rcx], 0		; je let la valeur du char/octet/byte rdi[rcx] a 0
	inc rcx						; j increment mon compteur
	jmp loop					; je recall mon llop

done:
	ret