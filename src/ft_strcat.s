section .text
	global _ft_strcat
	extern _ft_strlen

_ft_strcat:	
	mov r8, rdi
	cmp rdi, 0
	je fail
	cmp rsi, 0
	je end

loopDest: 				; mov pointer to dest end
    cmp byte [rdi], 0
    je	loop
    inc rdi
    jmp	loopDest


loop:
	cmp byte [rsi], 0
	je end
	mov rax, [rsi] 		; On move le char [rsi] dans le registre dans rax
	mov [rdi], al 		; On ajoute le caractere de rsi contneu dans les 8 bit de al (plu petit registre de rax)
	inc rsi				; On increment le pointeur sur rsi
	inc rdi				; On increment le compteur r15
	jmp loop

end:
	mov rax, r8			; restore pointer on begin dest
	mov byte [rdi], 0 	; add \0 at the end
	ret

fail:
	ret