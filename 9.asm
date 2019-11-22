data segment
str db 20,?,20 dup(?)
data ends

stack segment stack
		db 1024 dup(0)
stack ends

code segment
	assume cs:code,ds:data,ss:stack
	
begin:
	   MOV  AX,data
	   MOV  DS,AX
	   
	   lea dx,str
	   mov ah,0Ah
	   int 21h
	   
	   mov dl,0Dh
	   mov ah,2
	   int 21h
	   
	   mov bh,str[1]
	   mov bl,0
	   lea si,str[2]
f1:    inc si
	   inc bl
	   cmp bh,bl
	   jnz f1
	   mov str[si],24h;结尾加$字符
	   
	   lea dx,str[2]
	   mov ah,9
	   int 21h
	   
	   mov ah,4ch
	   int 21h
code ends
end begin