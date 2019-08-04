.model small
.stack 100h

.data
msg1 db 10,13,"Enter a character: $"
msg2 db 10,13,"The character is: $"

.code

main proc
	
	mov ax,@data
	mov ds,ax

	;display input prompt
	lea dx,msg1
	mov ah,09h
	int 21h

	;accept a character
	mov ah,01h
	int 21h

	;al has the character
	;display prompt
	lea dx,msg2
	mov ah,09h
	int 21h

	;display the character
	mov dl,al
	mov ah,02h
	int 21h

	mov ah,4ch
	int 21h

main endp
end main
