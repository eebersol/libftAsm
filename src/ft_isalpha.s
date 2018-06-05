section .text
	global _ft_isalpha

_ft_isalpha:
	cmp rdi, 65
	jl fail
	cmp rdi, 91
	ja succes
	cmp rdi, 97
	jl fail
	cmp rdi, 123
	ja succes

fail:
	mov rax, 0
	jmp end

succes:
	mov rax, 1
	jmp end

end:
	ret