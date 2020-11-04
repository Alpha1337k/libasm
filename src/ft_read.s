; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_read.s                                          :+:    :+:             ;
;                                                      +:+                     ;
;    By: alpha <alpha@student.codam.nl>               +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/09/27 03:11:41 by alpha         #+#    #+#                  ;
;    Updated: 2020/10/06 14:26:57 by okruitho      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_read
	extern ___error

_ft_read:									; same code as write dummy
	mov rax, 0x2000003
	syscall
	jc _return_error
	ret

_return_error:
	push rax
	call ___error
	pop r15
	mov	[rax], r15
	mov RAX, -1
	ret