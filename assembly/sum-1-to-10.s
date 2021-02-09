.pos 0x100
    ld    $0x0, r0          # r0 = 0 (tmp for i)
    ld    $a, r1            # r1 = address of a[0], i.e. 0x1000 + 4 + 4
    ld    $0x0, r2          # r2 = 0 (tmp for sum)
    ld    $0xfffffff6, r3   # r3 = -10 
loop: 
    mov   r0, r5            # r5 = r0 (i,e. i)
    add   r3, r5            # r5 = r0 - 10
    beq   r5, end_loop      # if r0 == 10 goto end, i.e. i=10 now

    ld    (r1, r0, 4), r4   # r4 = a[r0]
    add   r4, r2            # sum += a[r0]; i.e. sum += a[i]
    inc   r0                # r0 ++; i.e. i++
     
    # move PC with F9=-7, i.e. go back to loop: location 
    br   loop               # machine code = 80F9   
end_loop: 
    ld  $i,   r5        # r5 = address of i
    st  r0,   0x0 (r5)  # i = r0 (temp value in registry, flush to memory)
    ld  $s,   r0        # r0 = address of s, i.e. 0x1000
    st  r2,   0x0 (r0)  # s = r2
    halt
    

.pos 0x1000
s: .long 0xFFFFFFFF     # s
i: .long 0xFFFFFFFF     # i
a: .long 0x00000002     # a[0]
   .long 0x00000004     # a[1]
   .long 0x00000006     # a[2]
   .long 0x00000008     # a[3]
   .long 0x0000000a     # a[4]
   .long 0x0000000c     # a[5]
   .long 0x0000000e     # a[6]
   .long 0x00000010     # a[7]
   .long 0x00000012     # a[8]
   .long 0x00000014     # a[9]