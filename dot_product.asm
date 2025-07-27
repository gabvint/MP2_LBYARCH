section .text
global dot_product_asm

dot_product_asm:
    ; RCX = A
    ; RDX = B
    ; R8  = n

    xorpd xmm0, xmm0
    xor r9, r9         ; loop index i = 0

.loop:
    cmp r9, r8         ; compare i with n
    jge .done

    ; xmm1 = A[i]
    movsd xmm1, [rcx + r9*8]

    ; xmm2 = B[i]
    movsd xmm2, [rdx + r9*8]

    ; xmm1 *= xmm2
    mulsd xmm1, xmm2

    ; sum += xmm1
    addsd xmm0, xmm1

    inc r9
    jmp .loop

.done:
    ret
