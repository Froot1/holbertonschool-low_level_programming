; File: 100-_hello_holberton.asm
; Auth: Fahad Alonazi
; Desc: 64-bit assembly program that prints
;       Hello, World followed by a new line.

section .text
   global main

main:
   mov edx,len
   mov ecx,msg
   mov ebx,1
   mov eax,4
   int 0x80

   mov eax,0
   int 0x80

section .data
   msg: db 'Hello, World', 0xa
   len: equ $ - msg
