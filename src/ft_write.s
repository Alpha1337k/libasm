; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_write.s                                         :+:    :+:             ;
;                                                      +:+                     ;
;    By: okruitho <okruitho@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/10/05 12:42:27 by okruitho      #+#    #+#                  ;
;    Updated: 2020/10/05 13:04:38 by okruitho      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

section .text
    global _ft_write

_ft_write:								; fd = rdi, buffer = rsi, bytes = rdx
	mov		rax, 0x2000004
	syscall
	ret