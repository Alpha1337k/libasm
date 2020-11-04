; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strdup.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: okruitho <okruitho@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/10/05 13:16:50 by okruitho      #+#    #+#                  ;
;    Updated: 2020/10/06 14:25:09 by okruitho      ########   odam.nl          ;
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
	call _ft_strlen	; fetch strlen
	mov r12, RDI	; set the src pointer into r12, to preserve it
	mov RDI, RAX	; set the strlen as argument for malloc
	inc RDI			; null byte
	call _malloc	
	cmp RAX, 0		; malloc check
	je _return_null

_start_cpy:
	mov RDI, RAX	; get the src pointer back and start copying
	mov RSI, r12
	call _ft_strcpy

_return:
	mov rax, rdi	; return the new pointer and pop the stack
	pop r12
	ret

_return_null:		; malloc error return
	xor RAX,RAX
	pop r12
	ret
