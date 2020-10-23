global	_ft_strcmp

_ft_strcmp:
	cmp		rdi, 0			; check if first string is NULL
	jz		error			; if null jump to check_null
	cmp		rsi, 0			; check if second string is NULL;
	jz		error			; if null jump to return
	jmp		compare		; jump to compare
increment:
	inc		rdi				; *s1++;
	inc		rsi				; *s2++;
compare:
	movzx	rcx, byte[rdi]		
	movzx	rdx, byte[rsi]
	cmp		rcx, 0
	jz		return
	cmp		rdx, 0
	jz		return
	cmp		rcx, rdx
	je		increment
return:
	sub		rcx, rdx
	mov		rax, rcx
	ret
error:
	mov		rax, 0
	ret