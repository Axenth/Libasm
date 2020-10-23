global	_ft_read
extern ___error

_ft_read:							
	mov		rax, 0x2000003  ; 0x2000003 for mac  0x0 for linux
	syscall					; Make the system call to read
	jc error				; Jump if carry to error 
	ret

error:
	mov 	r10, rax	; save errno
	push 	r10
	call 	___error	; retrieve the address to errno
	mov		[rax], r10	; save errno in the pointer to errno returned by ___error
	pop		r10
	mov		rax, -1		; set return value to -1
	ret