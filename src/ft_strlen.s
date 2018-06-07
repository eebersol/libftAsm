section .text
	global _ft_strlen

_ft_strlen:  
	cmp rdi, 0 					; On check si \0
	je end 						; if equal

	xor rax, rax 				; clear rax register
	xor rcx, rcx 				; clear rcx register

	not rcx 					; inverse la value de rcx
	cld 						;
	repne scasb					; scan bytes of a string until the null character is found 
	not rcx						; reverse la value de rcx
	dec rcx 					; decrement by one pour se mettre sur le \0
	mov rax, rcx				;

end:
	ret