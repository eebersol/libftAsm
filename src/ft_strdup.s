section .text
	global _ft_strdup
	extern _ft_strlen
	extern _malloc

_ft_strdup:
	cmp rdi, 0;
	je fail

	push rdi
	call _ft_strlen		; je calcule sa len
	mov r12, rax

	mov rdi, rax		; Je donne a malloc la size que je souhaite
	call _malloc
	
	pop rdi
	mov rsi, rdi		; src start pointer
	mov rdi, rax		; Je donne ma zone allouée
	mov rcx, r12		; je lui donne sa longeur
	rep movsb			; je lance literation

end:
	ret

fail:
	mov rax, 0;