    @.thumb                      @ ARM assembly intro template
    .syntax unified
        .global __reset
    .section .vectors
    @@ Vector table at address 0
    .word __stack               @ Initial stack pointer
    .word __reset               @ Reset vector
    @@ Rest of the vectors are unused

    .text
    .thumb_func
__reset:
    mov r0, #0         @ initialize register to zero

main:
    nop
    @ Add your code in this section 
    mov r0, #5
    mov r1, #5
    add r1, r0, r1

    @Comptuing some big number
    mov r1, #229
    mov r2, #2
    lsl r2, r2, 29
    add r2, r2, #40
    add r0, r1, r2

    @Practicing bit shifting
    mov r0, #0x000000ff
    lsl r0, r0, 1
    lsl r0, r0, 2
    lsl r0, r0, 3

    @Changing the sign of a 2's complement number
    mvn r0, r0
    add r0, #1

    
    b main             @ and repeat
.size main, .-main