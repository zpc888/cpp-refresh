.pos 0x100
A_bar:
    mov r5, r0               # r5 point to *this in heap
    inca r0                   # inca moves to address of this->x
    ld  0x0 (r0), r1          # r1 = value of address of x
    ld  $0x02, r2             # r2 = 2;
    add r2, r1                # r1 = x + 2
    st  r1,   0x0 (r0)        # save x + 2 back to address of x
    j   0x0 (r6)              # return with assumptation r6 stores next instruction address
A_foo:
    mov r5, r0               # r5 point to *this in heap
    inca r0                   # inca moves to address of this->x
    inca r0                   # r0 = address of this->y
    ld  0x0 (r0), r1          # r1 = value of address of y
    ld  $0x0a, r2             # r2 = 10;
    add r2, r1                # r1 = y + 10
    st  r1,   0x0 (r0)        # save y + 10 back to address of y
    j   0x0 (r6)              # return with assumptation r6 stores next instruction address

B_bar:
    mov r5, r0               # r5 point to *this in heap
    inca r0                   # inca moves to address of this->x
    ld  0x0 (r0), r1          # r1 = value of address of x
    ld  $0x64, r2             # r2 = 100;
    add r2, r1                # r1 = x + 100
    st  r1,   0x0 (r0)        # save x + 100 back to address of x
    j   0x0 (r6)              # return with assumptation r6 stores next instruction address

B_woo:
    mov r5, r0               # r5 point to *this in heap
    inca r0                   # inca moves to address of this->x
    inca r0                   # r0 = address of this->y
    ld  0x0 (r0), r1          # r1 = value of address of y
    ld  $0x2710, r2           # r2 = 10000
    add r2, r1                # r1 = y + 10000
    st  r1,   0x0 (r0)        # save y + 10000 back to address of y
    j   0x0 (r6)              # return with assumptation r6 stores next instruction address

// ------------------- TO DO: ----------
C_bar:
    mov r5, r0               # r5 point to *this in heap
    inca r0                   # inca moves to address of this->x
    ld  0x0 (r0), r1          # r1 = value of address of x
    inca r0                   # inca moves to address of this->y
    inca r0                   # inca moves to address of this->step
    ld  0x0 (r0), r2          # r2 = value of address of this->step
    add r2, r1                # r1 = this->x + this->step
    st  r1,   0x0 (r0)        # save x + 100 back to address of x
    mov r6, r7                # save current return address
    gpc $2, r6                # next instruction address after calling B_bar(me) i.e. r6 = pc + p*2
    j B_bar                   # call B_bar(me)
    mov r7, r6                # restore current return address
    j   0x0 (r6)              # return with assumptation r6 stores next instruction address

.pos 0x1000               # static data
a: .long 0xFFFFFFFF       # a = -1
b: .long 0xFFFFFFFF       # b = -1
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

.pos 0x3000               # stack
