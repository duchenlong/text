data segment
x db 3
y db 4
a db ?
data ends
sseg segment stack
db 1024 dup(0)
sseg ends
cseg segment
assume ds:data,ss:sseg,cs:cseg
begin:mov ax,data
mov ds,ax
mov ah,x
mov bh,y
add ah,bh
add ah,48
mov ch,ah
mov a,ch
mov ah,2
mov dl,a
int 21h
exit:mov ah,4ch
int 21h
cseg ends
end begin