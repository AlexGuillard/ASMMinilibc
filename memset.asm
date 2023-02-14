BITS 64
section .text

GLOBAL memset

memset:
    ENTER 0, 0
    XOR RAX, RAX
    MOV RAX, 0
    MOV RCX, 0
    MOV R8, RDI

loop:
    CMP RDX, RCX
    JE end
    MOV [RDI], SIL
    PUSH RSI
    INC RDI
    INC RCX
    JMP loop

end:
    LEAVE
    RET
