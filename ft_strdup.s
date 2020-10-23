global _ft_strdup
extern _malloc
extern _ft_strcpy
extern _ft_strlen

_ft_strdup:
	cmp		rdi, 0 		; check if string is null
	jz		error 		; if null jump to error
	call 	_ft_strlen	; get string length and store it in rax
	inc 	rax			; rax++
	push 	rdi			; save rdi
	mov 	rdi, rax	; move rax into rdi
	call 	_malloc		; call malloc with value of rdi
	cmp 	rax, 0x0	; if malloc failes return 0
	pop 	rdi			; restore rdi
	jz		error		; if null jump to error
	push 	rsi			; save rsi
	mov 	rsi, rdi	; move string into rsi
	mov 	rdi, rax	; move the malloced area into rdi
	call 	_ft_strcpy	; copy over the string
	pop 	rsi			; remove rsi
	jmp 	done		; jump to done
error:
	xor 	rax, rax	; set return value to 0
done:
	ret					; return rax