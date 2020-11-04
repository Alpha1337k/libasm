; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strlen.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: okruitho <okruitho@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/10/06 14:27:31 by okruitho      #+#    #+#                  ;
;    Updated: 2020/10/06 14:27:33 by okruitho      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_strlen

_ft_strlen:
	xor     RAX,RAX         	; i = 0
	cmp		rdi,0
	je		_return
	jmp     _loop

_increment:
	inc		RAX					; i++

_loop:
	cmp		BYTE[rdi + rax], 0	; s[i] == 0
	jne		_increment			; false = increment

_return:
	ret							; return rax