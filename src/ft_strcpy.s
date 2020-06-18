section .text
	global _ft_strcpy

_ft_strcpy:
	xor     RAX , RAX         	; i = 0
    xor     DL  , DL			; c = 0
	jmp     _loop

_increment:
	inc		RAX					; i++

_loop:
	mov		BYTE[RDI + RAX]	, DL
	mov		DL	, BYTE[RSI + RAX]
	cmp		DL	, 0
	jnz		_increment

_return:
    mov     rax, rsi            ; set the return pointer to the dest pointer
	ret							; return rax