.model small
.stack 300h
.data
array1 db 50 dup(0)
msg4 db 0AH,0DH,'Enter size of the array: $'
msg1 db 0AH,0DH,'Enter number to be searched: $'
msg2 db 0AH,0DH,'FOUND AT POSITION $ '
msg3 db 0AH,0DH,'NOT FOUND$'
endl db 0AH,0DH,'$'
se db 00h
count db 00H

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

	print msg4
	call readnum
	mov count, al
	mov cl, count
	mov bx, 00h
	rdnxt:
		print endl
		call readnum
		mov array1[bx],al
		inc bx
	loop rdnxt
	
	mov cl, count
	print msg1
	call readnum
	mov se,al
	mov al,se
	mov ah,00h
	lea si, array1
	mov ch, count
	mov cl, 00h
	;mov cl, COUNT
	;sar cl
	loop1:
		;MOV BL,[SI]
		cmp cl, ch
		ja nfo
		mov bl, cl
		mov bh, 00h
		add bl, ch
		sar bl, 1
		mov bh, 00h
		cmp al, array1[bx]
		jz fo
		ja upcall
		downcall:
		mov ch, bl
		dec ch
		jmp loop1
		upcall:
		mov cl, bl
		inc cl
		jmp loop1
	
	
	nfo:
	print msg3
	jmp end1
 
	fo:
	print msg2
	mov al, bl
	call writenum
 
end1:
	mov ah, 4ch
	int 21h

main endp

print_array proc near
	; this procedure will print the elements of a given array
	; input : SI=offset address of the array
	;       : BX=size of the array
	; output : none

	push ax                        
	push cx                        
	push dx                        
	push si
	mov cx, bx                     

	@print_array:                  
		xor ah,ah                  
		mov al, [si]               

		call writenum              

		mov ah, 2                  
		mov dl, 20h                
		int 21h                    

		inc si                     
	loop @print_array              

	pop si
	pop dx                         
	pop cx                         
	pop ax                         

	ret                            
print_array endp


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

writenum proc near
	; this procedure will display a decimal number
	; input : AX
	; output : none

	push bx                        
	push cx                        
	push dx                        

	xor cx, cx
	mov bx, 0ah                     

	@output:                       
		xor dx, dx                   
		div bx                       ; divide AX by BX
		push dx                      ; push remainder onto the STACK
		inc cx                       
		or ax, ax                    
	jne @output                    

	mov ah, 02h                      ; set output function

	@display:                      
		pop dx                       ; pop a value(remainder) from STACK to DX
		or dl, 30h                   ; convert decimal to ascii code
		int 21h                      
	loop @display                  

	pop dx                         
	pop cx                         
	pop bx                         

	ret                            
writenum endp
	
end main
