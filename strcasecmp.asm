BITS 64
section .text

GLOBAL strcasecmp

strcasecmp:
    ENTER 0, 0
    XOR RAX, RAX
    MOV RAX, 0
    XOR R8, R8
    XOR R9, R9
    XOR RCX, RCX
    MOV RCX, 0

;loop
loop:
    CMP BYTE [RDI], 0
    JE check_less
    CMP BYTE [RSI], 0
    JE check_more

    ;if R8 > A && Z < R8
check_R8:
    MOV R8B, BYTE [RDI]
    CMP R8, 90
    JG check_R9

    CMP R8, 65
    JL check_R9
    ADD R8, 32

    ;if R9 > A && Z < R9
check_R9:
    MOV R9B, BYTE [RSI]
    CMP R9, 90
    JG end_loop

    CMP R9, 65
    JL end_loop
    ADD R9, 32

end_loop:
    CMP R8, R9
    JNE check
    INC RDI
    INC RSI
    INC RCX
    JMP loop
;end loop

;check if equal when at end of first string 
check_less:
    CMP BYTE [RSI], 0
    JE equal
    MOV R8B, BYTE [RDI]
    MOV R9B, BYTE [RSI]
    ;if R9 > A && Z < R9
    CMP R9, 90
    JG check

    CMP R9, 65
    JL check
    ADD R9, 32
    JMP check

;check if equal when at end of Second string 
check_more:
    CMP BYTE [RDI], 0
    JE equal
    MOV R8B, BYTE [RDI]
    MOV R9B, BYTE [RSI]
    ;if R9 > A && Z < R9
    CMP R8, 90
    JG check

    CMP R8, 65
    JL check
    ADD R8, 32
    JMP check

;Calcul Value return and return
check:
    SUB R8, R9
    MOV RAX, R8
    JMP end

equal:
    MOV RAX, 0
    JMP end

end:
    LEAVE
    RET
;end