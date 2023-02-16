BITS 64
section .text

GLOBAL strcspn

strcspn:
    ENTER 0, 0
    XOR RAX, RAX
    MOV RAX, 0
    XOR RDX, RDX
    MOV RDX, 0
    XOR RCX, RCX
    MOV RCX, 0
    XOR R8, R8

main_loop:
    CMP BYTE [RDI], 0
    JE end
    MOV RCX, 0
    JMP check_loop

check_loop:
    CMP BYTE [RSI + RCX], 0
    JE not_find
    MOV R8B, BYTE [RSI + RCX]
    CMP BYTE [RDI], R8B
    JE find
    INC RCX
    JMP check_loop

not_find:
    INC RDI
    JMP main_loop

find:
    INC RDI
    INC RDX
    JMP main_loop

end:
    MOV RAX, RDX
    LEAVE
    RET