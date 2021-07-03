	global	_ft_strcmp
	section	.text

_ft_strcmp:		mov rax, 0
loop:			mov	bh, byte [rdi + rax]
				mov	dl, byte [rsi + rax]
				sub bh, dl
				cmp bh, 0
				jne diff
				mov	bh, byte [rdi + rax]
				cmp bh, 0
				je equal
				inc rax
				jmp loop

equal:			mov rax, 0
				ret
diff:			mov	bh, byte [rdi + rax]
				mov	dl, byte [rsi + rax]
				sub bh, dl
				cmp dl, 0
				jl less
				mov rax, 1
				ret
less:			mov rax, -1
				ret