section .text
	global _ft_memcpy
	extern _ft_strlen


_ft_strdup:

	mov r10, rdi
	call _ft_strlen

	mov rdi, rax 	; malloc s first (and only) parameter: number of bytes to allocate
	extern malloc
	call malloc 	; on return, rax points to our newly-allocated memory
	ret

