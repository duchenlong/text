data segment
DAT1 db 8 dup(32h,56h,32h,01h,22h,01h,00h,48h)
DAT2 db 8 dup(32h,56h,32h,01h,22h,01h,00h,48h)
Str  db 8 dup(?)
data ends

stack segment stack
		db 1024 dup(0)
stack ends

code segment
	assume cs:code,ds:data,ss:stack
	
begin: mov ax,data
	   mov ds,ax
	   mov si,7
l1:	   mov al,DAT1[si]
	   mov dl,DAT2[si]
	   adc al,dl
	   mov Str[si],al
	   dec si
	   cmp si,0
	   jns l1
l3:	   inc si
	   mov dl,16
	   mov ah,0
	   mov al,Str[si]
	   div dl
	   cmp ah,10
	   jns s1
	   add ah,30h
	   jmp s3
s1:    add ah,55
s3:	   cmp al,10
	   jns s2
	   add al,30h
	   jmp s4
s2:	   add al,55
s4:    mov ch,ah
	   mov dl,al
	   mov ah,2
	   int 21h
	   mov dl,ch
	   mov ah,2
	   int 21h
	   mov ah,2
	   mov dl,' '
	   int 21h
	   cmp si,7
	   jnz l3
exit:  mov ah,4ch
	   int 21h
code ends
end begin