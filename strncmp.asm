BITS 64
section .text

GLOBAL strncmp

strncmp:
    ENTER 0, 0
    XOR RAX, RAX
    MOV RAX, 0
    XOR R8, R8
    XOR R9, R9
    XOR RCX, RCX
    MOV RCX, 0

loop:
    CMP RCX, RDX
    JE equal
    CMP BYTE [RDI], 0
    JE check_less
    CMP BYTE [RSI], 0
    JE check_more
    MOV R8B, BYTE [RDI]
    MOV R9B, BYTE [RSI]
    CMP R8, R9
    JNE check
    INC RDI
    INC RSI
    INC RCX
    JMP loop

check:
    SUB R8, R9
    MOV RAX, R8
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