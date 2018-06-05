section .text
	global _ft_toupper

_ft_toupper:
	cmp rdi, 97
	jl fail
	cmp rdi, 122
	jl succes


fail:
	mov rax, rdi
	jmp end

succes:
	sub rdi, 20H
	mov rax, rdi
	jmp end

end:
	ret