BITS 64
section .text

GLOBAL strlen

strlen:
    ENTER 0, 0
    XOR RAX, RAX
    MOV RSI, 0

loop:
    CMP BYTE[RDI], 0
    JE end
    INC RDI
    INC RSI
    CMP BYTE[RDI], 0
    JNE loop

end:
    MOV RAX, RSI
    LEAVE
    RET