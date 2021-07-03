	global	_ft_write
	section	.text
	extern	___error

_ft_write:	mov rax, 0x2000004
			syscall
			jc exit
			ret

exit:		push rax
			call ___error
			pop r8
			mov [rax], r8
			mov rax, -1
			ret