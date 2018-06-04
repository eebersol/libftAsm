
global _ft_cat

section .text

_ft_cat:
	xor rax, rax 		; rax <- 0 (write syscall number)
	xor rdi, rdi 		; rdi <- 0 (stdin file descriptor)
	mov rsi, rsi 		; rsi <- address of the buffer
	mov rdx, 100 		; rdx <- size of the buffer
	syscall 			; execute
	ret