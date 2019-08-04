.MODEL SMALL
.STACK 100H

.DATA
MSG1 DB 10,13,"ENTER A CHARACTER: $"
MSG2 DB 10,13,"LOWERCASE CHARACTER: $"

.CODE

MAIN PROC
        MOV AX, @DATA
        MOV DS, AX

        ;DISPLAY INPUT PROMPT
        LEA DX, MSG1
        MOV AH, 09H
        INT 21H

        ;ACCEPT A CHARACTER
        MOV AH, 01H
        INT 21H

        ;AL HAS THE CHARACTER

        ;CHECK IF AL IS UPPERCASE
        CMP AL, 'A'
        JL DISPLAY

        CMP AL, 'Z'
        JG DISPLAY

        ADD AL, 32

        DISPLAY:
        ;DISPLAY PROMPT
        LEA DX, MSG2
        MOV AH, 09H
        INT 21H

        ;DISPLAY THE CHARACTER
        MOV DL, AL
        MOV AH, 02H
        INT 21H

        MOV AH, 4CH
        INT 21H

MAIN ENDP
END MAIN
