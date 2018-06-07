section .text
	global _ft_isspace

_ft_isspace:
	cmp rdi, 9
	je succes
	cmp rdi, 10
	je succes
	cmp rdi, 11
	je succes
	cmp rdi, 12
	je succes
	cmp rdi, 13
	je succes
	cmp rdi, 32
	je succes
	jmp fail	

fail:
	mov rax, 0
	jmp end

succes:
	mov rax, 1
	jmp end

end:
	ret