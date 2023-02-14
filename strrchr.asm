BITS 64
section .text

GLOBAL strrchr

strrchr:
    ENTER 0, 0
    XOR RAX, RAX
    MOV RAX, 0

loop:
    CMP BYTE [RDI], 0
    JE last
    CMP [RDI], SIL
    JE find
    INC RDI
    JMP loop

find:
    MOV RAX, RDI
    INC RDI
    JMP loop

last:
    CMP [RDI], SIL
    JNE end
    MOV RAX, RDI
    JMP end

end:
    LEAVE
    RET

