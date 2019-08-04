.model small
.stack 100h
.data 
    prompt1 db 13,10,"enter the 1st number: $"
    prompt2 db 13,10,"enter the 2nd number: $"
    promptyes db 13,10,"the second number is less than the first$"
    promptno db 13,10,"the second number is not less than the first$"

.code
   main proc
          mov ax,@data                                
;for moving data to data segment
          mov ds,ax
          
          xor bx,bx                                   
;initially bx value is equal to 0
          mov cl,4      
          
          lea dx, prompt1                             
;show num1 prompt
          mov ah, 9
          int 21h

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
          lea dx, prompt2                             
;show num2 prompt
          mov ah, 9
          int 21h

          xor dx,dx                                   
;set dx value zero

          mov ah,1
          int 21h

      
      input2:
          cmp al,0dh                                  
;compare whether the pressed key is 'enter' or not
          je line2                                    
;if it is equal to 'enter' then stop taking first value
         
          cmp al,39h                                  
;compare the input whether it is letter or digit.39h is the ascii value of 9
          jg letter2
          
          and al,0fh                                  
;if it is digit then convert it's ascii value to real value by masking
          jmp shift2
          
      letter2:                                        
;if it is letter then subtract 37h from it to find it's real value
          sub al,37h
       
      shift2:
          shl dx, cl
          or  dl,al                                   
;making 'or' will add the current value with previous value
            
          int 21h
          jmp input2
      line2:
          xor cx,cx
          mov cx,dx

          mov dh,16
      
      compare_nums:
          cmp bx,cx                                 
;add two number which are stored in bx and cs register
          jg pc1

          lea dx, promptno                           
;show answer prompt
          mov ah, 9
          int 21h  
          jmp exit                                  
;if the register is overflowed then print an extra 1
      
      pc1:
          lea dx, promptyes                           
;show answer prompt
          mov ah, 9
          int 21h
      
      exit:
          mov ah, 4ch                               
;return control to dos
          int 21h
        
    main endp
   end main
