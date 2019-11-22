data segment
str db 'hello china!',13,0Ah,'$'
data ends

stack segment stack
		db 1024 dup(0)
stack ends

code segment
	assume cs:code,ds:data,ss:stack
	
begin:
	   MOV  AX,data
	   MOV  DS,AX
	   mov ax,3
	   ;mov bx,105h
	   int 10h
	   
	   mov ah,2;光标定格在第十行第五列
	   mov bh,0
	   mov dh,10
	   mov dl,5
	   int 10h
	   
	   lea dx,str
	   mov ah,9
	   int 21h
	   
	   mov ah,4ch
	   int 21h
code ends
end begin