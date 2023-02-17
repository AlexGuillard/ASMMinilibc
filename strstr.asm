BITS 64
section .text

GLOBAL strstr

strstr:
    ENTER 0, 0
    XOR RAX, RAX
    MOV RAX, 0
    XOR RDX, RDX
    MOV RDX, 0
    XOR RCX, RCX
    MOV RCX, 0
    XOR R8, R8
    XOR R9, R9
    MOV R9, 0

main_loop:
    CMP BYTE [RDI], 0
    JE end
    MOV RCX, 0
    MOV R9, 0
    JMP check_loop

check_loop:
    CMP BYTE [RSI + RCX], 0
    JE find
    MOV R8B, BYTE [RSI + RCX]
    CMP BYTE [RDI + R9], R8B
    JNE not_find
    INC RCX
    INC R9
    JMP check_loop

not_find:
    INC RDX
    INC RDI
    JMP main_loop

find:
    JMP end

end:
    MOV RAX, RDI
    LEAVE
    RET