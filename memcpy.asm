BITS 64
section .text

GLOBAL memcpy

memcpy:
    ENTER 0, 0
    XOR RAX, RAX
    MOV RAX, 0
    MOV RCX, 0

loop:
    CMP BYTE [RSI], 0
    JE end
    CMP RCX, RDX
    JE end
    MOVSB               ;
    INC RCX
    JMP loop

end:
    LEAVE
    RET


