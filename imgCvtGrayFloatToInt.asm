;%include "io64.inc"

section .data
    multiplier: dd 255.0
    
section .text

global imgCvtGrayFloatToInt
imgCvtGrayFloatToInt:
    ;write your code here
    
    mov rdi, rcx
    mov rsi, rdx
    mov rdx, r8
    
    mov rcx, 0
    movss xmm1, [multiplier]
    
.loop_start:
    cmp rcx, rdx
    jge .end_loop
    
    movss xmm0, [rdi + rcx * 4]
    mulss xmm0, xmm1
    cvttss2si eax, xmm0
    mov [rsi + rcx * 4], eax
    
    inc rcx
    jmp .loop_start

.end_loop:
    xor rax, rax
    ret