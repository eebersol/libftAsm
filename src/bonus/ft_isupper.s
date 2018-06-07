section .text
	global _ft_isupper

_ft_isupper:
	cmp rdi, 65
	jl fail
	cmp rdi, 91
	jl succes

fail:
	mov rax, 0
	jmp end

succes:
	mov rax, 1
	jmp end

end:
	ret