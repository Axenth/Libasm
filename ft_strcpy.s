global _ft_strcpy

_ft_strcpy:
	cmp		rsi, 0				 ; check if src is null
	jz		error				 ; if null return 0
	cmp		rdi, 0				 ; check if dst is null
	jz		error				 ; if null return 0
	mov		rdx, 0				 ; set cmp to 0
	mov		rcx, 0				 ; set counter to 0
	jmp		loop				 ; jump to loop
increment:
	inc 	rcx					 ; i++
loop:		
	mov		dl, BYTE [rsi + rcx] ; move character from src to tmp
	mov		BYTE [rdi + rcx], dl ; move character from tmp to dst
	cmp		dl, 0				 ; check if null character is found
	jnz		increment			 ; if not found jump to increment
done:
	mov		rax, rdi			 ; move dest pointer into rax
	ret							 ; return rax
error:
	mov		rax, 0
	ret