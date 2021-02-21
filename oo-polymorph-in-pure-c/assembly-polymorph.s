.pos 0x100
main:
    ld  $heap, r7         # heap address
    ld  $bottom_stack, r5 # call stack address

    # a object
    gpc  $0x06, r6        # r6 = current address of pc + 6
    j    new_A            # call new A

    ld   0x0 (r0), r1      # r1 = a->class
    gpc  $0x02, r6         # r6 = PC + 2
    j    *0x0 (r1)         # a->class->bar
    gpc  $0x02, r6         # r6 = PC + 2
    j    *0x4 (r1)         # a->class->foo

    ld   $ax, r2           # r2 = address of ax
    ld   0x04 (r0), r3     # r3 = x
    st   r3,  0x0 (r2)     # ax = a->x

    ld   $ay, r2           # r2 = address of ay
    ld   0x08 (r0), r3     # r3 = y
    st   r3,  0x0 (r2)     # ay = a->y

    gpc  $0x06, r6         # r6 = PC + 2
    j    free              # reformat heap to -1 to mimic releasing memory

    # b object
    gpc  $0x06, r6        # r6 = current address of pc + 6
    j    new_B            # call new B

    ld   0x0 (r0), r1      # r1 = b->class
    gpc  $0x02, r6         # r6 = PC + 2
    j    *0x0 (r1)         # b->class->bar
    gpc  $0x02, r6         # r6 = PC + 2
    j    *0x4 (r1)         # b->class->foo

    ld   $bx, r2           # r2 = address of bx
    ld   0x04 (r0), r3     # r3 = x
    st   r3,  0x0 (r2)     # bx = b->x

    ld   $by, r2           # r2 = address of by
    ld   0x08 (r0), r3     # r3 = y
    st   r3,  0x0 (r2)     # by = b->y

    gpc  $0x06, r6         # r6 = PC + 2
    j    free              # reformat heap to -1 to mimic releasing memory

    halt

malloc:
    mov  r7,  r1            # r1 = r7, which is current free heap address
    add  r0,  r7            # r7 = current free + size
    # no need to move since it is already pointing to next free available address
    # inca r7               # move to next address to store the size
    st   r0,  0x0 (r7)      # store the size of heap
    mov  r1,  r0            # r0 is pointing to its heap address
    j    0x0 (r6)           # return the call

free:
    ld   0x0 (r7), r1           # size of my heap
    ld   $0xFFFFFFFF, r3        # r3 = -1
do_free:
    st   r3, 0x0 (r7)           # reset to -1 to mimic memory released
    beq  r1, end_free
    deca r1
    deca r7
    br   do_free
end_free:
    j    0x0 (r6)           # return the call

new_A:
    deca  r5                 # stack frame push
    st    r6, 0x0 (r5)       # save return address on call stack
    ld    $0x0C, r0          # r0 = sizeof (struct A)   3*4
    gpc   $0x06, r6          # r6 = current address of pc + 6
    j     malloc
    ld    $A_class, r1       # r1 = address of A_class label
    st    r1, 0x0 (r0)       # A->class = A_class
    ld    $0x0, r2           # r2 = 0 for init a.x and a.y
    st    r2, 0x4 (r0)       # a->x = r2 = 0
    st    r2, 0x8 (r0)       # a->y = r2 = 0
    ld    0x0 (r5), r6       # restore return address from stack (pop)
    inca  r5
    j     0x0 (r6)
new_B:
    deca  r5                 # stack frame push
    st    r6, 0x0 (r5)       # save return address on call stack
    ld    $0x0C, r0          # r0 = sizeof (struct B)   3*4
    gpc   $0x06, r6          # r6 = current address of pc + 6
    j     malloc
    ld    $B_class, r1       # r1 = address of B_class label
    st    r1, 0x0 (r0)       # B->class = B_class
    ld    $0x0, r2           # r2 = 0 for init b.x and b.y
    st    r2, 0x4 (r0)       # b->x = r2 = 0
    st    r2, 0x8 (r0)       # b->y = r2 = 0
    ld    0x0 (r5), r6       # restore return address from stack (pop)
    inca  r5
    j     0x0 (r6)

new_C:
    deca  r5                 # stack frame push
    st    r6, 0x0 (r5)       # save return address on call stack
    ld    $0x10, r0          # r0 = sizeof (struct C)   4*4
    gpc   $0x06, r6          # r6 = current address of pc + 6
    j     malloc
    ld    $C_class, r1       # r1 = address of C_class label
    st    r1, 0x0 (r0)       # C->class = C_class
    ld    $0x0, r2           # r2 = 0 for init c.x and c.y
    st    r2, 0x4 (r0)       # c->x = r2 = 0
    st    r2, 0x8 (r0)       # c->y = r2 = 0
    ld    0x4 (r5), r1       # r1 = step from parameter
    st    r1,  0x0c (r0)     # c->step = step from parameter
    ld    0x0 (r5), r6       # restore return address from stack (pop)
    inca  r5
    j     0x0 (r6)

A_bar:
    ld   0x0 (r7), r3         # size of my heap
    mov  r7, r4               # r1 = r7
    not  r3
    inc  r3                   # r3 = -r3
    add  r3,  r4              # r3 = start address of my heap
    ld   0x04 (r4), r3        # r3 = x value
    ld   $0x02, r2            # r2 = 2;
    add  r2, r3               # r3 = x + 2
    inca r4                   # r1 is pointing at address of x
    st   r3, 0x0 (r4)         # x = x + 2
    j   0x0 (r6)              # return with assumptation r6 stores next instruction address
A_foo:
    ld   0x0 (r7), r3         # size of my heap
    mov  r7, r4               # r4 = r7
    not  r3
    inc  r3                   # r3 = -r3
    add  r3,  r4              # r4 = start address of my heap
    ld   0x08 (r4), r3        # r3 = y value
    ld   $0x0a, r2            # r2 = 10;
    add  r2, r3               # r3 = y + 10
    inca r4                   # r4 is pointing at address of x
    inca r4                   # r4 is pointing at address of y
    st   r3, 0x0 (r4)         # y = y + 10
    j   0x0 (r6)              # return with assumptation r6 stores next instruction addres

B_bar:
    ld   0x0 (r7), r3         # size of my heap
    mov  r7, r4               # r1 = r7
    not  r3
    inc  r3                   # r3 = -r3
    add  r3,  r4              # r3 = start address of my heap
    ld   0x04 (r4), r3        # r3 = x value
    ld   $0x64, r2            # r2 = 100;
    add  r2, r3               # r3 = x + 100
    inca r4                   # r1 is pointing at address of x
    st   r3, 0x0 (r4)         # x = x + 100
    j   0x0 (r6)              # return with assumptation r6 stores next instruction address

B_woo:
    ld   0x0 (r7), r3         # size of my heap
    mov  r7, r4               # r4 = r7
    not  r3
    inc  r3                   # r3 = -r3
    add  r3,  r4              # r4 = start address of my heap
    ld   0x08 (r4), r3        # r3 = y value
    ld   $0x2710, r2          # r2 = 10000;
    add  r2, r3               # r3 = y + 10000
    inca r4                   # r4 is pointing at address of x
    inca r4                   # r4 is pointing at address of y
    st   r3, 0x0 (r4)         # y = y + 100000
    j   0x0 (r6)              # return with assumptation r6 stores next instruction addres   

C_bar:
    ld   0x0 (r7), r3         # size of my heap
    mov  r7, r4               # r1 = r7
    not  r3
    inc  r3                   # r3 = -r3
    add  r3,  r4              # r3 = start address of my heap
    ld   0x04 (r4), r3        # r3 = x value
    ld   0x0c (r4), r2        # r2 = step value
    add  r2, r3               # x = x + step
    st   r3, 0x4 (r4)         # store x value back to heap

    deca  r5                 # stack frame push
    st    r6, 0x0 (r5)       # save return address on call stack
    gpc   $0x06, r6          # r6 = current address of pc + 6
    j     B_bar
    ld    0x0 (r5), r6       # restore return address from stack (pop)
    inca  r5

    j     0x0 (r6)

.pos 0x1000               # static data
ax: .long 0xFFFFFFFF       # ax = -1
ay: .long 0xFFFFFFFF       # ay = -1
bx: .long 0xFFFFFFFF       # bx = -1
by: .long 0xFFFFFFFF       # by = -1
cx: .long 0xFFFFFFFF       # cx = -1
cy: .long 0xFFFFFFFF       # cy = -1
A_class: 
   .long A_bar
   .long A_foo
B_class: 
   .long B_bar
   .long A_foo
   .long B_woo
C_class: 
   .long C_bar
   .long A_foo
    
.pos 0x2000               # heap
heap: .long 0xFFFFFFFF       # default to -1
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       

.pos 0x2FE0               # stack
top_stack: 
      .long 0xFFFFFFFF       # default to -1
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       
      .long 0xFFFFFFFF       
bottom_stack:               # pos = 0x3000
      .long 0xFFFFFFFF       