; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strdup.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: okruitho <okruitho@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/10/05 13:16:50 by okruitho      #+#    #+#                  ;
;    Updated: 2020/10/05 14:35:46 by okruitho      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy

_ft_strdup:
	push r12
	xor RAX, RAX    ; strlen
	xor DL, DL      ; index

_ft_allocate:
	call _ft_strlen
	mov r12, RDI
	mov RDI, RAX
	inc RDI
	call _malloc
	cmp RAX, 0
	je _return_null

_start_cpy:
	mov RDI, RAX
	mov RSI, r12
	call _ft_strcpy

_return:
	mov rax, rdi
	pop r12
	ret

_return_null:
	xor RAX,RAX
	pop r12
	ret
