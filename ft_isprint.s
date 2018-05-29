global _ft_isprint

section .text

_ft_isprint:
	cmp rdi, 0
	jl fail
	cmp rdi, 127
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
