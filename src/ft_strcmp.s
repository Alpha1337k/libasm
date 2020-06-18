section .text
	global _ft_strcmp

_ft_strcmp:
		xor RAX	, RAX	; i = 0
		xor DL	, DL	; c = 0
		jmp _loop

_increment:
		inc RAX

_loop:
		mov BYTE[rdi + RAX], DL
		cmp DL, 0
		je  _return_calc
		sub DL, BYTE[rsi + RAX]
		cmp DL, 0
		jne	_return_switch
		jmp _increment

_return_calc:
		sub Dl, BYTE[rsi + RAX]

_return_switch:
		cmp DL, 0
		ja	_return_pos
		js	_return_neg
		jmp	_return_zer

_return_pos:
		mov RAX, 1
		ret

_return_neg:
		mov RAX, -1
		ret

_return_zer:
		mov RAX, 0
		ret
		