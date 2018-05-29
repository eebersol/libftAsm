global _ft_tolower

section .text

_ft_tolower:
	mov rax, 1
	cmp rdi, 65
	jl fail
	cmp rdi, 91
	jl succes


fail:
	mov rax, rdi
	jmp end

succes:
	add rdi, 20H
	mov rax, rdi
	jmp end

end:
	ret
