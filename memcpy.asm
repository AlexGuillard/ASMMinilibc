BITS 64
section .text

GLOBAL memcpy

memcpy:
    ENTER 0, 0
    XOR RAX, RAX
    MOV RAX, 0
    PUSH RDI
    XOR R8, R8
    XOR RCX, RCX
    MOV RCX, 0

loop:
    CMP BYTE [RSI], 0
    JE end 
    CMP RDX, RCX
    JE end
    MOV R8B, BYTE [RSI]
    MOV [RDI + RCX], R8B
    INC RCX
    INC RSI
    JMP loop

end:
    MOV RAX, RDI
    LEAVE
    RET


