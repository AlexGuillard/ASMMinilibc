BITS 64
section .text

GLOBAL memset

memset:
    ENTER 0, 0
    XOR RAX, RAX
    MOV RAX, 0
    MOV RCX, 0
    PUSH RSI
    POP DIL

end:
    LEAVE
    RET
