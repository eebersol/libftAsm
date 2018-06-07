section .text
	global _ft_strlen

_ft_strlen:  
	cmp rdi, 0 					; On check si \0
	je end 						; if equal
	xor rdx, rdx

loop:
	cmp     byte [rdi + rdx],   0
    je      end
    inc     rdx
    jmp     loop

end:
	mov rax, rdx
	ret