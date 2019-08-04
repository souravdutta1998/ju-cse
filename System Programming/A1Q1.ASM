.MODEL SMALL
.STACK 100H

.DATA
        NAME1 DB "Name: Sourav Dutta$"
        PROGTITLE DB "Program title: a1q1.asm$"
.CODE
        MOV AX, @DATA
        MOV DS, AX

        ;DISPLAY THE NAME
        LEA DX, NAME1
        MOV AH, 09H
        INT 21H

        ;CARRIAGE RETURN
        MOV AH, 02H
        MOV DL, 0DH
        INT 21H

        ;LINE FEED
        MOV DL, 0AH
        INT 21H

        ;DISPLAY PROGRAM TITLE
        LEA DX, PROGTITLE
        MOV AH, 09H
        INT 21H

        ;EXIT
        MOV AH, 4CH
        INT 21H
END
