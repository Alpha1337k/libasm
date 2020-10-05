section .text
	global _ft_strcmp

_ft_strcmp:
		xor RAX	, RAX	; i = 0
		xor DL	, DL	; c = 0
		jmp _loop

_increment:
		inc RAX

_loop:
	mov	DL	, BYTE[RDI + RAX]
	cmp DL	, 0
	je	_return_switch
	cmp BYTE[RSI + RAX] , 0
	je	_return_switch
	cmp BYTE[RSI + RAX]	, DL
	je _increment

_return_switch:
	cmp DL	, BYTE[RSI + RAX]
	ja _return_pos
	je _return_zer
	js _return_neg

_return_pos:
		mov RAX, 1
		ret

_return_neg:
		mov RAX, -1
		ret

_return_zer:
		mov RAX, 0
		ret

; section .text
; 	global _ft_strcmp

; _ft_strcmp:
; 		xor RAX	, RAX			; i = 0
; 		xor r10b	, r10b			; a = 0
; 		xor r8b	, r8b			; b = 0
; 		xor r9b	, r9b			; c = 0
; 		; Check if both Variar8bes are NULL
; 		; cmp rdi, 0				;
; 		; jne _loop
; 		; cmp rsi, 0				;
; 		; jne _loop
; 		; jmp _return_zer
; 		jmp _loop

; _increment:						; increment counter
; 		inc RAX

; _loop:							; gets byte, checks if 0 (then continue) or returns
; 		mov BYTE[rdi + RAX], r8b
; 		mov BYTE[rsi + RAX], r9b

; 		mov r8b, r10b
; 		sub r10b, r8b

; 		cmp r8b, 0
; 		je _return_switch
; 		cmp r9b, 0
; 		je _return_switch
; 		cmp r10b, 0
; 		jne _return_switch
; 		jmp _increment

; _return_switch:
; 		cmp r10b, 0
; 		ja	_return_pos
; 		js	_return_neg
; 		jmp	_return_zer

; _return_pos:
; 		mov RAX, 1
; 		ret

; _return_neg:
; 		mov RAX, -1
; 		ret

; _return_zer:
; 		mov RAX, 0
; 		ret
		