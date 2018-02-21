#include "instructions.h"

const t_instruction     g_instructions[] = {
  /* 3.3.1 - 8 Bits Loads */

  /* 1. LD nn, n */
  /* Description: Put value nn into n */
  /* Use with:  */
  /*     nn = B,C,D,E,H,L,BC,DE,HL,SP  */
  /*      n = 8 bit immediate value  */
  [0x06] = { "LD B, n",         &i_ld8_b_n, 8, 2},
  [0x0e] = { "LD C, n",         &i_ld8_c_n, 8, 2},
  [0x16] = { "LD D, n",         &i_ld8_d_n, 8, 2},
  [0x1e] = { "LD E, n",         &i_ld8_e_n, 8, 2},
  [0x26] = { "LD H, n",         &i_ld8_h_n, 8, 2},
  [0x2e] = { "LD L, n",         &i_ld8_l_n, 8, 2},

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
  [0x36] = { "LD (HL), n",      &i_ld8_hl_n , 12, 2},

  /* 3. LD A, n */
  /* Description: Put value n into A */
  /* Use with:  */
  /*      n = A,B,C,D,E,H,L,(BC),(DE),(HL),(nn),# */
  /*     nn = two byte immediate value. (LS byte first.) */
  [0x0a] = { "LD A, (BC)", &i_ld8_a_bc    , 8, 1},
  [0x1a] = { "LD A, (DE)", &i_ld8_a_de    , 8, 1},
  [0xfa] = { "LD A, (nn)", &i_ld8_a_nn    , 16, 1},
  [0x3e] = { "LD A, #",    &i_ld8_a_sharp , 8, 1},

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
  [0xea] = { "LD (nn), A",      &i_ld8_nn_a, 16, 1},

  /* 5. LD A, (C) */
  [0xf2] = { "LD A, ($FF00 + C)",       &i_ld8_a_cp, 8, 1},

  /* 6. LD (C), A */
  [0xe2] = { "LD ($FF00+C), A", &i_ld8_cp_a, 8, 1},

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
  [0xe0] = { "LD ($FF00+n), A", &i_ld_ff00_n_a, 12, 2},
 
  /* 20. LDH A, (n) */
  /* Description: Put memory address $FF00+n into A */
  /* Use with: n = one byte immediate value */
  [0xf0] = { "LD A, ($FF00+n)", &i_ld_a_ff00_n, 12, 2},
  

  /* 3.3.2 - 16 Bits Loads */
  

  /* 1. LD n, nn */
  /* Description: Put value nn into n */
  /* Use With:  */
  /* n = BC, DE, HL, SP */
  /* nn = 16 bit immediate value */
  [0x01] = { "LD BC, nn", &i_ld16_bc_nn, 12, 3},
  [0x11] = { "LD DE, nn", &i_ld16_de_nn, 12, 3},
  [0x21] = { "LD HL, nn", &i_ld16_hl_nn, 12, 3},
  [0x31] = { "LD SP, nn", &i_ld16_sp_nn, 12, 3},

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
  [0xf8] = { "LDHL SP, n", &i_ld16_hl_sp_n, 12, 1},
 

  /* 5. LD (nn), SP */
  /* Description: */
  /*     Put Stack Pointer (SP) at address n. */
  /* Use with: */
  /*     nn = two byte immediate address. */
  [0x08] = { "LD (nn) SP", &i_ld16_nn_sp, 20, 1},

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
  [0xc6] = { "ADD A, #",    &i_add8_a_sharp, 8, 2},

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
  [0xce] = { "ADC A, #",    &i_adc8_a_sharp, 8, 1},

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
  [0xd6] = { "SUB #",    &i_sub8_a_sharp, 8, 2},

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
  [0xe6] = { "AND #",    &i_and_sharp, 8, 2},

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
  [0xf6] = { "OR #",    &i_or_sharp, 8, 2},

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
  [0xee] = { "XOR #",    &i_xor_sharp, 8, 2},


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
  [0xfe] = { "CP #    ",    &i_cp_sharp, 8, 2},

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
  [0xe8] = { "ADD SP, #", &unimplemented_instruction, 16, 2},

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
  /*     correct representation of Binary Coded Deciman (BCD) is obtained. */
  /* Flags affected: */
  /*     Z - Set if register A is zero. */
  /*     N - Not affected. */
  /*     H - Reset. */
  /*     C - Set or reset according to operation. */
  [0x27] = { "DDA", &unimplemented_instruction, 4, 1},

  /* 3. CPL */
  /* Description: */
  /*     Complement A register. (Flip all bits.) */
  /* Flags affected: */
  /*     Z - Not affected. */
  /*     N - Set. */
  /*     H - Set. */
  /*     C - Not affected. */
  [0x2f] = { "CPL", &unimplemented_instruction, 4, 1},

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
  [0xfb] = { "EI", &unimplemented_instruction, 4, 1},

  /* 3.3.6 Rotates & Shifts */

  /* 1. RLCA */
  /* Description: */
  /*     Rotate A left. Old bit 7 Carry flag. */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 7 data. */
  [0x07] = { "RLCA", &unimplemented_instruction, 4, 1},

  /* 2. RLA */
  /* Description: */
  /*     Rotate A left through Carry flag. */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 7 data. */
  [0x17] = { "RLA", &unimplemented_instruction, 4, 1},

  /* 3. RRCA */
  /* Description: */
  /*     Rotate A right. Old bit 0 to Carry flag. */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 0 data. */
  [0x0f] = { "RRCA", &unimplemented_instruction, 4, 1},

  /* 4. RRA */
  /* Description: */
  /*     Rotate A right through Carry flag. */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 0 data. */
  [0x1f] = { "RRA", &unimplemented_instruction, 4, 1},

  /* 3.3.8 - Jumps */

  /* 1. JP nn */
  /* Description: */
  /*     Jump to address nn. */
  /* Use with: */
  /*     nn = two byte immediate value. (LS byte first) */
  [0xc3] = { "JP nn", &i_jp_nn, 12, 3},
  

  /* 2. JP cc, nn */
  /* Description: */
  /*     Jump to address n if following condition is true. */
  /*     cc = NZ, Jump if Z flag is reset. */
  /*     cc = Z, Jump if Z flag is set. */
  /*     cc = NC, Jump if C flag is reset. */
  /*     cc = C, Jump if C flag is set. */
  /* Use with: */
  /*     nn = two byte immediate value. (LS byte first) */
  [0xc2] = { "JP NZ, nn", &i_jp_nz_nn, 12, 3},
  [0xca] = { "JP Z, nn",  &i_jp_z_nn,  12, 3},
  [0xd2] = { "JP NC, nn", &i_jp_nc_nn, 12, 3},
  [0xda] = { "JP C, nn",  &i_jp_c_nn,  12, 3},

  /* 3. JP (HL) */
  /* Description: */
  /*     Jump to address contained in HL. */
  [0xe9] = { "JP (HL)", &i_jp_hl, 4, 1},

  /* 4. JP n */
  /* Description: */
  /*     Add n to current address and jump to it. */
  /* Use with: */
  /*     n = one byte signed immediate value */
  [0x18] = { "JP n", &i_jp_n, 8, 2},

  /* 5. JR cc, n */
  /* Description: */
  /*     If following condition is true then add n to current address and jump to it. */
  /*     cc = NZ, Jump if Z flag is reset. */
  /*     cc = Z, Jump if Z flag is set. */
  /*     cc = NC, Jump if C flag is reset. */
  /*     cc = C, Jump if C flag is set. */
  /* Use with: */
  /*     n = one byte signed immediate value. */
  [0x20] = { "JR NZ, #", &i_jr_nz_sharp, 8, 2},
  [0x28] = { "JR Z, #",  &i_jr_z_sharp, 8, 2},
  [0x30] = { "JR NC, #", &i_jr_nc_sharp, 8, 2},
  [0x38] = { "JR C, #",  &i_jr_c_sharp, 8, 2},

  /* 3.3.9 - Calls */


  /* 1. CALL nn */
  /* Description: */
  /*     Push address of next instruction onto stack and then jump to address nn. */
  /* Use with: */
  /*     nn = two byte immediate value. (LS byte first). */
  [0xcd] = { "CALL nn", &i_call_nn, 12, 3},


  /* 2. CALL cc, nn */
  /* Description: */
  /*     Call address n if following condition is true: */
  /*     cc = NZ, Call if Z flag is reset */
  /*     cc = Z, Call if Z flag is set */
  /*     cc = NC, Call if C flag is reset */
  /*     cc = C, Call if C flag is set */
  /* Use with: */
  /*     nn = two byte immediate value. (LS byte first). */
  [0xc4] = { "CALL NZ, nn", &unimplemented_instruction, 12, 3},
  [0xcc] = { "CALL Z, nn",  &unimplemented_instruction, 12, 3},
  [0xd4] = { "CALL NC, nn", &unimplemented_instruction, 12, 3},
  [0xdc] = { "CALL C, nn",  &unimplemented_instruction, 12, 3},


  /* 3.3.10 - Restarts */

  /* 1. RST n */
  /* Description: */
  /*     Push present address onto stack. */
  /*     Jump to address $0000 + n. */
  /* Use with: */
  /*     n = $00, $08, $10, $18, $20, $28, $30, $38 */
  [0xc7] = { "RST 00H", &unimplemented_instruction, 32, 1},
  [0xcf] = { "RST 08H", &unimplemented_instruction, 32, 1},
  [0xd7] = { "RST 10H", &unimplemented_instruction, 32, 1},
  [0xdf] = { "RST 18H", &unimplemented_instruction, 32, 1},
  [0xe7] = { "RST 20H", &unimplemented_instruction, 32, 1},
  [0xef] = { "RST 28H", &unimplemented_instruction, 32, 1},
  [0xf7] = { "RST 30H", &unimplemented_instruction, 32, 1},
  [0xff] = { "RST 38H", &i_rst_38,                  32, 1},

  /* 3.3.11 - Returns */

  /* 1. RET */
  /* Description: */
  /*     Pop two bytes from stack & jump to that address. */
  [0xc9] = { "RET", &unimplemented_instruction, 8, 1},

  /* 2. RET cc */
  /* Description: */
  /*     Return if following condition is true. */
  /* Use with: */
  /*     cc = NZ, Return if Z flag is reset. */
  /*     cc = Z, Return if Z flag is set. */
  /*     cc = NC, Return if C flag is reset. */
  /*     cc = C, Return if C flag is set. */
  [0xc0] = { "RET NZ", &unimplemented_instruction, 8, 1},
  [0xc8] = { "RET Z",  &unimplemented_instruction, 8, 1},
  [0xd0] = { "RET NC", &unimplemented_instruction, 8, 1},
  [0xd8] = { "RET C",  &unimplemented_instruction, 8, 1},

  /* 3. RETI */
  /* Description: */
  /*     Pop two bytes from stack & jump to that address then enable interrupts. */
  [0xd9] = { "RETI", &unimplemented_instruction, 8, 1},

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

const t_instruction     g_instructions_cb[] = {

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

  [0x37] = {"SWAP A",    &unimplemented_instruction, 8, 1},
  [0x30] = {"SWAP B",    &unimplemented_instruction, 8, 1},
  [0x31] = {"SWAP C",    &unimplemented_instruction, 8, 1},
  [0x32] = {"SWAP D",    &unimplemented_instruction, 8, 1},
  [0x33] = {"SWAP E",    &unimplemented_instruction, 8, 1},
  [0x34] = {"SWAP H",    &unimplemented_instruction, 8, 1},
  [0x35] = {"SWAP L",    &unimplemented_instruction, 8, 1},
  [0x36] = {"SWAP (HL)", &unimplemented_instruction, 16, 1},

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

  [0x07] = {"RLC A",       &unimplemented_instruction, 8, 1},
  [0x00] = {"RLC B",       &unimplemented_instruction, 8, 1},
  [0x01] = {"RLC C",       &unimplemented_instruction, 8, 1},
  [0x02] = {"RLC D",       &unimplemented_instruction, 8, 1},
  [0x03] = {"RLC E",       &unimplemented_instruction, 8, 1},
  [0x04] = {"RLC H",       &unimplemented_instruction, 8, 1},
  [0x05] = {"RLC L",       &unimplemented_instruction, 8, 1},
  [0x06] = {"RLC (HL)",    &unimplemented_instruction, 16, 1},

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

  [0x17] = {"RL A",          &unimplemented_instruction, 8, 1},
  [0x10] = {"RL B",          &unimplemented_instruction, 8, 1},
  [0x11] = {"RL C",          &unimplemented_instruction, 8, 1},
  [0x12] = {"RL D",          &unimplemented_instruction, 8, 1},
  [0x13] = {"RL E",          &unimplemented_instruction, 8, 1},
  [0x14] = {"RL H",          &unimplemented_instruction, 8, 1},
  [0x15] = {"RL L",          &unimplemented_instruction, 8, 1},
  [0x16] = {"RL (HL)",       &unimplemented_instruction, 16, 1},

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

  [0x0f] = {"RRC A",          &unimplemented_instruction, 8, 1},
  [0x08] = {"RRC B",          &unimplemented_instruction, 8, 1},
  [0x09] = {"RRC C",          &unimplemented_instruction, 8, 1},
  [0x0a] = {"RRC D",          &unimplemented_instruction, 8, 1},
  [0x0b] = {"RRC E",          &unimplemented_instruction, 8, 1},
  [0x0c] = {"RRC H",          &unimplemented_instruction, 8, 1},
  [0x0d] = {"RRC L",          &unimplemented_instruction, 8, 1},
  [0x0e] = {"RRC (HL)",       &unimplemented_instruction, 16, 1},

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

  [0x1f] = {"RR A",          &unimplemented_instruction, 8, 1},
  [0x18] = {"RR B",          &unimplemented_instruction, 8, 1},
  [0x19] = {"RR C",          &unimplemented_instruction, 8, 1},
  [0x1a] = {"RR D",          &unimplemented_instruction, 8, 1},
  [0x1b] = {"RR E",          &unimplemented_instruction, 8, 1},
  [0x1c] = {"RR H",          &unimplemented_instruction, 8, 1},
  [0x1d] = {"RR L",          &unimplemented_instruction, 8, 1},
  [0x1e] = {"RR (HL)",       &unimplemented_instruction, 16, 1},

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

  [0x27] = {"SLA A",          &unimplemented_instruction, 8, 1},
  [0x20] = {"SLA B",          &unimplemented_instruction, 8, 1},
  [0x21] = {"SLA C",          &unimplemented_instruction, 8, 1},
  [0x22] = {"SLA D",          &unimplemented_instruction, 8, 1},
  [0x23] = {"SLA E",          &unimplemented_instruction, 8, 1},
  [0x24] = {"SLA H",          &unimplemented_instruction, 8, 1},
  [0x25] = {"SLA L",          &unimplemented_instruction, 8, 1},
  [0x26] = {"SLA (HL)",       &unimplemented_instruction, 16, 1},

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

  [0x2f] = {"SRA A",          &unimplemented_instruction, 8, 1},
  [0x28] = {"SRA B",          &unimplemented_instruction, 8, 1},
  [0x29] = {"SRA C",          &unimplemented_instruction, 8, 1},
  [0x2a] = {"SRA D",          &unimplemented_instruction, 8, 1},
  [0x2b] = {"SRA E",          &unimplemented_instruction, 8, 1},
  [0x2c] = {"SRA H",          &unimplemented_instruction, 8, 1},
  [0x2d] = {"SRA L",          &unimplemented_instruction, 8, 1},
  [0x2e] = {"SRA (HL)",       &unimplemented_instruction, 16, 1},

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

  [0x47] = {"BIT b, A",       &i_bit_a , 8, 2},
  [0x40] = {"BIT b, B",       &i_bit_b , 8, 2},
  [0x41] = {"BIT b, C",       &i_bit_c , 8, 2},
  [0x42] = {"BIT b, D",       &i_bit_d , 8, 2},
  [0x43] = {"BIT b, E",       &i_bit_e , 8, 2},
  [0x44] = {"BIT b, H",       &i_bit_h , 8, 2},
  [0x45] = {"BIT b, L",       &i_bit_l , 8, 2},
  [0x46] = {"BIT b, (HL)",    &i_bit_hl, 16, 2},

  /* SET b, r */
  /* Description: */
  /*     Set bit b in register r. */
  /* Use with: */
  /*     b = 0 - 7, r = A, B, C, D, E, H, L, (HL) */

  [0xc7] = {"SET b, A",       &unimplemented_instruction, 8, 1},
  [0xc0] = {"SET b, B",       &unimplemented_instruction, 8, 1},
  [0xc1] = {"SET b, C",       &unimplemented_instruction, 8, 1},
  [0xc2] = {"SET b, D",       &unimplemented_instruction, 8, 1},
  [0xc3] = {"SET b, E",       &unimplemented_instruction, 8, 1},
  [0xc4] = {"SET b, H",       &unimplemented_instruction, 8, 1},
  [0xc5] = {"SET b, L",       &unimplemented_instruction, 8, 1},
  [0xc6] = {"SET b, (HL)",    &unimplemented_instruction, 16, 1},

  /* RES b, r */
  /* Description: */
  /*     Reset bit b in register r. */
  /* Use with: */
  /*     b = 0 - 7, r = A, B, C, D, E, H, L, (HL) */

  [0x87] = {"RES b, A",       &unimplemented_instruction, 8, 1},
  [0x80] = {"RES b, B",       &unimplemented_instruction, 8, 1},
  [0x81] = {"RES b, C",       &unimplemented_instruction, 8, 1},
  [0x82] = {"RES b, D",       &unimplemented_instruction, 8, 1},
  [0x83] = {"RES b, E",       &unimplemented_instruction, 8, 1},
  [0x84] = {"RES b, H",       &unimplemented_instruction, 8, 1},
  [0x85] = {"RES b, L",       &unimplemented_instruction, 8, 1},
  [0x86] = {"RES b, (HL)",    &unimplemented_instruction, 16, 1},
};
