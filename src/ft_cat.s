section .bss
    user_input resb 250

section .text
	global _ft_cat
	extern _ft_memset

_ft_cat:
	cmp rdi, 0
	jl end;
	mov r9, rdi
	jmp loop

loop:
	;prepare buffer
	lea rdi, [rel user_input]		; src 
	mov rsi, 0						; octet
	mov rdx, 250					; size
	call _ft_memset


	mov rax, 0x2000003				; read
	mov rdi, r9						; input
	lea rsi, [rel user_input]		; buffer address
	mov rdx, 250					; buffer size
	syscall 						; execute read

	jc end							; check syscall return
	cmp rax, 0						; check invalid retour sur read a cause dun mauvais fd
	je end

	mov rdx, rax                    ; len
    mov rax, 0x2000004              ; write
    lea rsi, [rel user_input]       ; user_input
    mov rdi, 1                      ; stdout
    syscall							; execute read
   
    jc end							; check syscall return
    cmp rax, 0						; check invalid retour sur read a cause dun mauvais fd
	je end

	jmp loop

end:
	ret