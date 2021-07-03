	global 	_ft_strdup
	section	.text
	extern	_malloc
	extern	_ft_strcpy

_ft_strdup:		mov rax, 0

first:		cmp byte [rdi + rax], 0
			jz next
			inc rax
			jmp first
				
next:		inc rax
			push rdi
			mov rdi, rax
			call _malloc
			pop	rdi
			cmp rdi, 0
			je error
			mov rsi, rdi
			mov rdi, rax
			call _ft_strcpy
			ret

error:		mov rax, 0
			ret