#include "instructions.h"

t_instruction     g_instructions[] = {
  /* 3.3.1 - 8 Bits Loads */

  /* 1. LD nn, n */
  /* Description: Put value nn into n */
  /* Use with:  */
  /*     nn = B,C,D,E,H,L,BC,DE,HL,SP  */
  /*      n = 8 bit immediate value  */
  [0x06] = { "LD B, 0x%02x",         &i_ld8_b_n, 8, 2},
  [0x0e] = { "LD C, 0x%02x",         &i_ld8_c_n, 8, 2},
  [0x16] = { "LD D, 0x%02x",         &i_ld8_d_n, 8, 2},
  [0x1e] = { "LD E, 0x%02x",         &i_ld8_e_n, 8, 2},
  [0x26] = { "LD H, 0x%02x",         &i_ld8_h_n, 8, 2},
  [0x2e] = { "LD L, 0x%02x",         &i_ld8_l_n, 8, 2},

  /* 2. LD r1, r2 */
  /* Description: Put value r2 into r1 */
  /* Use with:  */
  /*     r1, r2 = A,B,C,D,E,H,L,(HL) */

  [0x7f] = { "LD A, A",         &i_ld8_a_a  , 4, 1},
  [0x78] = { "LD A, B",         &i_ld8_a_b  , 4, 1},
  [0x79] = { "LD A, C",         &i_ld8_a_c  , 4, 1},
  [0x7a] = { "LD A, D",         &i_ld8_a_d  , 4, 1},
  [0x7b] = { "LD A, E",         &i_ld8_a_e  , 4, 1},
  [0x7c] = { "LD A, H",         &i_ld8_a_h  , 4, 1},
  [0x7d] = { "LD A, L",         &i_ld8_a_l  , 4, 1},
  [0x7e] = { "LD A, (HL)",      &i_ld8_a_hl , 8, 1},
  [0x40] = { "LD B, B",         &i_ld8_b_b  , 4, 1},
  [0x41] = { "LD B, C",         &i_ld8_b_c  , 4, 1},
  [0x42] = { "LD B, D",         &i_ld8_b_d  , 4, 1},
  [0x43] = { "LD B, E",         &i_ld8_b_e  , 4, 1},
  [0x44] = { "LD B, H",         &i_ld8_b_h  , 4, 1},
  [0x45] = { "LD B, L",         &i_ld8_b_l  , 4, 1},
  [0x46] = { "LD B, (HL)",      &i_ld8_b_hl , 8, 1},
  [0x48] = { "LD C, B",         &i_ld8_c_b  , 4, 1},
  [0x49] = { "LD C, C",         &i_ld8_c_c  , 4, 1},
  [0x4a] = { "LD C, D",         &i_ld8_c_d  , 4, 1},
  [0x4b] = { "LD C, E",         &i_ld8_c_e  , 4, 1},
  [0x4c] = { "LD C, H",         &i_ld8_c_h  , 4, 1},
  [0x4d] = { "LD C, L",         &i_ld8_c_l  , 4, 1},
  [0x4e] = { "LD C, (HL)",      &i_ld8_c_hl , 8, 1},
  [0x50] = { "LD D, B",         &i_ld8_d_b  , 4, 1},
  [0x51] = { "LD D, C",         &i_ld8_d_c  , 4, 1},
  [0x52] = { "LD D, D",         &i_ld8_d_d  , 4, 1},
  [0x53] = { "LD D, E",         &i_ld8_d_e  , 4, 1},
  [0x54] = { "LD D, H",         &i_ld8_d_h  , 4, 1},
  [0x55] = { "LD D, L",         &i_ld8_d_l  , 4, 1},
  [0x56] = { "LD D, (HL)",      &i_ld8_d_hl , 8, 1},
  [0x58] = { "LD E, B",         &i_ld8_e_b  , 4, 1},
  [0x59] = { "LD E, C",         &i_ld8_e_c  , 4, 1},
  [0x5a] = { "LD E, D",         &i_ld8_e_d  , 4, 1},
  [0x5b] = { "LD E, E",         &i_ld8_e_e  , 4, 1},
  [0x5c] = { "LD E, H",         &i_ld8_e_h  , 4, 1},
  [0x5d] = { "LD E, L",         &i_ld8_e_l  , 4, 1},
  [0x5e] = { "LD E, (HL)",      &i_ld8_e_hl , 8, 1},
  [0x60] = { "LD H, B",         &i_ld8_h_b  , 4, 1},
  [0x61] = { "LD H, C",         &i_ld8_h_c  , 4, 1},
  [0x62] = { "LD H, D",         &i_ld8_h_d  , 4, 1},
  [0x63] = { "LD H, E",         &i_ld8_h_e  , 4, 1},
  [0x64] = { "LD H, H",         &i_ld8_h_h  , 4, 1},
  [0x65] = { "LD H, L",         &i_ld8_h_l  , 4, 1},
  [0x66] = { "LD H, (HL)",      &i_ld8_h_hl , 8, 1},
  [0x68] = { "LD L, B",         &i_ld8_l_b  , 4, 1},
  [0x69] = { "LD L, C",         &i_ld8_l_c  , 4, 1},
  [0x6a] = { "LD L, D",         &i_ld8_l_d  , 4, 1},
  [0x6b] = { "LD L, E",         &i_ld8_l_e  , 4, 1},
  [0x6c] = { "LD L, H",         &i_ld8_l_h  , 4, 1},
  [0x6d] = { "LD L, L",         &i_ld8_l_l  , 4, 1},
  [0x6e] = { "LD L, (HL)",      &i_ld8_l_hl , 8, 1},
  [0x70] = { "LD (HL), B",      &i_ld8_hl_b , 8, 1},
  [0x71] = { "LD (HL), C",      &i_ld8_hl_c , 8, 1},
  [0x72] = { "LD (HL), D",      &i_ld8_hl_d , 8, 1},
  [0x73] = { "LD (HL), E",      &i_ld8_hl_e , 8, 1},
  [0x74] = { "LD (HL), H",      &i_ld8_hl_h , 8, 1},
  [0x75] = { "LD (HL), L",      &i_ld8_hl_l , 8, 1},
  [0x36] = { "LD (HL), 0x%02x", &i_ld8_hl_n , 12, 2},

  /* 3. LD A, n */
  /* Description: Put value n into A */
  /* Use with:  */
  /*      n = A,B,C,D,E,H,L,(BC),(DE),(HL),(nn),# */
  /*     nn = two byte immediate value. (LS byte first.) */
  [0x0a] = { "LD A, (BC)",      &i_ld8_a_bc    , 8, 1},
  [0x1a] = { "LD A, (DE)",      &i_ld8_a_de    , 8, 1},
  [0xfa] = { "LD A, (0x%04x)",  &i_ld8_a_nn    , 16, 3},
  [0x3e] = { "LD A, 0x%02x",    &i_ld8_a_sharp , 8, 2},

  /* 4. LD n, A */
  /* Description: Put value A into n */
  /* Use with:  */
  /*      n = A,B,C,D,E,H,L,(BC),(DE),(HL),(nn) */
  /*     nn = two byte immediate value. (LS byte first.) */
  [0x47] = { "LD B, A",         &i_ld8_b_a , 4, 1},
  [0x4f] = { "LD C, A",         &i_ld8_c_a , 4, 1},
  [0x57] = { "LD D, A",         &i_ld8_d_a , 4, 1},
  [0x5f] = { "LD E, A",         &i_ld8_e_a , 4, 1},
  [0x67] = { "LD H, A",         &i_ld8_h_a , 4, 1},
  [0x6f] = { "LD L, A",         &i_ld8_l_a , 4, 1},
  [0x02] = { "LD (BC), A",      &i_ld8_bc_a, 8, 1},
  [0x12] = { "LD (DE), A",      &i_ld8_de_a, 8, 1},
  [0x77] = { "LD (HL), A",      &i_ld8_hl_a, 8, 1},
  [0xea] = { "LD (0x%04x), A",  &i_ld8_nn_a, 16, 3},

  /* 5. LD A, (C) */
  [0xf2] = { "LD A, ($FF00 + C)",       &i_ld8_a_cp, 8, 1},

  /* 6. LD (C), A */
  [0xe2] = { "LD ($FF00 + C), A", &i_ld8_cp_a, 8, 1},

  /* 7. LD A, (HLD) */
  /* Description: Same as: LDD A, (HL) */

  /* 8. LD A, (HL-) */
  /* Description: Same as: LDD A, (HL) */
 
  /* 9. LDD A, (HL) */
  /* Description: Put value at address HL into A. Decrement HL */
  /* Same as: LD A, (HL) - DEC HL */
  [0x3a] = { "LDD A, (HL)", &i_ldd8_a_hl, 8, 1},

  /* 10. LD (HLD), A */
  /* Description: Same as: LDD (HL), A */

  /* 11. LD (HL-), A */
  /* Description: Same as: LDD (HL), A */
 
  /* 12. LDD (HL), A */
  /* Description: Put A into memory address HL. Decrement HL */
  /* Same as: LD (HL), A - DEC HL */
  [0x32] = { "LDD (HL), A", &i_ldd8_hl_a, 8, 1},


  /* 13. LD A, (HLI) */
  /* Description: Same as: LDI A, (HL) */

  /* 14. LD A, (HL+) */
  /* Description: Same as: LDI A, (HL) */
 
  /* 15. LDI A, (HL) */
  /* Description: Put value at address HL into A. Increment HL */
  /* Same as: LD A, (HL) - INC HL */
  [0x2a] = { "LDI A, (HL)", &i_ldi8_a_hl, 8, 1},

  /* 16. LD (HLI), A */
  /* Description: Same as: LDD (HL), A */

  /* 17. LD (HL+), A */
  /* Description: Same as: LDD (HL), A */
 
  /* 18. LDI (HL), A */
  /* Description: Put A into memory address HL. Increment HL */
  /* Same as: LD (HL), A - INC HL */
  [0x22] = { "LDI (HL), A", &i_ldi8_hl_a, 8, 1},

  /* 19. LDH (n), A */
  /* Description: Put A into memory address $FF00+n */
  /* Use with: n = one byte immediate value. */
  [0xe0] = { "LD ($FF00 + 0x%02x), A", &i_ld_ff00_n_a, 12, 2},
 
  /* 20. LDH A, (n) */
  /* Description: Put memory address $FF00+n into A */
  /* Use with: n = one byte immediate value */
  [0xf0] = { "LD A, ($FF00 + 0x%02x)", &i_ld_a_ff00_n, 12, 2},
  

  /* 3.3.2 - 16 Bits Loads */
  

  /* 1. LD n, nn */
  /* Description: Put value nn into n */
  /* Use With:  */
  /* n = BC, DE, HL, SP */
  /* nn = 16 bit immediate value */
  [0x01] = { "LD BC, 0x%04x", &i_ld16_bc_nn, 12, 3},
  [0x11] = { "LD DE, 0x%04x", &i_ld16_de_nn, 12, 3},
  [0x21] = { "LD HL, 0x%04x", &i_ld16_hl_nn, 12, 3},
  [0x31] = { "LD SP, 0x%04x", &i_ld16_sp_nn, 12, 3},

  /* 2. LD SP, HL */
  /* Description: Put HL into Stack Pointer (SP) */
  [0xf9] = { "LD SP, HL", &i_ld16_sp_hl, 8, 1},

  /* 3. LD HL, SP+n */
  /* Description: Same as: LDHL SP, n */

  /* 4. LDHL SP, n */
  /* Description: */
  /*     Put SP + n effective address into HL */
  /* Use with: */
  /*     n = one byte signed immediate value */
  /* Flags affected */
  /*     Z - Reset. */
  /*     N - Reset. */
  /*     H - Set or reset according to operation. */
  /*     C - Set or reset according to operation. */
  [0xf8] = { "LDHL SP, 0x%02x", &i_ld16_hl_sp_n, 12, 2},
 

  /* 5. LD (nn), SP */
  /* Description: */
  /*     Put Stack Pointer (SP) at address n. */
  /* Use with: */
  /*     nn = two byte immediate address. */
  [0x08] = { "LD (0x%04x) SP", &i_ld16_nn_sp, 20, 3},

  /* 6. PUSH nn */
  /* Description: */
  /*     Push register pair nn onto stack. */
  /*     Decrement Stack Pointer (SP) twice. */
  /* Use with: */
  /*     nn = AF, BC, DE, HL */
  [0xf5] = { "PUSH AF", &i_push_af, 16, 1},
  [0xc5] = { "PUSH BC", &i_push_bc, 16, 1},
  [0xd5] = { "PUSH DE", &i_push_de, 16, 1},
  [0xe5] = { "PUSH HL", &i_push_hl, 16, 1},
  
  /* 7. POP nn */
  /* Description: */
  /*     Pop two bytes off stack into register pair nn. */
  /*     Increment Stack Pointer (SP) twice. */
  /* Use with: */
  /*     nn = AF, BC, DE, HL */
  [0xf1] = { "POP AF", &i_pop_af, 12, 1},
  [0xc1] = { "POP BC", &i_pop_bc, 12, 1},
  [0xd1] = { "POP DE", &i_pop_de, 12, 1},
  [0xe1] = { "POP HL", &i_pop_hl, 12, 1},

  /* 3.3.3 - 8 Bit ALU */

  /* 1.ADD A, n */
  /* Description: */
  /*     Add n to A. */
  /* Use with: */
  /*     n = A, B, C, D, E, H, L, (HL), #. */
  /* Flags affected: */
  /*     Z - Set if result is zero */
  /*     N - Reset */
  /*     H - Set if carry from bit 3 */
  /*     C - Set if carry from bit 7 */
  [0x87] = { "ADD A, A",    &i_add8_a_a    , 4, 1},
  [0x80] = { "ADD A, B",    &i_add8_a_b    , 4, 1},
  [0x81] = { "ADD A, C",    &i_add8_a_c    , 4, 1},
  [0x82] = { "ADD A, D",    &i_add8_a_d    , 4, 1},
  [0x83] = { "ADD A, E",    &i_add8_a_e    , 4, 1},
  [0x84] = { "ADD A, H",    &i_add8_a_h    , 4, 1},
  [0x85] = { "ADD A, L",    &i_add8_a_l    , 4, 1},
  [0x86] = { "ADD A, (HL)", &i_add8_a_hl   , 8, 1},
  [0xc6] = { "ADD A, 0x%02x",    &i_add8_a_sharp, 8, 2},

  /* 2.ADC A, n */
  /* Description: */
  /*     Add n + Carry flag to A. */
  /* Use with: */
  /*     n = A, B, C, D, E, H, L, (HL), #. */
  /* Flags affected: */
  /*     Z - Set if result is zero */
  /*     N - Reset */
  /*     H - Set if carry from bit 3 */
  /*     C - Set if carry from bit 7 */
  [0x8f] = { "ADC A, A",    &i_adc8_a_a    , 4, 1},
  [0x88] = { "ADC A, B",    &i_adc8_a_b    , 4, 1},
  [0x89] = { "ADC A, C",    &i_adc8_a_c    , 4, 1},
  [0x8a] = { "ADC A, D",    &i_adc8_a_d    , 4, 1},
  [0x8b] = { "ADC A, E",    &i_adc8_a_e    , 4, 1},
  [0x8c] = { "ADC A, H",    &i_adc8_a_h    , 4, 1},
  [0x8d] = { "ADC A, L",    &i_adc8_a_l    , 4, 1},
  [0x8e] = { "ADC A, (HL)", &i_adc8_a_hl   , 8, 1},
  [0xce] = { "ADC A, 0x%02x",    &i_adc8_a_sharp, 8, 1},

  /* SUB n */
  /* Description: */
  /*     Substract n from A */
  /* Use with: */
  /*     n = A, B, C, D, E, H, L, (HL), # */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Set. */
  /*     H - Set if no borrow from bit 4. */
  /*     C - Set if no borrow. */
  [0x97] = { "SUB A",    &i_sub8_a_a    , 4, 1},
  [0x90] = { "SUB B",    &i_sub8_a_b    , 4, 1},
  [0x91] = { "SUB C",    &i_sub8_a_c    , 4, 1},
  [0x92] = { "SUB D",    &i_sub8_a_d    , 4, 1},
  [0x93] = { "SUB E",    &i_sub8_a_e    , 4, 1},
  [0x94] = { "SUB H",    &i_sub8_a_h    , 4, 1},
  [0x95] = { "SUB L",    &i_sub8_a_l    , 4, 1},
  [0x96] = { "SUB (HL)", &i_sub8_a_hl   , 8, 1},
  [0xd6] = { "SUB 0x%02x",    &i_sub8_a_sharp, 8, 2},

  /* 4. SBC A, n */
  /* Description: */
  /*     Substract n + Carry flag from A. */
  /* Use with: */
  /*     n = A, B, C, D, E, H, L, (HL), # */
  /* Use with: */
  /*     Z - Set if result is zero. */
  /*     N - Set. */
  /*     H - Set if no borrow from bit 4. */
  /*     C - Set if no borrow. */
  [0x9f] = { "SBC A, A",    &i_sbc8_a_a    , 4, 1},
  [0x98] = { "SBC A, B",    &i_sbc8_a_b    , 4, 1},
  [0x99] = { "SBC A, C",    &i_sbc8_a_c    , 4, 1},
  [0x9a] = { "SBC A, D",    &i_sbc8_a_d    , 4, 1},
  [0x9b] = { "SBC A, E",    &i_sbc8_a_e    , 4, 1},
  [0x9c] = { "SBC A, H",    &i_sbc8_a_h    , 4, 1},
  [0x9d] = { "SBC A, L",    &i_sbc8_a_l    , 4, 1},
  [0x9e] = { "SBC A, (HL)", &i_sbc8_a_hl   , 8, 1},
  /* {0x??, "SUB A, #", &unimplemented_instruction, ??, 2}, */

  /* 5. AND n */
  /* Description: */
  /*     Logically AND n with A, result in A. */
  /* Use with: */
  /*     n = A, B, C, D, E, H, L, (HL), # */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Set. */
  /*     C - Reset. */
  [0xa7] = { "AND A",    &i_and_a    , 4, 1},
  [0xa0] = { "AND B",    &i_and_b    , 4, 1},
  [0xa1] = { "AND C",    &i_and_c    , 4, 1},
  [0xa2] = { "AND D",    &i_and_d    , 4, 1},
  [0xa3] = { "AND E",    &i_and_e    , 4, 1},
  [0xa4] = { "AND H",    &i_and_h    , 4, 1},
  [0xa5] = { "AND L",    &i_and_l    , 4, 1},
  [0xa6] = { "AND (HL)", &i_and_hl   , 8, 1},
  [0xe6] = { "AND 0x%02x",    &i_and_sharp, 8, 2},

  /* 6. OR n */
  /* Description: */
  /*     Logically OR n with A, result in A. */
  /* Use with: */
  /*     n = A, B, C, D, E, H, L, (HL), # */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Reset. */
  [0xb7] = { "OR A",    &i_or_a    , 4, 1},
  [0xb0] = { "OR B",    &i_or_b    , 4, 1},
  [0xb1] = { "OR C",    &i_or_c    , 4, 1},
  [0xb2] = { "OR D",    &i_or_d    , 4, 1},
  [0xb3] = { "OR E",    &i_or_e    , 4, 1},
  [0xb4] = { "OR H",    &i_or_h    , 4, 1},
  [0xb5] = { "OR L",    &i_or_l    , 4, 1},
  [0xb6] = { "OR (HL)", &i_or_hl   , 8, 1},
  [0xf6] = { "OR 0x%02x",    &i_or_sharp, 8, 2},

  /* 7. XOR n */
  /* Description: */
  /*     Logically exclusive OR n with A, result in A. */
  /* Use with: */
  /*     n = A, B, C, D, E, H, L, (HL), # */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Reset. */
  [0xaf] = { "XOR A",    &i_xor_a    , 4, 1},
  [0xa8] = { "XOR B",    &i_xor_b    , 4, 1},
  [0xa9] = { "XOR C",    &i_xor_c    , 4, 1},
  [0xaa] = { "XOR D",    &i_xor_d    , 4, 1},
  [0xab] = { "XOR E",    &i_xor_e    , 4, 1},
  [0xac] = { "XOR H",    &i_xor_h    , 4, 1},
  [0xad] = { "XOR L",    &i_xor_l    , 4, 1},
  [0xae] = { "XOR (HL)", &i_xor_hl   , 8, 1},
  [0xee] = { "XOR 0x%02x",    &i_xor_sharp, 8, 2},


  /* 8. CP n */
  /* Description: */
  /*     Compare A with n. This is basically an A - n substraction instruction but the results are thrown away */
  /* Use with: */
  /*     n = A, B, C, D, E, H, L, (HL), # */
  /* Flags affected: */
  /*     Z - Set if result is zero. (Set if A = n.) */
  /*     N - Set. */
  /*     H - Set if no borrow from bit 4. */
  /*     C - Set for no borrow. (Set if A < n.) */
  [0xbf] = { "CP A",        &i_cp_a    , 4, 1},
  [0xb8] = { "CP B",        &i_cp_b    , 4, 1},
  [0xb9] = { "CP C",        &i_cp_c    , 4, 1},
  [0xba] = { "CP D",        &i_cp_d    , 4, 1},
  [0xbb] = { "CP E",        &i_cp_e    , 4, 1},
  [0xbc] = { "CP H",        &i_cp_h    , 4, 1},
  [0xbd] = { "CP L",        &i_cp_l    , 4, 1},
  [0xbe] = { "CP (HL) ",    &i_cp_hl   , 8, 1},
  [0xfe] = { "CP 0x%02x ",    &i_cp_sharp, 8, 2},

  /* 9. INC n */
  /* Description: */
  /*     Increment register n */
  /* Use with: */
  /*     n = A, B, C, D, E, H, L, (HL), # */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Set if carry from bit 3. */
  /*     C - Not affected */
  [0x3c] = { "INC A",    &i_inc_a , 4, 1},
  [0x04] = { "INC B",    &i_inc_b , 4, 1},
  [0x0c] = { "INC C",    &i_inc_c , 4, 1},
  [0x14] = { "INC D",    &i_inc_d , 4, 1},
  [0x1c] = { "INC E",    &i_inc_e , 4, 1},
  [0x24] = { "INC H",    &i_inc_h , 4, 1},
  [0x2c] = { "INC L",    &i_inc_l , 4, 1},
  [0x34] = { "INC (HL)", &i_inc_hl, 8, 1},

  /* 10. DEC n */
  /* Description: */
  /*     Decrement register n */
  /* Use with: */
  /*     n = A, B, C, D, E, H, L, (HL), # */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Set. */
  /*     H - Set if no borrow from bit 4. */
  /*     C - Not affected */
  [0x3d] = { "DEC A",    &i_dec_a , 4,  1},
  [0x05] = { "DEC B",    &i_dec_b , 4,  1},
  [0x0d] = { "DEC C",    &i_dec_c , 4,  1},
  [0x15] = { "DEC D",    &i_dec_d , 4,  1},
  [0x1d] = { "DEC E",    &i_dec_e , 4,  1},
  [0x25] = { "DEC H",    &i_dec_h , 4,  1},
  [0x2d] = { "DEC L",    &i_dec_l , 4,  1},
  [0x35] = { "DEC (HL)", &i_dec_hl, 12, 1},

  /* 3.3.4 - 16 Bit Arithmetic */
  
  /* 1. ADD HL, n */
  /* Description: */
  /*     Add n to HL. */
  /* Use with: */
  /*     n = BC, DE, HL, SP */
  /* Flags affected: */
  /*     Z - Not affected. */
  /*     N - Reset. */
  /*     H - Set if carry from bit 11. */
  /*     C - Set if carry from bit 15. */
  [0x09] = { "ADD HL, BC", &i_add16_hl_bc, 8, 1},
  [0x19] = { "ADD HL, DE", &i_add16_hl_de, 8, 1},
  [0x29] = { "ADD HL, HL", &i_add16_hl_hl, 8, 1},
  [0x39] = { "ADD HL, SP", &i_add16_hl_sp, 8, 1},
  

  /* 2. ADD SP, n */
  /* Description: */
  /*     Add n to Stack Pointer (SP). */
  /* Use with: */
  /*     n = one byte signed immediate value (#). */
  /* Flags affected: */
  /*     Z - Reset. */
  /*     N - Reset. */
  /*     H - Set or reset according to operation. */
  /*     C - Set or reset according to operation. */
  [0xe8] = { "ADD SP, 0x%02x", &i_add_sp_sharp, 16, 2},

  /* 3. INC nn */
  /* Description: */
  /*     Increment register nn. */
  /* Use with: */
  /*     nn = BC, DE, HL, SP. */
  /* Flags affected: */
  /*     None. */
  [0x03] = { "INC BC", &i_inc_d_bc, 8, 1},
  [0x13] = { "INC DE", &i_inc_d_de, 8, 1},
  [0x23] = { "INC HL", &i_inc_d_hl, 8, 1},
  [0x33] = { "INC SP", &i_inc_d_sp, 8, 1},

  /* 3. DEC nn */
  /* Description: */
  /*     Decrement register nn. */
  /* Use with: */
  /*     nn = BC, DE, HL, SP. */
  /* Flags affected: */
  /*     None. */
  [0x0b] = { "DEC BC", &i_dec_d_bc, 8, 1},
  [0x1b] = { "DEC DE", &i_dec_d_de, 8, 1},
  [0x2b] = { "DEC HL", &i_dec_d_hl, 8, 1},
  [0x3b] = { "DEC SP", &i_dec_d_sp, 8, 1},

  /* 3.3.5 Miscellaneous */


  /* 2. DAA */
  /* Description: */
  /*     Decimal adjust register A. */
  /*     This instruction adjusts register A so that the */
  /*     correct representation of Binary Coded Decimal (BCD) is obtained. */
  /* Flags affected: */
  /*     Z - Set if register A is zero. */
  /*     N - Not affected. */
  /*     H - Reset. */
  /*     C - Set or reset according to operation. */
  [0x27] = { "DDA", &i_daa, 4, 1},

  /* 3. CPL */
  /* Description: */
  /*     Complement A register. (Flip all bits.) */
  /* Flags affected: */
  /*     Z - Not affected. */
  /*     N - Set. */
  /*     H - Set. */
  /*     C - Not affected. */
  [0x2f] = { "CPL", &i_cpl, 4, 1},

  /* 4. CCF */
  /* Description: */
  /*     Complement carry flag. */
  /*     If C flag is set, then reset it. */
  /*     If C flag is reset, then set it. */
  /* Flags affected: */
  /*     Z - Not affected. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Complemented */
  [0x3f] = { "CCF", &i_ccf, 4, 1},

  /* 5. SCF */
  /* Description: */
  /*     Set carry flag. */
  /* Flags affected: */
  /*     Z - Not affected. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Set */

  /* 6. NOP */
  /* Description: */
  /*     No operation. */
  [0x00] = { "NOP", &i_nop, 4, 1},

  /* 7. HALT */
  /* Description: */
  /*     Power down PU until an interrupt occurs. */
  /*     Use this when ever possible to reduce energy consumption. */
  [0x76] = { "HALT", &i_halt, 4, 1},

  /* 8. STOP */
  /* Description: */
  /*     Halt CPU & LCD display until button pressed. */
  [0x10] = { "STOP", &i_stop, 4, 2},
  
  /* 9. DI */
  /* Description: */
  /*     This instruction disables interrupts but not immediately. */
  /*     Interrupts are disabled after instruction after DI is executed. */
  [0xf3] = { "DI", &i_di, 4, 1},

  /* 10. EI */
  /* Description: */
  /*     Enable interrupts. */
  /*     This instruction enables interrupts but not immediately. */
  /*     Interrupts are enabled after instruction after EI is executed. */
  [0xfb] = { "EI", &i_ei, 4, 1},

  /* 3.3.6 Rotates & Shifts */

  /* 1. RLCA */
  /* Description: */
  /*     Rotate A left. Old bit 7 Carry flag. */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 7 data. */
  [0x07] = { "RLCA", &i_rlca, 4, 1},

  /* 2. RLA */
  /* Description: */
  /*     Rotate A left through Carry flag. */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 7 data. */
  [0x17] = { "RLA", &i_rla, 4, 1},

  /* 3. RRCA */
  /* Description: */
  /*     Rotate A right. Old bit 0 to Carry flag. */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 0 data. */
  [0x0f] = { "RRCA", &i_rrca, 4, 1},

  /* 4. RRA */
  /* Description: */
  /*     Rotate A right through Carry flag. */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 0 data. */
  [0x1f] = { "RRA", &i_rra, 4, 1},

  /* 3.3.8 - Jumps */

  /* 1. JP nn */
  /* Description: */
  /*     Jump to address nn. */
  /* Use with: */
  /*     nn = two byte immediate value. (LS byte first) */
  [0xc3] = { "JP 0x%04x", &i_jp_nn, 12, 3},
  

  /* 2. JP cc, nn */
  /* Description: */
  /*     Jump to address n if following condition is true. */
  /*     cc = NZ, Jump if Z flag is reset. */
  /*     cc = Z, Jump if Z flag is set. */
  /*     cc = NC, Jump if C flag is reset. */
  /*     cc = C, Jump if C flag is set. */
  /* Use with: */
  /*     nn = two byte immediate value. (LS byte first) */
  [0xc2] = { "JP NZ, 0x%04x", &i_jp_nz_nn, 12, 3},
  [0xca] = { "JP Z, 0x%04x",  &i_jp_z_nn,  12, 3},
  [0xd2] = { "JP NC, 0x%04x", &i_jp_nc_nn, 12, 3},
  [0xda] = { "JP C, 0x%04x",  &i_jp_c_nn,  12, 3},

  /* 3. JP (HL) */
  /* Description: */
  /*     Jump to address contained in HL. */
  [0xe9] = { "JP (HL)", &i_jp_hl, 4, 1},

  /* 4. JP n */
  /* Description: */
  /*     Add n to current address and jump to it. */
  /* Use with: */
  /*     n = one byte signed immediate value */
  [0x18] = { "JP 0x%02x", &i_jp_n, 8, 2},

  /* 5. JR cc, n */
  /* Description: */
  /*     If following condition is true then add n to current address and jump to it. */
  /*     cc = NZ, Jump if Z flag is reset. */
  /*     cc = Z, Jump if Z flag is set. */
  /*     cc = NC, Jump if C flag is reset. */
  /*     cc = C, Jump if C flag is set. */
  /* Use with: */
  /*     n = one byte signed immediate value. */
  [0x20] = { "JR NZ, 0x%02x", &i_jr_nz_sharp, 8, 2},
  [0x28] = { "JR Z, 0x%02x",  &i_jr_z_sharp, 8, 2},
  [0x30] = { "JR NC, 0x%02x", &i_jr_nc_sharp, 8, 2},
  [0x38] = { "JR C, 0x%02x",  &i_jr_c_sharp, 8, 2},

  /* 3.3.9 - Calls */


  /* 1. CALL nn */
  /* Description: */
  /*     Push address of next instruction onto stack and then jump to address nn. */
  /* Use with: */
  /*     nn = two byte immediate value. (LS byte first). */
  [0xcd] = { "CALL 0x%04x", &i_call_nn, 12, 3},


  /* 2. CALL cc, nn */
  /* Description: */
  /*     Call address n if following condition is true: */
  /*     cc = NZ, Call if Z flag is reset */
  /*     cc = Z, Call if Z flag is set */
  /*     cc = NC, Call if C flag is reset */
  /*     cc = C, Call if C flag is set */
  /* Use with: */
  /*     nn = two byte immediate value. (LS byte first). */
  [0xc4] = { "CALL NZ, 0x%02x", &i_call_nz_nn, 12, 2},
  [0xcc] = { "CALL Z, 0x%02x",  &i_call_z_nn , 12, 2},
  [0xd4] = { "CALL NC, 0x%02x", &i_call_nc_nn, 12, 2},
  [0xdc] = { "CALL C, 0x%02x",  &i_call_c_nn , 12, 2},


  /* 3.3.10 - Restarts */

  /* 1. RST n */
  /* Description: */
  /*     Push present address onto stack. */
  /*     Jump to address $0000 + n. */
  /* Use with: */
  /*     n = $00, $08, $10, $18, $20, $28, $30, $38 */
  [0xc7] = { "RST 00H", &i_rst_00,  32, 1},
  [0xcf] = { "RST 08H", &i_rst_08,  32, 1},
  [0xd7] = { "RST 10H", &i_rst_10,  32, 1},
  [0xdf] = { "RST 18H", &i_rst_18,  32, 1},
  [0xe7] = { "RST 20H", &i_rst_20,  32, 1},
  [0xef] = { "RST 28H", &i_rst_28,  32, 1},
  [0xf7] = { "RST 30H", &i_rst_30,  32, 1},
  [0xff] = { "RST 38H", &i_rst_38,  32, 1},

  /* 3.3.11 - Returns */

  /* 1. RET */
  /* Description: */
  /*     Pop two bytes from stack & jump to that address. */
  [0xc9] = { "RET", &i_ret, 8, 1},

  /* 2. RET cc */
  /* Description: */
  /*     Return if following condition is true. */
  /* Use with: */
  /*     cc = NZ, Return if Z flag is reset. */
  /*     cc = Z, Return if Z flag is set. */
  /*     cc = NC, Return if C flag is reset. */
  /*     cc = C, Return if C flag is set. */
  [0xc0] = { "RET NZ", &i_ret_nz, 8, 1},
  [0xc8] = { "RET Z",  &i_ret_z , 8, 1},
  [0xd0] = { "RET NC", &i_ret_nc, 8, 1},
  [0xd8] = { "RET C",  &i_ret_c , 8, 1},

  /* 3. RETI */
  /* Description: */
  /*     Pop two bytes from stack & jump to that address then enable interrupts. */
  [0xd9] = { "RETI", &i_reti, 8, 1},

  /* Non-Documented */
  [0xcb] = { "PREFIX", &i_prefix, 4, 1},

  [0xd3] = { "UNKNOWN!", &unimplemented_instruction, 0, 1},
  [0xdb] = { "UNKNOWN!", &unimplemented_instruction, 0, 1},
  [0xdd] = { "UNKNOWN!", &unimplemented_instruction, 0, 1},
  [0xde] = { "UNKNOWN!", &unimplemented_instruction, 0, 1},
  [0xe3] = { "UNKNOWN!", &unimplemented_instruction, 0, 1},
  [0xe4] = { "UNKNOWN!", &unimplemented_instruction, 0, 1},
  [0xeb] = { "UNKNOWN!", &unimplemented_instruction, 0, 1},
  [0xec] = { "UNKNOWN!", &unimplemented_instruction, 0, 1},
  [0xed] = { "UNKNOWN!", &unimplemented_instruction, 0, 1},
  [0xf4] = { "UNKNOWN!", &unimplemented_instruction, 0, 1},
  [0xfc] = { "UNKNOWN!", &unimplemented_instruction, 0, 1},
  [0xfd] = { "UNKNOWN!", &unimplemented_instruction, 0, 1},
};

t_instruction     g_instructions_cb[] = {

  /* SWAP n */
  /* Description: */
  /*     Swap upper & lower nibles of n. */
  /* Use with: */
  /*     n = A, B, C, D, E, H, L, (HL). */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Reset. */

  [0x37] = {"SWAP A",    &i_swap_a , 8, 1},
  [0x30] = {"SWAP B",    &i_swap_b , 8, 1},
  [0x31] = {"SWAP C",    &i_swap_c , 8, 1},
  [0x32] = {"SWAP D",    &i_swap_d , 8, 1},
  [0x33] = {"SWAP E",    &i_swap_e , 8, 1},
  [0x34] = {"SWAP H",    &i_swap_h , 8, 1},
  [0x35] = {"SWAP L",    &i_swap_l , 8, 1},
  [0x36] = {"SWAP (HL)", &i_swap_hl, 16, 1},

  /* RLC n */
  /* Description: */
  /*     Rotate n left. Old bit 7 to Carry flag. */
  /* Use with: */
  /*     n = A,B,C,D,E,H,L,(HL) */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 7 data. */

  [0x07] = {"RLC A",       &i_rlc_a , 8, 1},
  [0x00] = {"RLC B",       &i_rlc_b , 8, 1},
  [0x01] = {"RLC C",       &i_rlc_c , 8, 1},
  [0x02] = {"RLC D",       &i_rlc_d , 8, 1},
  [0x03] = {"RLC E",       &i_rlc_e , 8, 1},
  [0x04] = {"RLC H",       &i_rlc_h , 8, 1},
  [0x05] = {"RLC L",       &i_rlc_l , 8, 1},
  [0x06] = {"RLC (HL)",    &i_rlc_hl, 16, 1},

  /* RL n */
  /* Description: */
  /*     Rotate n left through Carry flag. */
  /* Use with: */
  /*     n = A,B,C,D,E,H,L,(HL) */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 7 data. */

  [0x17] = {"RL A",          &i_rl_a , 8, 1},
  [0x10] = {"RL B",          &i_rl_b , 8, 1},
  [0x11] = {"RL C",          &i_rl_c , 8, 1},
  [0x12] = {"RL D",          &i_rl_d , 8, 1},
  [0x13] = {"RL E",          &i_rl_e , 8, 1},
  [0x14] = {"RL H",          &i_rl_h , 8, 1},
  [0x15] = {"RL L",          &i_rl_l , 8, 1},
  [0x16] = {"RL (HL)",       &i_rl_hl, 16, 1},

  /* RRC n */
  /* Description: */
  /*     Rotate n right. Old bit 0 to Carry flag. */
  /* Use with: */
  /*     n = A,B,C,D,E,H,L,(HL) */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 0 data. */

  [0x0f] = {"RRC A",          &i_rrc_a , 8, 1},
  [0x08] = {"RRC B",          &i_rrc_b , 8, 1},
  [0x09] = {"RRC C",          &i_rrc_c , 8, 1},
  [0x0a] = {"RRC D",          &i_rrc_d , 8, 1},
  [0x0b] = {"RRC E",          &i_rrc_e , 8, 1},
  [0x0c] = {"RRC H",          &i_rrc_h , 8, 1},
  [0x0d] = {"RRC L",          &i_rrc_l , 8, 1},
  [0x0e] = {"RRC (HL)",       &i_rrc_hl, 16, 1},

  /* RR n */
  /* Description: */
  /*     Rotate n right through Carry flag. */
  /* Use with: */
  /*     n = A,B,C,D,E,H,L,(HL) */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 0 data. */
  [0x1f] = {"RR A",          &i_rr_a , 8, 1},
  [0x18] = {"RR B",          &i_rr_b , 8, 1},
  [0x19] = {"RR C",          &i_rr_c , 8, 1},
  [0x1a] = {"RR D",          &i_rr_d , 8, 1},
  [0x1b] = {"RR E",          &i_rr_e , 8, 1},
  [0x1c] = {"RR H",          &i_rr_h , 8, 1},
  [0x1d] = {"RR L",          &i_rr_l , 8, 1},
  [0x1e] = {"RR (HL)",       &i_rr_hl, 16, 1},

  /* SLA n */
  /* Description: */
  /*     Shift n left into Carry. LSB of n set to 0. */
  /* Use with: */
  /*     n = A,B,C,D,E,H,L,(HL) */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 7 data. */
  [0x27] = {"SLA A",          &i_sla_a , 8, 1},
  [0x20] = {"SLA B",          &i_sla_b , 8, 1},
  [0x21] = {"SLA C",          &i_sla_c , 8, 1},
  [0x22] = {"SLA D",          &i_sla_d , 8, 1},
  [0x23] = {"SLA E",          &i_sla_e , 8, 1},
  [0x24] = {"SLA H",          &i_sla_h , 8, 1},
  [0x25] = {"SLA L",          &i_sla_l , 8, 1},
  [0x26] = {"SLA (HL)",       &i_sla_hl, 16, 1},

  /*  SRA n */
  /* Description: */
  /*     Shift n right into Carry. MSB doesn't change. */
  /* Use with: */
  /*     n = A,B,C,D,E,H,L,(HL) */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 0 data. */

  [0x2f] = {"SRA A",          &i_sra_a , 8, 1},
  [0x28] = {"SRA B",          &i_sra_b , 8, 1},
  [0x29] = {"SRA C",          &i_sra_c , 8, 1},
  [0x2a] = {"SRA D",          &i_sra_d , 8, 1},
  [0x2b] = {"SRA E",          &i_sra_e , 8, 1},
  [0x2c] = {"SRA H",          &i_sra_h , 8, 1},
  [0x2d] = {"SRA L",          &i_sra_l , 8, 1},
  [0x2e] = {"SRA (HL)",       &i_sra_hl, 16, 1},

  /* SRL n */
  /* Description: */
  /*     Shift n right into Carry. MSB set to 0. */
  /* Use with: */
  /*     n = A,B,C,D,E,H,L,(HL) */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 0 data. */

  [0x3f] = {"SRL A",          &i_srl_a , 8, 1},
  [0x38] = {"SRL B",          &i_srl_b , 8, 1},
  [0x39] = {"SRL C",          &i_srl_c , 8, 1},
  [0x3a] = {"SRL D",          &i_srl_d , 8, 1},
  [0x3b] = {"SRL E",          &i_srl_e , 8, 1},
  [0x3c] = {"SRL H",          &i_srl_h , 8, 1},
  [0x3d] = {"SRL L",          &i_srl_l , 8, 1},
  [0x3e] = {"SRL (HL)",       &i_srl_hl, 16, 1},

  /* 3.3.7 - Bit Opcodes */

  /* BIT b, r */
  /* Description: */
  /*     Test bit b in register r. */
  /* Use with: */
  /*     b = 0 - 7, r = A, B, C, D, E, H, L, (HL) */
  /* Flags affected: */
  /*     Z - Set if bit b of register r is 0. */
  /*     N - Reset. */
  /*     H - Set. */
  /*     C - Not affected. */

  [0x47] = {"BIT 0x%02x, A",       &i_bit_a , 8,  2},
  [0x40] = {"BIT 0x%02x, B",       &i_bit_b , 8,  2},
  [0x41] = {"BIT 0x%02x, C",       &i_bit_c , 8,  2},
  [0x42] = {"BIT 0x%02x, D",       &i_bit_d , 8,  2},
  [0x43] = {"BIT 0x%02x, E",       &i_bit_e , 8,  2},
  [0x44] = {"BIT 0x%02x, H",       &i_bit_h , 8,  2},
  [0x45] = {"BIT 0x%02x, L",       &i_bit_l , 8,  2},
  [0x46] = {"BIT 0x%02x, (HL)",    &i_bit_hl, 16, 2},

  /* SET b, r */
  /* Description: */
  /*     Set bit b in register r. */
  /* Use with: */
  /*     b = 0 - 7, r = A, B, C, D, E, H, L, (HL) */

  [0xc7] = {"SET 0x%02x, A",       &i_set_a , 8,  2},
  [0xc0] = {"SET 0x%02x, B",       &i_set_b , 8,  2},
  [0xc1] = {"SET 0x%02x, C",       &i_set_c , 8,  2},
  [0xc2] = {"SET 0x%02x, D",       &i_set_d , 8,  2},
  [0xc3] = {"SET 0x%02x, E",       &i_set_e , 8,  2},
  [0xc4] = {"SET 0x%02x, H",       &i_set_h , 8,  2},
  [0xc5] = {"SET 0x%02x, L",       &i_set_l , 8,  2},
  [0xc6] = {"SET 0x%02x, (HL)",    &i_set_hl, 16, 2},

  /* RES b, r */
  /* Description: */
  /*     Reset bit b in register r. */
  /* Use with: */
  /*     b = 0 - 7, r = A, B, C, D, E, H, L, (HL) */

  [0x87] = {"RES 0x%02x, A",       &i_res_a , 8,  2},
  [0x80] = {"RES 0x%02x, B",       &i_res_b , 8,  2},
  [0x81] = {"RES 0x%02x, C",       &i_res_c , 8,  2},
  [0x82] = {"RES 0x%02x, D",       &i_res_d , 8,  2},
  [0x83] = {"RES 0x%02x, E",       &i_res_e , 8,  2},
  [0x84] = {"RES 0x%02x, H",       &i_res_h , 8,  2},
  [0x85] = {"RES 0x%02x, L",       &i_res_l , 8,  2},
  [0x86] = {"RES 0x%02x, (HL)",    &i_res_hl, 16, 2},
};
