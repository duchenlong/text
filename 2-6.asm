data segment
N dw 6 dup(12,15,48,123,145,2)
data ends

stack segment stack
    db 1024 dup(0)
stack ends

code segment
	assume cs:code,ds:data,ss:stack
	
begin: 		mov ax,data
            mov ds,ax
			lea si,N
			mov cl,10
			mov ch,6
f:			mov ax,[si]
			mov bl,0
f1:			div cl
			push ax
			mov ah,0
			inc bl
			cmp al,0
			jnz f1
f2:			pop dx
			mov dl,dh
			add dl,30h
			mov ah,2
			int 21h
			dec bl
			cmp bl,0
			jnz f2
			mov ah,2
			mov dl,' '
			int 21h
			inc si
			inc si
			dec ch
			cmp ch,0
			jnz f
exit:		mov ah,4ch
			int 21h
code ends
end  begin 