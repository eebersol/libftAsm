section .text
	global _ft_isprint

_ft_isprint:
	cmp rdi, 0
	jl fail
	cmp rdi, 126
	ja fail
	cmp rdi, 31
	ja succes

fail:
	mov rax, 0
	jmp end

succes:
	mov rax, 1
	jmp end

end:
	ret