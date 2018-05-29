global _ft_isascii

section .text

_ft_isascii:
	cmp rdi, 0
	jl fail
	cmp rdi, 127
	jl succes

fail:
	mov rax, 0
	jmp end

succes:
	mov rax, 1
	jmp end

end:
	ret
