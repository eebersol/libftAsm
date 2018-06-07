section .text
	global _ft_isalnum

_ft_isalnum:
	cmp rdi, 122		; Je compare le char avec 'z'
	ja fail
	cmp rdi, 97			; Je compare le char avec 'a'
	jl check_alpha
	jae succes

check_alpha:
	cmp rdi, 90			; Je compare le char avec 'Z'
	ja fail
	cmp rdi, 65			; Je compare le char avec 'A'
	jl check_digit
	jmp succes

check_digit:
	cmp rdi, 57 		; Je compare le char avec '9'
	ja fail
	cmp rdi , 48		; Je compare le char avec '0'
	jl fail
	jmp succes
	
fail:
	mov rax, 0
	jmp end

succes:
	mov rax, 1
	jmp end

end:
	ret