data segment
N dw 6 dup(12,-15,48,-123,145,2)
data ends

stack segment stack
    db 1024 dup(0)
stack ends

code segment
	assume cs:code,es:data,ds:data,ss:stack
	
begin: 		mov ax,data
            mov ds,ax
			mov es,ax 
			call ShowArr
			mov dl,0ah
			mov ah,2
			int 21h
			mov dl,0dh
			mov ah,2
			int 21h
			mov ah,0  ;ah外循环次数	
SortW:		lea si,N  ;si 指向需要比较的数的地址
			mov bl,5
			mov al,0  ;al内循环次数 
			sub bl,ah ;bl是本次内循环的最大比较次数
			mov di,si 
SortN:		inc di    ;di指向被比较的数的地址
			inc di
			mov cx,[si]
			mov dx,[di] 
judge1:		cmp cx,0  ;判断两个数是否都是负数的情况
			jns judgenum
			cmp dx,0
			jns judgenum
			push cx  ;保护比较的负数
			push dx
			neg dx   ;对负数取绝对值
			neg cx
			cmp cx,dx
			pop dx   ;还原负数
			pop cx
			js Swap  ;判断是否交换
			jmp SortNnum
judgenum:	cmp cx,dx
			jle SortNnum
Swap:		mov [si],dx
			mov [di],cx
SortNnum:	inc si  ;需要比较的数的指针移动
			inc si
			inc al
			cmp bl,al  ;判断内循环是否结束
			jnz SortN
			inc ah
			cmp ah,5
			jnz SortW  ;判断外循环是否结束
			call ShowArr
exit:		mov ah,4ch
			int 21h
			
;子程序功能：打印数组中的所有元素	
;使用寄存器：si,cx,ax,dx,bl
;cl 除数
;ax 数组中的元素兼被除数
;dx 弹栈后输出使用
;si 指针变量，表示数组元素的地址
ShowArr		proc
			lea si,N ;开始打印排序后的数组
			mov cl,10;cl 是除数
			mov ch,6 ;数组元素的个数
f:			mov bl,0
			mov ax,[si]  
			cmp ax,0  ;如果是正数直接输出
			jns f1
			mov ah,2
			mov dl,'-';负数先打印 '-'
			int 21h
			mov ax,0
			sub ax,[si] ;用0减去这个数，把负数变成正数
f1:			div cl   ;除10取模来显示ax中的数
			push ax  ;每操作一次进行压栈保护
			mov ah,0 ;余数清零
			inc bl   ;记录压栈次数
			cmp al,0 ;判断商是否为0
			jnz f1
f2:			pop dx   ;弹栈
			mov dl,dh
			add dl,30h  ;将数字转为字符串
			mov ah,2
			int 21h
			dec bl   ;弹栈次数
			cmp bl,0
			jnz f2
			mov ah,2
			mov dl,' ' ;两个十进制数中加空格分隔
			int 21h
			inc si   ;指针向下一个元素移动
			inc si
			dec ch 	 ;循环次数-1
			cmp ch,1 ;判断是否打印完毕
			jns f
			ret
ShowArr		endp

code ends
end  begin 
