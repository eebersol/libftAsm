global _ft_strlen

section .text

_ft_strlen:  
	cmp rdi, 0 					; Compare with nul asciim
	je end 						; if equal
	sub rcx, rcx 				; on se replace a la bonne adresse
	not rcx 					; on inverse la valeur cela permet de boucler infini avec rpen
	cld 						; clear flag register
	mov rax, 0 					; cdt darret
	repne scasb					; scan bytes of a string until the trailing null character is found 
	not rcx						; on inverse la valeur cela permet de boucler infini avec rpen
	dec rcx 					; decrement by one
	mov rax, rcx				;

end:
	ret
