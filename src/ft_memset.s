section .text
	global _ft_memset


_ft_memset:
	mov r8, rdi		; store start pointer
	cmp rdx, 0		; check len
	je done
	
	mov rax, rsi 	; Value a modifier
	mov rcx, rdx	; nombre d iteration
	cld				; type diteration
	rep stosb		; iteration

done:
	mov rax, r8 	; restore start pointer
	ret