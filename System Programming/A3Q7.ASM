.model small  
.stack 100h
.data        
 	;a dw 1234H  
 	;b dw 0100H
	msg1 db 0AH,0DH,'Enter first 16 bit hex number: $'
	msg2 db 0AH,0Dh,'Enter second 16 bit hex number: $'
	msg3 db 0AH,0DH,'Result after multiplying: $'  
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
      	mov      ax, @data      ; Initialize data section  
      	mov      ds, ax  
      
	print msg1
	call readhex          
      	mov cx, ax
	
	print msg2
	call readhex

	print msg3
	
	mov bx, ax          ; Load number2 in bx  
	mov ax, cx	    ; Load number1 in ax      	
	mul bx             ; multiply numbers. Result in dx and ax  
      	mov si, ax  
      	mov bx, dx         ; Result in reg bx  
      	mov dh, 2  
l1:     mov ch, 04h     ; Count of digits to be displayed  
      	mov cl, 04h        ; Count to roll by 4 bits    
l2:     rol bx, cl          ; roll bl so that msb comes to lsb   
      	mov dl, bl         ; load dl wth data to be displayed  
      	and dl, 0fH        ; get only lsb  
      	cmp dl, 09         ; check if digit is 0-9 or letter A-F  
      	jbe l4  
      	add dl, 07         ; if letter add 37H else only add 30H  
l4:     add dl, 30H  
      	mov ah, 02         ; Function 2 under INT 21H (Display character)  
      	int 21H  
      	dec ch             ; Decrement Count  
      	jnz l2  
      	dec dh  
      	cmp dh, 0  
      	mov bx, si       
      	jnz l1  
      	
	mov ah, 4cH        ; Terminate Program  
      	int 21H  
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


end main
