section .text
	global _ft_isdigit

_ft_isdigit:
	cmp rdi, 48	; Je compare le char avec 0
	jl fail
	cmp rdi, 58 ; Je compare le char avec 9
	jl succes

fail:
	mov rax, 0
	jmp end

succes:
	mov rax, 1
	jmp end

end:
	ret