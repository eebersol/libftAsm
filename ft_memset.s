section .text
	global _ft_memset


_ft_memset:
	cmp rdx, 0		; check len
	je done
	mov r8, rdi		; store pointer
	mov rax, rsi 	; Value a comparer
	mov rcx, rdx	; nombre d iteration
	cld				; type diteration
	rep stosb		; iteration

done:
	mov rax, r8 	; restore pointer
	ret

	    mov rax, [r10+ rcx]    ; Value a comparer
    mov rcx, r8            ; nombre d iteration
    cld                    ; type diteration
    rep stosb              ; iteratio



    	mov rdi, rax    ; malloc s first (and only) parameter: number of bytes to allocate
    extern _malloc
    call _malloc    ; on return, rax points to our newly-allocat