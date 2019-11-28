data segment
d dw -20
data ends

stack segment stack
    db 1024 dup(0)
stack ends

code segment
	assume cs:code,ds:data,ss:stack
	
begin: 		mov ax,data
            mov ds,ax
			mov ax,d
			cmp ax,0
			jns f    ;判断是否是负数
			mov ah,2
			mov dl,'-'  ;如果是负数，则打印-
			int 21h
			mov ax,0   ;将负数转成正数
			sub ax,d
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