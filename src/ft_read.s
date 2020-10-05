; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_read.s                                          :+:    :+:             ;
;                                                      +:+                     ;
;    By: alpha <alpha@student.codam.nl>               +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/09/27 03:11:41 by alpha         #+#    #+#                  ;
;    Updated: 2020/10/05 17:05:17 by okruitho      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_read
	extern ___error

_ft_read:
	mov rax, 0x2000003
	syscall
	jc _return_error
	ret

_return_error:
	mov	r15, rax
	call ___error
	mov	[rax], r15
	mov RAX, -1
	ret