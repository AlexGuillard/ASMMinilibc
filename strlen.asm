BITS 64
section .text

GLOBAL strlen

strlen:
    ENTER 0, 0
    XOR RAX, RAX
    MOV RSI, 0

    loop:
        INC RDI
        INC RSI
        CMP BYTE[RDI], 0
        JNE loop

    MOV RAX, RSI
    LEAVE
    RET