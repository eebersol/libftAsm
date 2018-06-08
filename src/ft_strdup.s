section .text
	global _ft_strdup
	extern _ft_strlen
	extern _malloc

_ft_strdup:
	enter 16,0
	cmp rdi, 0;
	je fail

	mov rbx, rdi
	call _ft_strlen		; je calcule sa len
	mov r12, rax

	mov rdi, rax		; Je donne a malloc la size que je souhaite
	call _malloc
	
	mov rdi, rax		; Je donne ma zone allouée
	mov rcx, r12		; je lui donne sa longeur
	mov rsi, rbx
	rep movsb			; je lance literation

end:
	leave
	ret

fail:
	mov rax, 0;