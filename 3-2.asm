data segment 
src  db 'abcdef','$'
N dw 6		;密码长度
str1 db  'welcome  ',0dh,0ah,'$'
str2 db  'wrong  ',0dh,0ah,'$'
str3 db  'sorry  password iswrong ',0dh,0ah,'$'
str  dw 20,?,20 dup(?)
data ends

stack segment stack
    db 1024 dup(?)
stack ends

code segment
	assume cs:code,ds:data,es:data,ss:stack
	
begin:	mov ax,data
		mov ds,ax
		mov es,ax
		mov bl,0 ;输入密码的次数
		
Scanf:	lea dx,str
		mov ah,0ah
		int 21h
		
		inc bl ;输入次数
	
		mov dl,0dh  ;回车
		mov ah,2
		int 21h
		mov dl,0ah ;换行
		mov ah,2
		int 21h
			
		mov ax,str[1]	;bx 是输入字符串的长短
		mov ah,0
		cmp ax,N
		jnz Wrong ;长度不相等,密码错误
judge:  CLD		  ;DF清0，串操作从前向后
		mov cx,N
		lea si,str[2]
		lea di,src
		REPZ CMPSB
		cmp cx,0
		jz correct
		
Wrong:	cmp bl,3
		jnz Printf1 ;前两次密码错误，输入二号字符串
		lea dx,str3 ;第三次密码错误，输入三号字符串
		mov ah,9
		int 21h
		jmp exit
Printf1:lea dx,str2 
		mov ah,9
		int 21h
		jmp Scanf
		 
correct:lea dx,str1  ;密码正确显示串1
		mov ah,9
		int 21h
		 
exit:	mov ah,4ch
		int 21h
code ends
end  begin