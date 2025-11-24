;%include "io64.inc"

section .data
    multiplier: dd 255.0
    half:       dd 0.5

section .text
    bits 64
    default rel
global imgCvtGrayFloatToInt
imgCvtGrayFloatToInt:

    mov rdi, rcx        ; input float*
    mov rsi, rdx        ; output int*
    mov rdx, r8         ; total pixels

    xor rcx, rcx
    movss xmm1, [multiplier]    ; 255.0
    movss xmm2, [half]          ; 0.5

.loop:
    cmp rcx, rdx
    jge .done

    movss xmm0, [rdi + rcx*4]    ; load float pixel
    mulss xmm0, xmm1            ; x = pixel * 255

    roundss xmm4, xmm0, 1       ; 1 = floor(x)

    movss xmm5, xmm0
    addss xmm5, xmm2            ; tmp = x + 0.5

    roundss xmm6, xmm5, 1       ; floor(tmp)

    movss xmm7, xmm6
    subss xmm7, xmm4            ; test = rounded - floor_x
    cvttss2si eax, xmm7         ; convert test to int

    cmp eax, 1
    jne .store_normal           ; not tie -> store rounded

    cvttss2si eax, xmm6         ; eax = rounded
    test eax, 1                 ; check if odd
    jz .store                   ; if even -> store as-is
    dec eax                     ; if odd -> subtract 1
    jmp .store

.store_normal:
    cvttss2si eax, xmm6         ; normal rounding

.store:
    mov [rsi + rcx*4], eax

    inc rcx
    jmp .loop

.done:
    ret
