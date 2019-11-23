data segment
a dw 2016
N dw 6 dup(?)
data ends

stack segment stack
		db 1024 dup(0)
stack ends

code segment
	assume cs:code,ds:data,ss:stack
	
begin: mov ax,stack
	   mov ss,ax
	   mov ax,data
	   mov ds,ax
	   mov ax,a
	   mov bl,10
	   mov si,0
l1:	   div bl
	   mov N[si],ah
	   inc si
	   mov ah,0
	   cmp ax,0
	   ja l1
l2:	   dec si
	   mov al,N[si]
	   add al,48
	   mov ah,2
	   mov dl,al
	   int 21h
	   cmp si,0
	   jne l2
exit: mov ah,4ch
	  int 21h
code ends
end begin