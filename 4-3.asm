data segment
str db 20,?,20 dup(?)
data ends

stack segment stack
    db 1024 dup(0)
stack ends

code segment
	assume cs:code,ds:data,ss:stack
	
begin: 		mov ax,data
			mov ds,ax
			lea dx,str
			mov ah,0ah  ;10号命令进行输入
			int 21h
	   
			mov dl,0dh  ;回车
			mov ah,2
			int 21h
			mov dl,0ah ;换行
			mov ah,2
			int 21h
			
			mov bh,str[1]	;bh 是输入字符串的长短
			mov bl,0	  	;bl 指针移动的距离 
			lea si,str[2]   ;si 从字符串头开始移动
f1:			inc si
			inc bl
			cmp bh,bl
			jnz f1
			mov str[si],24h;结尾加$字符

			lea dx,str[2]
            mov ah,9
			int 21h
			
exit:		mov ah,4ch
			int 21h
code ends
end  begin 