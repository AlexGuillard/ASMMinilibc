BITS 64
section .text

GLOBAL strcmp

strcmp:
    ENTER 0, 0
    XOR RAX, RAX
    MOV RAX, 0
    XOR R8, R8
    XOR R9, R9

loop:
    CMP BYTE [RDI], 0
    JE check_less
    CMP BYTE [RSI], 0
    JE check_more
    MOV R8B, BYTE [RDI]
    MOV R9B, BYTE [RSI]
    CMP R8, R9
    JG more
    CMP R8, R9
    JL less
    INC RDI
    INC RSI
    JMP loop

more:
    MOV RAX, 1
    JMP end

less:
    MOV RAX, -1
    JMP end

check_less:
    CMP BYTE [RSI], 0
    JE equal
    MOV RAX, -1
    JMP end

check_more:
    CMP BYTE [RDI], 0
    JE equal
    MOV RAX, 1
    JMP end

equal:
    MOV RAX, 0
    JMP end

end:
    LEAVE
    RET