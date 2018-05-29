global _ft_strlen

section .text

_ft_strlen:  
	cmp rdi, 0 					; Compare with nul asciim
	je end 						; if equal
	sub rcx, rcx 				; on se replace a la bonne adresse
	not rcx 					; on 'reverse' la string
	cld 						; clear flag register
	mov rax, 0 					;
	repne scasb					; scan bytes of a string until the trailing null character is found 
	not rcx						; on 'reverse' la string
	dec rcx 					; decrement by one
	mov rax, rcx				;

end:
	ret


