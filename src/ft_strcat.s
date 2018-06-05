section .text
	global _ft_strcat
	extern _ft_strlen

_ft_strcat:	
	enter 16, 0
	push rdi

	call _ft_strlen		;on appelle strlen avec la chaine envoyee
	mov	r15, rax 		; On save la len de rdi
	pop rdi				; On recupere le pointeur sur le debut de rdi
	push rdi			; On resave le pointeur
	mov rax, rdi		; On copy rdi dans rax
	xor rcx, rcx		; on met rcx a 0

loop:
		mov al, [rsi] 	; On move le char [rsi] dans le registre d e8 octet
		cmp al, 0		; on verifie chaque bite de src voir si cest la fin de la string
		je end
		mov [rdi + r15], al ; On ajoute le caractere de rsi dans rdi 
		inc rsi	
		inc r15
		jmp loop

end:
		leave
		ret