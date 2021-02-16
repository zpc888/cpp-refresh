.pos 0x100
    ld  $i,   r0         # r0 = address of i
    ld  0x0 (r0), r0     # load r0 address 0x0 offset value into r0
                         # i.e. r0 = the value of i
    
    ld  $0xFFFFFFFD,   r1     # r1 = -3
    add r0, r1                # r1 = -3 + i = i - 3
    beq r1,   case_i_is_3     # i - 3 == 0

    ld  $0xFFFFFFFE,   r1     # r1 = -2
    add r0, r1                # r1 = -2 + i = i - 2
    beq r1,   case_i_is_2     # i - 2 == 0

    ld  $0xFFFFFFFF,   r1     # r1 = -1
    add r0, r1                # r1 = -1 + i = i - 1
    beq r1,   case_i_is_1     # i - 1 == 0

    beq r0,   case_i_is_0     # i = 0

    br  case_default          # else
case_i_is_0:
    ld  $0xa, r1              # r1 = 10
    br  switch_end
case_i_is_1:
    ld  $0xb, r1              # r1 = 11
    br  switch_end
case_i_is_2:
    ld  $0xc, r1              # r1 = 12
    br  switch_end
case_i_is_3:
    ld  $0xd, r1              # r1 = 13
    br  switch_end
case_default:
    ld  $0xe, r1              # r1 = 14

switch_end:
    ld  $j, r0           # r0 = address of j
    st  r1, 0x0 (r0)     # j = r1
    halt

.pos 0x1000
i: .long 0x00000002       # i = 2
j: .long 0xFFFFFFFF       # j = -1