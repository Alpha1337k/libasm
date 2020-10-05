; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_write.s                                         :+:    :+:             ;
;                                                      +:+                     ;
;    By: okruitho <okruitho@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/10/05 12:42:27 by okruitho      #+#    #+#                  ;
;    Updated: 2020/10/05 17:05:51 by okruitho      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

section .text
    global _ft_write
	extern ___error

_ft_write:								; fd = rdi, buffer = rsi, bytes = rdx
	mov		rax, 0x2000004
	syscall
	jc _return_error
	ret

_return_error:
	mov	r15, rax
	call ___error
	mov	[rax], r15
	mov RAX, -1
	ret