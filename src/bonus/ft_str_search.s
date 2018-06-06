section .text
	global _ft_str_search
	extern _ft_strlen

_ft_str_search:

	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je out
	cmp rsi, 0
	je out
	push rdi
	push rsi
	mov r10, rdi
	call _ft_strlen
	mov rdi, r10
	xor rcx, rcx ; Met a zero le compteur

loop:
	mov al, 0
	mov bl, 0
	mov al, [rdi]
	mov bl, [r11]
	cmp al, bl
	je done
	cmp rcx, rax ; je compare mon index avec le param index
	je notFound
	inc rcx
	jmp loop

out:
	mov rax, 99
	leave
	ret

notFound:
	mov rax, -1
	leave
	ret

done:
	mov rax, 2
	leave
	ret