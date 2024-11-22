.model small
.stack 100h
.data
.code

main proc
mov  ax,@data
mov es,ax
mov ds,ax
mov si,0030h
mov dx,0000h
mov ax,0000h
mov cl,[si]

l2:
cmp cl,00hs
jz l1
dec cl
mov al,dl
add al,01h
daa
mov dl,al
mov al,dh
adc al,00h
daa
mov dh,al
jmp l2

l1:
mov si,0040h
mov [si],dx

int 03h
mov ah,4ch
int 21h

main endp
end main
