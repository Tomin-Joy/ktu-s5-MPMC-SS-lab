ASSUME CS:CODE,DS:DATA
DATA SEGMENT
MSG1 DB 0ah,'Enter No : $'
msg2 db 0ah,'The number is : $'
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
	mov dx,offset msg2
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