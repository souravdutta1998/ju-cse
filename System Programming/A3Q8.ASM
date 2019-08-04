print macro msg
      lea dx,msg
      mov ah,09h
      int 21h
      endm
      read macro n,j1,j2
      j1: mov ah,01h
          int 21h
          cmp al,0dh
          je j2
          sub al,30h
          mov bl,al
          mov ax,n
          mov dx,0ah
          mul dx
          xor bh,bh
          add ax,bx
          mov n,ax
          jmp j1
      j2: nop
      endm
     printmul macro n1,l2,l3
                mov bx,000ah
                mov ax,n1
                xor cx,cx
           l2: xor dx,dx
               div bx
               push dx
               inc cx
               cmp ax,0000h
               jne l2
           l3: pop dx
               add dl,30h
               mov ah,02h
               int 21h
               loop l3
           endm
.model small
.stack 100h
.data
        num dw 100 dup(0)
        n dw 0 
        m dw 0
        msg1 db 10,13,'Enter the no of elements:$'
        msg2 db 10,13,'Enter an element:$'
        msg3 db 10,13,'Original array:$'
        msg4 db '  $'    
        msg6 db 10,13,' $'

.code
      main proc
                mov ax,@data
                mov  ds,ax
                print msg1
               read n,jump1,jump2
                mov cx,n
                mov ax,n
                dec ax
                mov m,ax
                mov si,0000h
            loop1:      print msg2
                        read num[si],jump3,jump4
                        add si,02h
                        loop loop1
            print msg3
            call display   
            print msg6
            mov si,0000h
            xor cx,cx
            outerloop:  mov ax,num[si]
                        mov di,si
                        push cx
                        push si   
                        mov si,di
                        innerloop:  
                                     add si,02h
                                     cmp ax,num[si]
                                     jl check
                                     mov ax,num[si]  
                                     mov di,si   
                                     
                             check:  inc cx
                                     cmp cx,m
                                     jl innerloop
                        pop si
                        pop cx
                        mov bx,num[si]
                        mov num[di],bx
                        mov num[si],ax
                        push cx
                        push si
                        call display 
                        print msg6
                        pop si
                        pop cx
                        add si,02h
                        inc cx
                        cmp cx,m
                        jl outerloop
                        mov ah,4ch
                        int 21h
            main endp
            display proc
                        mov cx,n
                        mov si,00h
                        l4: push cx
                            print msg4
                            printmul num[si],l5,l6
                            add si,02h
                            pop cx
                            loop l4
                            ret
           display endp
   end
