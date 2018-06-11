section .text
	global _ft_strlen

_ft_strlen:  
    cmp rdi, 0                  ; Compare with null ascii
    je end                      ; if equal stop

    xor rcx, rcx                ; init rcx at 0
    xor rax, rax                ; init rax at 0

    not rcx                     ; on reverse le compteur permet quil soit negatif et donc pas pris en compte pas rep
    repne scasb                 ; scan bytes of a string until the trailing null character is found 

    not rcx                     ; on remet le compteur dans son ordre de base
    dec rcx                     ; decrement le compteur pour le \0
    mov rax, rcx                ; on place la valeur trouve dans rax

end:
    ret