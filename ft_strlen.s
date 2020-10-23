global	_ft_strlen

_ft_strlen:
	xor		rax, rax			; set return value & counter to 0
	cmp		rdi, 0
	jz		done
	jmp		compare				; jump to compare
increment:
	inc		rax					; increment return value & counter		
compare:
	cmp		BYTE [rdi + rax], 0 ; check if the character is the null terminating character
	jne		increment			; if its not the null terminating character increment
done:
	ret							; return rax