section .text
	global _ft_tolower

_ft_tolower:
	cmp rdi, 65
	jl fail
	cmp rdi, 91
	jl succes

fail:
	mov rax, rdi
	jmp end

succes:
	add rdi, 20H ; increment rdi pour passer le char en maj
	mov rax, rdi
	jmp end

end:
	ret