section .text
	global _ft_islower

_ft_islower:
	cmp rdi, 97
	jl fail
	cmp rdi, 123
	jl succes

fail:
	mov rax, 0
	jmp end

succes:
	mov rax, 1
	jmp end

end:
	ret