BITS 64
section .text

GLOBAL strchr

strchr:
    ENTER 0, 0
    XOR RAX, RAX
    MOV RAX, 0

loop:
    CMP BYTE [RDI], 0
    JE end
    CMP [RDI], SIL
    JE find
    INC RDI
    JMP loop

find:
    JMP end
end:
    MOV RAX, RDI
    LEAVE
    RET