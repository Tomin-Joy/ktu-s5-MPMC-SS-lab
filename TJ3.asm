ASSUME CS:CODE,DS:DATA
DATA SEGMENT
MSG1 DB 0ah,'Enter No 1: $'
MSG2 DB 0ah,'Enter No 1: $'
msg3 db 0ah,'The sum is : $'
data ends
code segment
start: mov ax,data
	mov ds,ax
	mov dx,offset msg1
	mov ah,09h
	int 21h
	MOV AH,01H
	INT 21H
	SUB AL,30H
	MOV BH,0aH
	MUL BH
	MOV BH,AL
	MOV AH,01H
	INT 21H
	SUB AL,30H
	ADD BH,AL
	mov BL,BH
	mov dx,offset msg2
	mov ah,09h
	int 21h
	MOV AH,01H
	INT 21H
	SUB AL,30H
	MOV BH,0aH
	MUL BH
	MOV BH,AL
	MOV AH,01H
	INT 21H
	SUB AL,30H
	ADD BH,AL
	ADD BH,BL
	mov dx,offset msg3
	mov ah,09h
	int 21h
	MOV CL,0AH
	MOV AL,BH
	MOV AH,00H
	DIV CL
	ADD AL,30H
	MOV DL,AL
	MOV BL,AH
	MOV AH,02H
	INT 21H
	ADD BL,30H
	MOV DL,BL
	MOV AH,02H
	INT 21H
	MOV AH,4CH
	INT 21H
    code ends
end start