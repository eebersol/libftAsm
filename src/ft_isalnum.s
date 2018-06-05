section .text
	global _ft_isalnum

_ft_isalnum:
	cmp rdi, 122
	ja fail
	cmp rdi, 97
	jl check_lower
	jae succes

check_lower:
	cmp rdi, 90
	ja fail
	cmp rdi, 65
	jl check_digit
	jae succes

check_digit:
	cmp rdi, 57
	ja fail
	cmp rdi , 49
	jl fail
	jae succes
	
fail:
	mov rax, 0
	jmp end

succes:
	mov rax, 1
	jmp end

end:
	ret