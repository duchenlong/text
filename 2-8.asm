data segment
N dw 7 dup(12,-15,48,-123,145,2);0表示负数个数
data ends

stack segment stack
    db 1024 dup(0)
stack ends

code segment
	assume cs:code,ds:data,ss:stack
	
begin: 		mov ax,data
            mov ds,ax
			lea si,N
			mov bh,0 ;负数个数
			mov cl,10;除数
			mov ch,6 ;数组元素的个数
f:			mov bl,0
			mov ax,[si]  
			cmp ax,0  ;如果是正数直接输出
			jns f1
			mov ah,2
			mov dl,'-'
			int 21h
			mov ax,0
			sub ax,[si]  
			inc bh
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
			cmp ch,1
			jns f
			mov ah,2
			mov dl,0ah
			int 21h
			mov ah,2
			mov dl,0dh
			int 21h
			add bh,30h
			mov ah,2
			mov dl,bh
			int 21h
exit:		mov ah,4ch
			int 21h
code ends
end  begin 