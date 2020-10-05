section .text
	global _ft_strcmp

_ft_strcmp:
		xor RAX	, RAX	; i = 0
		xor DL	, DL	; c = 0
		jmp _loop

_increment:
		inc RAX

_loop:
	mov	DL	, BYTE[RDI + RAX]
	cmp DL	, 0
	je	_return_switch
	cmp BYTE[RSI + RAX] , 0
	je	_return_switch
	cmp BYTE[RSI + RAX]	, DL
	je _increment

_return_switch:
	cmp DL	, BYTE[RSI + RAX]
	ja _return_pos
	je _return_zer
	jb _return_neg

_return_pos:
		mov RAX, 1
		ret

_return_neg:
		mov RAX, -1
		ret

_return_zer:
		mov RAX, 0
		ret
