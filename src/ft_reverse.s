section .text
	global _ft_reverse
	extern _ft_strlen

_ft_reverse:  
 	
 	mov r12, rdi
 	call _ft_strlen
 	mov rcx, rax

 	mov rax, 0
 	jmp loop

 loop:
 	cmp rcx, 0
 	je end

 	mov al, [rdi]
 	mov [rax], al

 	jmp end
 	inc rax
 	dec rcx
 	dec rdi

 end:
 	mov rax, r12
 	ret