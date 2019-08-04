.model small
.stack 100h

.data
msg db 10,13,"Enter q to quit any other key to continue looping: $"
looping db 10,13,"loop$"

.code

main proc

	mov ax,@data
	mov ds,ax

	label1:

		;display loop message
		lea dx,looping
		mov ah,09h
		int 21h

		;display input prompt
		lea dx,msg
		mov ah,09h
		int 21h

		;accept a character
		mov ah,01h
		int 21h

		; check if character is q
		cmp al,'q'
		jne label1

	;exit
	mov ah,4Ch
	int 21h
main endp
end main
