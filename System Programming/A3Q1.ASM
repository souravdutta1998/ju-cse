.model small
.stack 100h
.data
	msg1 db 0AH,0DH,'Enter a hexadecimal number: $'
	msg2 db 0AH,0DH,'Decimal equivalent is : $'
	;num dw 1234h
	res db 10 dup('$')
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
	mov ax, @data
	mov ds, ax
	
	print msg1
	;mov ax, num
	call readhex

	print msg2
	call writenum
	
exit:
	mov ah,4ch
	int 21h
main endp

readhex proc near
	; this will input a 16 bit hexadecimal number
	; output : AX
	
	push bx
	push cx
	push dx

	xor bx,bx                                   
;initially bx value is equal to 0
          mov cl,4 
	mov ah,1                                    
;for taking input
          int 21h
      
      
      input1:
          cmp al,0dh                                  
;compare whether the pressed key is 'enter' or not
          je line1                                    
;if it is equal to 'enter' then stop taking first value
         
          cmp al,39h                                  
;compare the input whether it is letter or digit.39h is the ascii value of 9
          jg letter1
          
          and al,0fh                                  
;if it is digit then convert it's ascii value to real value by masking
          jmp shift1
          
      letter1:                                        
;if it is letter then subtract 37h from it to find it's real value
          sub al,37h
       
      shift1:
          shl bx, cl
          or  bl,al                                   
;making 'or' will add the current value with previous value
          
          int 21h
          jmp input1
line1:
	mov ax, bx

	pop dx
	pop cx
	pop bx
	ret
readhex endp

writenum proc near
	; this procedure will display a decimal number
	; input : AX
	; output : none

	push ax
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
	pop ax

	ret                            
writenum endp

end main
