	global	_ft_strlen
	section	.text

_ft_strlen:		mov rax, 0
step:			cmp byte [rdi + rax], 0
				je exit
				inc rax
				jmp step

exit:			ret