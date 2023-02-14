BITS 64
section .text

GLOBAL strchr

strchr:
    ENTER 0, 0
    XOR RAX, RAX
    MOV RAX, 0
    CMP BYTE [RSI], 0
    JE void

loop:
    CMP BYTE [RDI], 0
    JE end
    CMP [RDI], SIL
    JE find
    INC RDI
    JMP loop

void:
    MOV RAX, RSI
    JMP end

find:
    MOV RAX, RDI
    JMP end
end:
    LEAVE
    RET