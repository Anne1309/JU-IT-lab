.model small
.stack 100h
.code

main proc
mov ax, @data
mov ds, ax

mov si, 0030h
mov al, 00h
mov cl, 0007h
inc si

l1:
cmp al, [si]
jnc l2
mov al, [si]
l2:
inc si
loop l1

mov si,0040h
mov [si], al

int 03h

main endp
end main
