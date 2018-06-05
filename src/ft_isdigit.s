section .text
	global _ft_isdigit
_ft_isdigit:
	mov rax, 1
	cmp rdi, 49
	jl fail
	cmp rdi, 57
	ja fail
	jl succes

fail:
	mov rax, 0
	jmp end

succes:
	mov rax, 1
	jmp end

end:
	ret