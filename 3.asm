data segment
d  dw 11
N  dw 6 dup(?)
c  db 0
data ends

stack segment stack
    db 1024 dup(0)
stack ends

code segment
      assume cs:code,ds:data,ss:stack
	  
begin: 		
sub2:		mov ax,data
            mov ds,ax
			mov bx,d
			mov dh,c
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
			inc dh
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
f2:			mov ah,2
			mov dl,0dh
			int 21h
			mov ah,2
			mov dl,0ah
			int 21h
			
Show1Num:	mov cl,10
			mov al,dh
			mov ah,0
			div cl
			mov ch,al
			mov dl,ah
			add dl,30h
			mov ah,2
			int 21h
			cmp ch,0
			jz w
			add ch,30h
			mov ah,2
			mov dl,ch
			int 21h
w:			mov ah,2
			mov dl,0dh
			int 21h
			mov ah,2
			mov dl,0ah
			int 21h
			
			
sub16:		mov bx,d
			mov cx,0504h
			cmp bx,0
s1:			rol bx,cl
			dec ch
			mov ax,bx
			and ax,0Fh
			cmp ax,0
			jz s1	
sixteen:	mov ax,bx
			and ax,0Fh
			cmp ax,10
            js sum
	        add al,55
			mov dl,al
			jmp show16			
sum:   		add al,30h
			mov dl,al		
show16:    	mov ah,2
			int 21h
			mov ah,2
			mov dl,' '
			int 21h
			rol bx,cl
			dec ch
			jnz sixteen
s2:			mov ah,2
			mov dl,0dh
			int 21h
			mov ah,2
			mov dl,0ah
			int 21h
	
sub10:		mov bx,d
			mov ax,bx 
			mov cl,0
			mov bl,10 
			lea si,N
		
l1:	    	div bl
			mov [si],ah
			inc cl
			inc si
			inc si
			mov ah,0
			cmp ax,0
			jnz l1
			
l2:	   		dec si
			dec si
			mov al,[si]
			add al,48
			mov ah,2
			mov dl,al
			int 21h
			dec cl
			cmp cl,0
			jne l2
			mov ah,2
			mov dl,0dh
			int 21h
			mov ah,2
			mov dl,0ah
			int 21h
		
exit:		mov ah,4ch
			int 21h
code ends
end  begin 