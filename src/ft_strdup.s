section .text
	global _ft_strdup
	extern _ft_strlen
	extern _malloc

_ft_strdup:
	enter 16,0

	mov r15, rdi 		; Je save la source
	call _ft_strlen		; je calcule sa len

	lea r12, [rax * 8]	; Je multiplie mon nombre de char par 8 pour avoir le nombre de bit
	mov rdi, r12		; Je donne a malloc la size que je souhaite
	call _malloc
	
	mov rdi, rax		; Je donne ma zone allouée
	mov rsi, r15		; Je lui donne la string a copier
	mov rcx, r12		; je lui donne sa longeur
	cld
	rep movsb			; je lance literation

end:
	leave
	ret