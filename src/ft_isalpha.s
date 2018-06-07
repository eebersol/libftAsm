section .text
	global _ft_isalpha

_ft_isalpha:
	cmp rdi, 65		; Je compare le char avec 'A'
	jl fail
	cmp rdi, 90 	; Je compare le char avec 'Z'
	ja check_lower
	jmp succes

check_lower:
	cmp rdi, 97		; Je compare le char avec 'a'
	jl fail
	cmp rdi, 123 	; Je compare le char avec 'z'
	jl succes

fail:
	mov rax, 0
	jmp end

succes:
	mov rax, 1
	jmp end

end:
	ret