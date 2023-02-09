BITS 64
section .text

GLOBAL strchr

strchr:
    ENTER 0, 0
    XOR RAX, RAX
    MOV RAX,0

loop:
    CMP BYTE[RDI], 0
    JE end
    INC RDI
    CMP [RDI], RSI
    JNE loop
    MOV RAX, RDI
    JMP end

end:
    LEAVE
    RET