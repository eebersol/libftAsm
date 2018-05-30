
PART 1 ::


• bzero		-> OK
• strcat
• isalpha	-> OK
• isdigit	-> OK
• isalnum	-> OK
• isascii	-> OK
• isprint	-> OK
• toupper 	-> OK
• tolower	-> OK
• puts 		-> OK


PART 2 ::

• strlen	-> OK
• memset
• memcpy
• strdup (bien entendu, vous pouvez appeller malloc)

PART 3 ::

• cat








repne scabs :: https://www.aldeid.com/wiki/X86-assembly/Instructions/repne

tuto : http://deamonftp.free.fr/deamoncrack/Pages/cours-asm.htm#6

instruction List :: [.https://www.felixcloutier.com/x86/.m ]


sysCall List :: [http://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/ ]

https://asm.developpez.com/intro/


https://hackademics.fr/forum/d%C3%A9veloppement/applicatif/autres-aj/1218-programmer-en-assembleur-asm-avec-nasm






<!-- 
MY ret : global _ft_strlen

section .text

_ft_strlen:  
	cmp rdi, 0 					; Compare with nul asciim
	je end 						; if equal
	sub rcx, rcx 				; on se replace a la bonne adresse
	not rcx 					; on inverse la valeur cela permet de boucler infini avec rpen
	cld 						; clear flag register
	mov rax, 0 					; cdt darret
	repne scasb					; scan bytes of a string until the trailing null character is found 
	not rcx						; on inverse la valeur cela permet de boucler infini avec rpen
	dec rcx 					; decrement by one
	mov rax, rcx				;

end:
	ret

 -->