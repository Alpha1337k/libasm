; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strcpy.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: okruitho <okruitho@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/10/06 14:27:43 by okruitho      #+#    #+#                  ;
;    Updated: 2020/10/06 14:27:44 by okruitho      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_strcpy

_ft_strcpy:
	xor     RAX , RAX         	; i = 0
    xor     DL  , DL			; c = 0
	jmp     _loop

_increment:
	inc		RAX					; i++

_loop:
	mov		DL	, BYTE[RSI + RAX]	; fetch a byte from src
	mov		BYTE[RDI + RAX], DL		; set a byte of dst
	cmp		DL	, 0					; see if 0
	jnz		_increment				; if not continue

_return:
    mov     rax, rdi            ; set the return pointer to the dest pointer
	ret							; return rax