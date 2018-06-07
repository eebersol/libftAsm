section .text
	global _ft_isascii

_ft_isascii:
	cmp rdi, 0		; Je compare le debut de la table ascii
	jl fail
	cmp rdi, 128 	; Je compare avec le fin de la table ascii
	jl succes

fail:
	mov rax, 0
	jmp end

succes:
	mov rax, 1
	jmp end

end:
	ret