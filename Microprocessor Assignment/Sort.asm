code segment
assume ds:code,cs:code
start:
 mov ax,code
 mov ds,ax
 jmp start2
ARR:   dw 1,2,4,3,6,5,9
start2:
 mov ch,0h
ARR:   dw 1,2,4,3,6,5,9
 mov ch,0h
 mov cl,1h
 mov bh 7h
 jmp assign_nums
restart:
 mov ch,0h
 mov cl,1h
 dec bh
 jmp assign_nums
swap:
 mov ch,dl
 mov cl,dh
 jmp next
next:
 cmp bh,cl
 je restart
 add ch,1h
 add cl,1h
 jmp assign_nums
assign_nums:
 cmp bh,0h
 je done
mov ax,[ARR+si]
mov dx,[ARR+di]
 cmp dh,dl
 jl swap
 jnl next
done:
 nop
code ends
end start