BITS 64
section .text

GLOBAL memcpy

memcpy:
    ENTER 0, 0
    XOR RAX, RAX
    MOV RAX, 0

loop:
    CMP BYTE [RDI], RDX
    JE end
    CMP RDX, RCX
    JE end
    MOV [RDI], SIL
    PUSH RSI
    INC RDI
    INC RCX
    JMP loop

end:
    LEAVE
    RET
