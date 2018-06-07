section .text
	global _ft_memset


_ft_memset:
	cmp rdx, 0		; check len
	je done
	mov r8, rdi		; store start pointer
	
	mov rax, rsi 	; Value a modifier
	mov rcx, rdx	; nombre d iteration
	cld				; type diteration
	rep stosb		; iteration

done:
	mov rax, r8 	; restore start pointer
	ret
