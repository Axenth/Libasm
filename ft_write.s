global  _ft_write
extern ___error

_ft_write:
    mov rax, 0x2000004 ; 0x1 for linux 0x2000004 for mac
    syscall
    jc  error
    ret

error:
	mov 	r10, rax	; save errno
	push 	r10
	call 	___error	; retrieve the address to errno
	mov		[rax], r10	; save errno in the pointer to errno returned by ___error
	pop		r10
	mov		rax, -1		; set return value to -1
	ret