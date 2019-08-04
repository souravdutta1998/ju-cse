.model small
.stack 300h
.data
msg1 db 0AH,0DH,'Enter number: $'
msg2 db 0AH,0DH,'Number is prime $ '
msg3 db 0AH,0DH,'Number is not prime $'
endl db 0AH,0DH,'$'
val db ?

.code
print macro msg
	push ax
	push dx
	mov ah, 09h
	lea dx, msg
	int 21h
	pop dx
	pop ax
endm

main proc
	mov ax,@data
	mov ds,ax
	
	start:
	
	print msg1
	
	call readnum
	
	mov val, al
	
	cmp al,01h
	jz notp
	cmp al,02h
	jz isp
	
	mov cl, 02h
	mov bl, 00h
	loop1:
		mov al, val
		mov ah,00h
		div cl
		cmp ah, 00h
		jz notp
		inc cl
		cmp cl, val
	jnz loop1
		
	isp:	
	print msg2
	
	jmp EXIT
	
	notp:
	print msg3   
    exit:
    mov ah, 4ch
    int 21h
main endp
readnum proc near
	; this procedure will take a number as input from user and store in AL
	; input : none
	
	; output : AL

	
	push bx
	push cx
	mov cx,0ah
	mov bx,00h
	loopnum: 
		mov ah,01h
		int 21h
		cmp al,'0'
		jb skip
		cmp al,'9'
		ja skip
		sub al,'0'
		push ax
		mov ax,bx
		mul cx
		mov bx,ax
		pop ax
		mov ah,00h
		add bx,ax
	jmp loopnum
	
	skip:
	mov ax,bx
	pop cx
	pop bx
	ret
readnum endp

end main
