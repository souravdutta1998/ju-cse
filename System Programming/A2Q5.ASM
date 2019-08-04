.MODEL SMALL
.STACK 1000h

.DATA
  HEX_Map   DB  '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
  HEX_Out   DB  "00", 13, 10, '$'   ; string with line feed and '$'-terminator

msg1 db 0AH,0DH,'Enter binary number: $'
msg2 db 0AH,0DH,'Hexadecimal: $'
msg3 db 0AH,0DH,'Enter hexadecimal number: $'
msg4 db 0AH,0DH,'Binary: $'

space db ' $'
endl db 0AH,0DH,'$'
binno db 17
	  db ?
	  db 17 dup(0)

str1 db 20 dup('$')
str2 db 20 dup('$')

.code

val1 dw ?
val2 dw ?


.CODE

print macro msg
	push ax
	push dx
	mov ah, 09h
	lea dx, msg
	int 21h
	pop dx
	pop ax
endm
read macro memloc
	push ax
	push cx
	push dx
	mov ah, 0ah
	lea dx, memloc
	int 21h
	lea si, memloc + 1 ;NUMBER OF CHARACTERS ENTERED.
	mov cl, [si] ;MOVE LENGTH TO CL.
	mov ch, 0      ;CLEAR CH TO USE CX. 
	inc cx ;TO REACH CHR(13).
	add si, cx ;NOW SI POINTS TO CHR(13).
	mov al, '$'
	mov [si], al ;REPLACE CHR(13) BY '$'.            
	
	pop dx
	pop cx
	pop ax
endm


main PROC
    mov ax, @DATA                   ; Initialize DS
    mov ds, ax

print msg1
	
	read binno; bin no strored in binno
	
	print  msg2
	mov ax,0000h
	mov bx,0000h
	lea si, binno + 1
	mov cl, [si]
	mov ch, 00h
	inc  si
	;add si, cx
	mov ax,cx
	;call writenum
	;print endl
	mov ax,00h
	
	loop1:
		mov bl, [si]
		sub bl, '0'
		mov bh, 00h
		mov dx,02h
		mul dx
		add ax, bx
		;call writenum
		;print endl
		inc si
	loop loop1
	


    ; Example No. 1 with output
    mov di, OFFSET HEX_Out          ; First argument: pointer
    ;mov ax, 10101100b               ; Second argument: Integer
    call IntegerToHexFromMap        ; Call with arguments
    mov ah, 09h                     ; Int 21h / 09h: Write string to STDOUT
    mov dx, OFFSET HEX_Out          ; Pointer to '$'-terminated string
    int 21h                         ; Call MS-DOS

    
    mov ax, 4C00h                   ; Int 21h / 4Ch: Terminate program (Exit code = 00h)
    int 21h                         ; Call MS-DOS
main ENDP

IntegerToHexFromMap PROC
    mov si, OFFSET Hex_Map          ; Pointer to hex-character table

    mov bx, ax                      ; BX = argument AX
    and bx, 00FFh                   ; Clear BH (just to be on the safe side)
    shr bx, 1                       ; Isolate high nibble (i.e. 4 bits)
    SHR BX,1
    SHR BX,1
    SHR BX,1
    mov dl, [si+bx]                 ; Read hex-character from the table
    mov [di+0], dl                  ; Store character at the first place in the output string

    mov bx, ax                      ; BX = argument AX (just to be on the safe side)
    and bx, 00FFh                   ; Clear BH (just to be on the safe side)
    and bl, 0Fh                     ; Isolate low nibble (i.e. 4 bits)
    mov dl, [si+bx]                 ; Read hex-character from the table
    mov [di+1], dl                  ; Store character at the second place in the output string

    ret
IntegerToHexFromMap ENDP

readnum proc near
	; this procedure will take a number as input from user and store in AX
	; input : none
	
	; output : AX

	
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


END main                            ; End of assembly with entry-procedure
