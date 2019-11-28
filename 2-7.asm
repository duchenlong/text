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
			mov ch,6
			mov ax,[si]
s1:			inc si
			inc si
			cmp ax,[si]
			jns s2
			mov ax,[si]
s2:			dec ch
			cmp ch,1
			jnz s1
f:			mov bl,0
			mov cl,10
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
exit:		mov ah,4ch
			int 21h
code ends
end  begin 