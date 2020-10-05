section .text
	global _ft_strcpy

_ft_strcpy:
	xor     RAX , RAX         	; i = 0
    xor     DL  , DL			; c = 0
	jmp     _loop

_increment:
	inc		RAX					; i++

_loop:
	mov		DL	, BYTE[RSI + RAX]	;
	mov		BYTE[RDI + RAX], DL
	cmp		DL	, 0
	jnz		_increment

_return:
    mov     rax, rdi            ; set the return pointer to the dest pointer
	ret							; return rax