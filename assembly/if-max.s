.pos 0x100
    ld  $a,   r0         # r0 = address of a
    ld  0x0 (r0), r0     # load r0 address 0x0 offset value into r0
                         # i.e. r0 = the value of a
    
    ld  $b,   r1         # r1 = address of b
    ld  0x0 (r1), r1     # r1 = value of b

    mov r1,   r2         # r2 = value of b too; mimic j for calculation
    not r2               # complement r2 for negative b
    inc r2               # r2 = -(value of b)
    add r0,   r2         # r2 = a-b
    bgt r2,   then       # if a > b goto +2
else:
    mov r1,   r3         # r3 = b
    br  end_if           # goto +1
then:
    mov r0,   r3         # r3 = a
end_if:
    ld  $max, r0         # r0 = address of max
    st  r3, 0x0 (r0)     # max = r3
    halt

.pos 0x1000
a: .long 0x00000001       # a = 1
b: .long 0x00000002       # b = 2
max: .long 0xFFFFFFFF     # max = -1