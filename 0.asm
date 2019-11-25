data segment
d  dw 5
data ends

stack segment stack
    db 1024 dup(0)
stack ends

code segment
      assume cs:code,ds:data,ss:stack
	  
begin: 		mov ax,data
            mov ds,ax
			mov bx,d
			cmp bx,0
			jz f2
			mov cl,17
f1:			rol bx,1
			dec cl
			jnc f1 
two:		mov ax,bx
			and ax,1
			cmp ax,0
            jz zero
			mov dl,31h
			jmp show
zero:   	mov dl,30h
show:    	mov ah,2
			int 21h
			mov ah,2
			mov dl,' '
			int 21h
			rol bx,1
			dec cl
			jnz two
			jmp exit
f2:			mov ah,2
			mov dl,30h
			int 21h
exit:		mov ah,4ch
			int 21h
code ends
end  begin 