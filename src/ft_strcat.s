section .text
	global _ft_strcat
	extern _ft_strlen

_ft_strcat:	
	enter 16, 0
	cmp rdi, 0
	je end
	mov r9, rdi
	push rdi

	call _ft_strlen		; On appelle strlen avec la chaine envoyee
	mov	r15, rax 		; On save la len de rdi
	mov rdi, r9				; On recupere le pointeur sur le debut de rdi
	push rdi			; On resave le pointeur
	mov rax, rdi		; On copy rdi dans rax
	xor rcx, rcx		; On met rcx a 0

loop:
	cmp byte [rsi], 0
	je end
	mov al, [rsi] 		; On move le char [rsi] dans le registre de 8 octet
	mov [rdi + r15], al ; On ajoute le caractere de rsi dans rdi 
	inc rsi				; On increment le pointeur sur rsi
	inc r15				; On increment le compteur r15
	jmp loop

end:
	leave
	ret