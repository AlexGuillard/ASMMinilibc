BITS 64
section .text

GLOBAL memset

memset:
    ENTER 0, 0
    XOR RAX, RAX
    MOV RAX, 0
    MOV RCX, 0

loop:
    CMP RDX, RCX
    JE end
    MOV [RDI + RCX], SIL
    INC RCX
    JMP loop

end:
    MOV RAX, RDI
    LEAVE
    RET
