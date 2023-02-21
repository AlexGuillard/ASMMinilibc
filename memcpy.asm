BITS 64
section .text

GLOBAL memcpy

memcpy:
    ENTER 0, 0
    XOR RAX, RAX
    MOV RAX, 0
    XOR R8, R8
    XOR R9, R9
    XOR RCX, RCX
    MOV RCX, 0

    CMP RDX, RCX
    JE end
    CMP RDI, 0
    JE void
    CMP RSI, 0
    JE void

loop:
    CMP RDX, RCX
    JE end
    CMP BYTE [RSI], 0
    JE end 
    MOV R8B, BYTE [RSI]
    MOV [RDI + RCX], R8B
    INC RCX
    INC RSI
    JMP loop

void:
    LEAVE
    RET

end:
    MOV RAX, RDI
    LEAVE
    RET


