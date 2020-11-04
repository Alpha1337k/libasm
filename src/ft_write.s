; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_write.s                                         :+:    :+:             ;
;                                                      +:+                     ;
;    By: okruitho <okruitho@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/10/05 12:42:27 by okruitho      #+#    #+#                  ;
;    Updated: 2020/10/06 14:26:26 by okruitho      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

section .text
    global _ft_write
	extern ___error

_ft_write:						; sycall for write all variables are already alligned
	mov		rax, 0x2000004
	syscall
	jc _return_error			; jc is a error flag, if true _return_error
	ret

_return_error:					; push rax (return syscall) for stack alignment and call errno
	push rax
	call ___error
	pop	r15
	mov	[rax], r15				; pop en set return naar -1
	mov RAX, -1
	ret