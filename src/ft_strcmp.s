; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strcmp.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: okruitho <okruitho@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/10/06 14:27:51 by okruitho      #+#    #+#                  ;
;    Updated: 2020/10/06 14:27:52 by okruitho      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_strcmp

_ft_strcmp:
		xor RAX	, RAX	; i = 0
		xor DL	, DL	; c = 0
		jmp _loop

_increment:
		inc RAX

_loop:
	mov	DL	, BYTE[RDI + RAX]	; move a byte of s1 into c, than compare it with 0. if so, start returning
	cmp DL	, 0
	je	_return_switch
	cmp BYTE[RSI + RAX] , 0		; same for s2
	je	_return_switch
	cmp BYTE[RSI + RAX]	, DL	; if equal continue
	je _increment

_return_switch:
	cmp DL	, BYTE[RSI + RAX]	; compare s1 and s2
	ja _return_pos				; higher
	je _return_zer				; equal
	jb _return_neg				; lower

_return_pos:
		mov RAX, 1
		ret

_return_neg:
		mov RAX, -1
		ret

_return_zer:
		mov RAX, 0
		ret
