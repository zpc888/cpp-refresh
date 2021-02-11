#
# int x = 6;
# 
# void increase() { 
#     x++; 
# }
#
# increase();
# x++;
#

.pos 0x100
    ld  $x,  r0           # r0 = address of x
    gpc $0x6, r5          # r5 = pc of next instruction
    j   increase          # jump to increase-label
    ld (r0),  r1          # r1 = value at address of (value of r0)
    inc r1                # r1 = r1 + 1; by now x = 7; r1 = 8
    st  r1,  0x0 (r0)     # store r1 value back to address of (value of r0); x++
    halt                  # by now x = 8
increase:
    ld (r0),  r1          # r1 = value at address of (value of r0)
    inc r1                # r1 = r1 + 1
    st  r1,  0x0 (r0)     # store r1 value back to address of (value of r0); x++
    j   (r5)              # return; pc = address of (value of r5)


.pos 0x1000
x: .long 0x00000006      # x = 6