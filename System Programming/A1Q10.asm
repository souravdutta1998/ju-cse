.model small
.stack 100h

.data
space db ' '
.code

main proc
	
	mov ax,@data
	mov ds,ax

	mov bx,65
	mov cx,0

	label1:
		;print the character 
		mov ah,02h
		mov dl,bl
		int 21h

		;print the character 
		mov ah,02h
		mov dl,space
		int 21h

		;increment
		inc bx
		inc cx
		cmp cx,26
		
	jne label1

	mov ah,4ch
	int 21h

main endp

end main
