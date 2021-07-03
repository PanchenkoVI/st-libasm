	global	_ft_strcpy
	section	.text

_ft_strcpy:		mov rax, 0
loop:			mov cl, byte [rsi + rax]
				mov byte [rdi + rax], cl
				cmp cl, 0
				je end;
				inc rax
				jmp loop

end:			mov rax, rdi
				ret