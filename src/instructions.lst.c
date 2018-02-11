#include "instructions.h"

const t_instruction     g_instructions[] = {
  /* 3.3.1 - 8 Bits Loads */

  /* 1. LD nn, n */
  /* Description: Put value nn into n */
  /* Use with:  */
  /*     nn = B,C,D,E,H,L,BC,DE,HL,SP  */
  /*      n = 8 bit immediate value  */
  {0x06, "LD B, n", &unimplemented_instruction, 8, 2},
  {0x0e, "LD C, n", &unimplemented_instruction, 8, 2},
  {0x16, "LD D, n", &unimplemented_instruction, 8, 2},
  {0x1e, "LD E, n", &unimplemented_instruction, 8, 2},
  {0x26, "LD H, n", &unimplemented_instruction, 8, 2},
  {0x2e, "LD L, n", &unimplemented_instruction, 8, 2},

  /* 2. LD r1, r2 */
  /* Description: Put value r2 into r1 */
  /* Use with:  */
  /*     r1, r2 = A,B,C,D,E,H,L,(HL) */
  {0x7f, "LD A, A",         &unimplemented_instruction, 4, 1},
  {0x78, "LD A, B",         &unimplemented_instruction, 4, 1},
  {0x79, "LD A, C",         &unimplemented_instruction, 4, 1},
  {0x7a, "LD A, D",         &unimplemented_instruction, 4, 1},
  {0x7b, "LD A, E",         &unimplemented_instruction, 4, 1},
  {0x7c, "LD A, H",         &unimplemented_instruction, 4, 1},
  {0x7d, "LD A, L",         &unimplemented_instruction, 4, 1},
  {0x7e, "LD A, (HL)",      &unimplemented_instruction, 8, 1},
  {0x40, "LD B, B",         &unimplemented_instruction, 4, 1},
  {0x41, "LD B, C",         &unimplemented_instruction, 4, 1},
  {0x42, "LD B, D",         &unimplemented_instruction, 4, 1},
  {0x43, "LD B, E",         &unimplemented_instruction, 4, 1},
  {0x44, "LD B, H",         &unimplemented_instruction, 4, 1},
  {0x45, "LD B, L",         &unimplemented_instruction, 4, 1},
  {0x46, "LD B, (HL)",      &unimplemented_instruction, 8, 1},
  {0x48, "LD C, B",         &unimplemented_instruction, 4, 1},
  {0x49, "LD C, C",         &unimplemented_instruction, 4, 1},
  {0x4a, "LD C, D",         &unimplemented_instruction, 4, 1},
  {0x4b, "LD C, E",         &unimplemented_instruction, 4, 1},
  {0x4c, "LD C, H",         &unimplemented_instruction, 4, 1},
  {0x4d, "LD C, L",         &unimplemented_instruction, 4, 1},
  {0x4e, "LD C, (HL)",      &unimplemented_instruction, 8, 1},
  {0x50, "LD D, B",         &unimplemented_instruction, 4, 1},
  {0x51, "LD D, C",         &unimplemented_instruction, 4, 1},
  {0x52, "LD D, D",         &unimplemented_instruction, 4, 1},
  {0x53, "LD D, E",         &unimplemented_instruction, 4, 1},
  {0x54, "LD D, H",         &unimplemented_instruction, 4, 1},
  {0x55, "LD D, L",         &unimplemented_instruction, 4, 1},
  {0x56, "LD D, (HL)",      &unimplemented_instruction, 8, 1},
  {0x58, "LD E, B",         &unimplemented_instruction, 4, 1},
  {0x59, "LD E, C",         &unimplemented_instruction, 4, 1},
  {0x5a, "LD E, D",         &unimplemented_instruction, 4, 1},
  {0x5b, "LD E, E",         &unimplemented_instruction, 4, 1},
  {0x5c, "LD E, H",         &unimplemented_instruction, 4, 1},
  {0x5d, "LD E, L",         &unimplemented_instruction, 4, 1},
  {0x5e, "LD E, (HL)",      &unimplemented_instruction, 8, 1},
  {0x60, "LD H, B",         &unimplemented_instruction, 4, 1},
  {0x61, "LD H, C",         &unimplemented_instruction, 4, 1},
  {0x62, "LD H, D",         &unimplemented_instruction, 4, 1},
  {0x63, "LD H, E",         &unimplemented_instruction, 4, 1},
  {0x64, "LD H, H",         &unimplemented_instruction, 4, 1},
  {0x65, "LD H, L",         &unimplemented_instruction, 4, 1},
  {0x66, "LD H, (HL)",      &unimplemented_instruction, 8, 1},
  {0x68, "LD L, B",         &unimplemented_instruction, 4, 1},
  {0x69, "LD L, C",         &unimplemented_instruction, 4, 1},
  {0x6a, "LD L, D",         &unimplemented_instruction, 4, 1},
  {0x6b, "LD L, E",         &unimplemented_instruction, 4, 1},
  {0x6c, "LD L, H",         &unimplemented_instruction, 4, 1},
  {0x6d, "LD L, L",         &unimplemented_instruction, 4, 1},
  {0x6e, "LD L, (HL)",      &unimplemented_instruction, 8, 1},
  {0x70, "LD (HL), B",      &unimplemented_instruction, 8, 1},
  {0x71, "LD (HL), C",      &unimplemented_instruction, 8, 1},
  {0x72, "LD (HL), D",      &unimplemented_instruction, 8, 1},
  {0x73, "LD (HL), E",      &unimplemented_instruction, 8, 1},
  {0x74, "LD (HL), H",      &unimplemented_instruction, 8, 1},
  {0x75, "LD (HL), L",      &unimplemented_instruction, 8, 1},
  {0x36, "LD (HL), n",      &unimplemented_instruction, 12, 3},

  /* 3. LD A, n */
  /* Description: Put value n into A */
  /* Use with:  */
  /*      n = A,B,C,D,E,H,L,(BC),(DE),(HL),(nn),# */
  /*     nn = two byte immediate value. (LS byte first.) */
  {0x0a, "LD A, (BC)", &unimplemented_instruction, 8, 1},
  {0x1a, "LD A, (DE)", &unimplemented_instruction, 8, 1},
  {0xfa, "LD A, (nn)", &unimplemented_instruction, 16, 1},
  {0x3e, "LD A, #", &unimplemented_instruction, 8, 1},

  /* 4. LD n, A */
  /* Description: Put value A into n */
  /* Use with:  */
  /*      n = A,B,C,D,E,H,L,(BC),(DE),(HL),(nn) */
  /*     nn = two byte immediate value. (LS byte first.) */
  {0x47, "LD B, A",         &unimplemented_instruction, 4, 1},
  {0x4f, "LD C, A",         &unimplemented_instruction, 4, 1},
  {0x57, "LD D, A",         &unimplemented_instruction, 4, 1},
  {0x5f, "LD E, A",         &unimplemented_instruction, 4, 1},
  {0x67, "LD H, A",         &unimplemented_instruction, 4, 1},
  {0x6f, "LD L, A",         &unimplemented_instruction, 4, 1},
  {0x02, "LD (BC), A",      &unimplemented_instruction, 8, 1},
  {0x12, "LD (DE), A",      &unimplemented_instruction, 8, 1},
  {0x77, "LD (HL), A",      &unimplemented_instruction, 8, 1},
  {0xea, "LD (nn), A",      &unimplemented_instruction, 16, 1},

  /* 5. LD A, (C) */
  {0xf2, "LD A, (C)",       &unimplemented_instruction, 8, 1},

  /* 6. LD (C), A */
  {0xe2, "LD ($FF00+C), A", &unimplemented_instruction, 8, 1},

  /* 7. LD A, (HLD) */
  /* Description: Same as: LDD A, (HL) */

  /* 8. LD A, (HL-) */
  /* Description: Same as: LDD A, (HL) */
 
  /* 9. LDD A, (HL) */
  /* Description: Put value at address HL into A. Decrement HL */
  /* Same as: LD A, (HL) - DEC HL */
  {0x3a, "LDD A, (HL)", &unimplemented_instruction, 8, 1},

  /* 10. LD (HLD), A */
  /* Description: Same as: LDD (HL), A */

  /* 11. LD (HL-), A */
  /* Description: Same as: LDD (HL), A */
 
  /* 12. LDD (HL), A */
  /* Description: Put A into memory address HL. Decrement HL */
  /* Same as: LD (HL), A - DEC HL */
  {0x32, "LDD (HL), A", &unimplemented_instruction, 8, 1},


  /* 13. LD A, (HLI) */
  /* Description: Same as: LDI A, (HL) */

  /* 14. LD A, (HL+) */
  /* Description: Same as: LDI A, (HL) */
 
  /* 15. LDI A, (HL) */
  /* Description: Put value at address HL into A. Increment HL */
  /* Same as: LD A, (HL) - INC HL */
  {0x2a, "LDI A, (HL)", &unimplemented_instruction, 8, 1},

  /* 16. LD (HLI), A */
  /* Description: Same as: LDD (HL), A */

  /* 17. LD (HL+), A */
  /* Description: Same as: LDD (HL), A */
 
  /* 18. LDI (HL), A */
  /* Description: Put A into memory address HL. Increment HL */
  /* Same as: LD (HL), A - INC HL */
  {0x22, "LDI (HL), A", &unimplemented_instruction, 8, 1},

  /* 19. LDH (n), A */
  /* Description: Put A into memory address $FF00+n */
  /* Use with: n = one byte immediate value. */
  {0xe0, "LD ($FF00+n), A", &unimplemented_instruction, 12, 2},
 
  /* 20. LDH A, (n) */
  /* Description: Put memory address $FF00+n into A */
  /* Use with: n = one byte immediate value */
  {0xf0, "LD A, ($FF00+n)", &unimplemented_instruction, 12, 1},
  
  /* 3.3.2 - 16 Bits Loads */
  
  /* 1. LD n, nn */
  /* Description: Put valie nn into n */
  /* Use With:  */
  /* n = BC, DE, HL, SP */
  /* nn = 16 bit immediate value */
  {0x01, "LD BC, nn", &i_ld16_bc_nn, 12, 3},
  {0x11, "LD DE, nn", &unimplemented_instruction, 12, 3},
  {0x21, "LD HL, nn", &i_ld16_hl_nn, 12, 3},
  {0x31, "LD SP, nn", &unimplemented_instruction, 12, 3},

  /* 2. LD SP, HL */
  /* Description: Put HL into Stack Pointer (SP) */
  {0xf9, "LD SP, HL", &unimplemented_instruction, 8, 1},

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
  {0xf8, "LDHL SP, n", &unimplemented_instruction, 12, 1},
 
  /* 5. LD (nn), SP */
  /* Description: */
  /*     Put Stack Pointer (SP) at address n. */
  /* Use with: */
  /*     nn = two byte immediate address. */
  {0x08, "LD (nn) SP", &unimplemented_instruction, 20, 1},

  /* 6. PUSH nn */
  /* Description: */
  /*     Push register pair nn onto stack. */
  /*     Decrement Stack Pointer (SP) twice. */
  /* Use with: */
  /*     nn = AF, BC, DE, HL */
  {0xf5, "PUSH AF", &unimplemented_instruction, 16, 1},
  {0xc5, "PUSH BC", &unimplemented_instruction, 16, 1},
  {0xd5, "PUSH DE", &unimplemented_instruction, 16, 1},
  {0xe5, "PUSH HL", &unimplemented_instruction, 16, 1},
  
  /* 7. POP nn */
  /* Description: */
  /*     Pop two bytes off stack into register pair nn. */
  /*     Increment Stack Pointer (SP) twice. */
  /* Use with: */
  /*     nn = AF, BC, DE, HL */
  {0xf1, "POP AF", &unimplemented_instruction, 12, 1},
  {0xc1, "POP BC", &unimplemented_instruction, 12, 1},
  {0xd1, "POP DE", &unimplemented_instruction, 12, 1},
  {0xe1, "POP HL", &unimplemented_instruction, 12, 1},

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
  {0x87, "ADD A, A",    &unimplemented_instruction, 4, 1},
  {0x80, "ADD A, B",    &unimplemented_instruction, 4, 1},
  {0x81, "ADD A, C",    &unimplemented_instruction, 4, 1},
  {0x82, "ADD A, D",    &unimplemented_instruction, 4, 1},
  {0x83, "ADD A, E",    &unimplemented_instruction, 4, 1},
  {0x84, "ADD A, H",    &unimplemented_instruction, 4, 1},
  {0x85, "ADD A, L",    &unimplemented_instruction, 4, 1},
  {0x86, "ADD A, (HL)", &unimplemented_instruction, 8, 1},
  {0xc6, "ADD A, #",    &unimplemented_instruction, 8, 2},

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
  {0x8f, "ADC A, A", &unimplemented_instruction, 4, 1},
  {0x88, "ADC A, B", &unimplemented_instruction, 4, 1},
  {0x89, "ADC A, C", &unimplemented_instruction, 4, 1},
  {0x8a, "ADC A, D", &unimplemented_instruction, 4, 1},
  {0x8b, "ADC A, E", &unimplemented_instruction, 4, 1},
  {0x8c, "ADC A, H", &unimplemented_instruction, 4, 1},
  {0x8d, "ADC A, L", &unimplemented_instruction, 4, 1},
  {0x8e, "ADC A, (HL)", &unimplemented_instruction, 8, 1},
  {0xce, "ADC A, #", &unimplemented_instruction, 8, 1},

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
  {0x97, "SUB A",    &unimplemented_instruction, 4, 1},
  {0x90, "SUB B",    &unimplemented_instruction, 4, 1},
  {0x91, "SUB C",    &unimplemented_instruction, 4, 1},
  {0x92, "SUB D",    &unimplemented_instruction, 4, 1},
  {0x93, "SUB E",    &unimplemented_instruction, 4, 1},
  {0x94, "SUB H",    &unimplemented_instruction, 4, 1},
  {0x95, "SUB L",    &unimplemented_instruction, 4, 1},
  {0x96, "SUB (HL)", &unimplemented_instruction, 8, 1},
  {0xd6, "SUB #",    &unimplemented_instruction, 8, 2},

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
  {0x9f, "SUB A, A", &unimplemented_instruction, 4, 1},
  {0x98, "SUB A, B", &unimplemented_instruction, 4, 1},
  {0x99, "SUB A, C", &unimplemented_instruction, 4, 1},
  {0x9a, "SUB A, D", &unimplemented_instruction, 4, 1},
  {0x9b, "SUB A, E", &unimplemented_instruction, 4, 1},
  {0x9c, "SUB A, H", &unimplemented_instruction, 4, 1},
  {0x9d, "SUB A, L", &unimplemented_instruction, 4, 1},
  {0x9e, "SUB A, (HL)", &unimplemented_instruction, 8, 1},
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
  {0xa7, "AND A",    &unimplemented_instruction, 4, 1},
  {0xa0, "AND B",    &unimplemented_instruction, 4, 1},
  {0xa1, "AND C",    &unimplemented_instruction, 4, 1},
  {0xa2, "AND D",    &unimplemented_instruction, 4, 1},
  {0xa3, "AND E",    &unimplemented_instruction, 4, 1},
  {0xa4, "AND H",    &unimplemented_instruction, 4, 1},
  {0xa5, "AND L",    &unimplemented_instruction, 4, 1},
  {0xa6, "AND (HL)", &unimplemented_instruction, 8, 1},
  {0xe6, "AND #",    &unimplemented_instruction, 8, 2},

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
  {0xb7, "OR A",    &unimplemented_instruction, 4, 1},
  {0xb0, "OR B",    &unimplemented_instruction, 4, 1},
  {0xb1, "OR C",    &unimplemented_instruction, 4, 1},
  {0xb2, "OR D",    &unimplemented_instruction, 4, 1},
  {0xb3, "OR E",    &unimplemented_instruction, 4, 1},
  {0xb4, "OR H",    &unimplemented_instruction, 4, 1},
  {0xb5, "OR L",    &unimplemented_instruction, 4, 1},
  {0xb6, "OR (HL)", &unimplemented_instruction, 8, 1},
  {0xf6, "OR #",    &unimplemented_instruction, 8, 2},

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
  {0xaf, "XOR A",    &i_xor_a, 4, 1},
  {0xa8, "XOR B",    &unimplemented_instruction, 4, 1},
  {0xa9, "XOR C",    &unimplemented_instruction, 4, 1},
  {0xaa, "XOR D",    &unimplemented_instruction, 4, 1},
  {0xab, "XOR E",    &unimplemented_instruction, 4, 1},
  {0xac, "XOR H",    &unimplemented_instruction, 4, 1},
  {0xad, "XOR L",    &unimplemented_instruction, 4, 1},
  {0xae, "XOR (HL)", &unimplemented_instruction, 8, 1},
  {0xee, "XOR #",    &unimplemented_instruction, 8, 2},


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
  {0xbf, "OP A",    &unimplemented_instruction, 4, 1},
  {0xb8, "OP B",    &unimplemented_instruction, 4, 1},
  {0xb9, "OP C",    &unimplemented_instruction, 4, 1},
  {0xba, "OP D",    &unimplemented_instruction, 4, 1},
  {0xbb, "OP E",    &unimplemented_instruction, 4, 1},
  {0xbc, "OP H",    &unimplemented_instruction, 4, 1},
  {0xbd, "OP L",    &unimplemented_instruction, 4, 1},
  {0xbe, "OP (HL)", &unimplemented_instruction, 8, 1},
  {0xfe, "OP #",    &unimplemented_instruction, 8, 2},

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
  {0x3c, "INC A",    &unimplemented_instruction, 4, 1},
  {0x04, "INC B",    &unimplemented_instruction, 4, 1},
  {0x0c, "INC C",    &unimplemented_instruction, 4, 1},
  {0x14, "INC D",    &unimplemented_instruction, 4, 1},
  {0x1c, "INC E",    &unimplemented_instruction, 4, 1},
  {0x24, "INC H",    &unimplemented_instruction, 4, 1},
  {0x2c, "INC L",    &unimplemented_instruction, 4, 1},
  {0x34, "INC (HL)", &unimplemented_instruction, 8, 1},

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
  {0x3d, "DEC A",    &unimplemented_instruction, 4,  1},
  {0x05, "DEC B",    &unimplemented_instruction, 4,  1},
  {0x0d, "DEC C",    &unimplemented_instruction, 4,  1},
  {0x15, "DEC D",    &unimplemented_instruction, 4,  1},
  {0x1d, "DEC E",    &unimplemented_instruction, 4,  1},
  {0x25, "DEC H",    &unimplemented_instruction, 4,  1},
  {0x2d, "DEC L",    &unimplemented_instruction, 4,  1},
  {0x35, "DEC (HL)", &unimplemented_instruction, 12, 1},

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
  {0x09, "ADD HL, BC", &unimplemented_instruction, 8, 1},
  {0x19, "ADD HL, DE", &unimplemented_instruction, 8, 1},
  {0x29, "ADD HL, HL", &unimplemented_instruction, 8, 1},
  {0x39, "ADD HL, CP", &unimplemented_instruction, 8, 1},
  

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
  {0xe8, "ADD CP, #", &unimplemented_instruction, 16, 2},

  /* 3. INC nn */
  /* Description: */
  /*     Increment register nn. */
  /* Use with: */
  /*     nn = BC, DE, HL, SP. */
  /* Flags affected: */
  /*     None. */
  {0x03, "INC BC", &unimplemented_instruction, 8, 1},
  {0x13, "INC DE", &unimplemented_instruction, 8, 1},
  {0x23, "INC HL", &unimplemented_instruction, 8, 1},
  {0x33, "INC SP", &unimplemented_instruction, 8, 1},

  /* 3. DEC nn */
  /* Description: */
  /*     Decrement register nn. */
  /* Use with: */
  /*     nn = BC, DE, HL, SP. */
  /* Flags affected: */
  /*     None. */
  {0x0b, "DEC BC", &unimplemented_instruction, 8, 1},
  {0x1b, "DEC DE", &unimplemented_instruction, 8, 1},
  {0x2b, "DEC HL", &unimplemented_instruction, 8, 1},
  {0x3b, "DEC SP", &unimplemented_instruction, 8, 1},

  /* 3.3.5 Miscellaneous */

  /* 1. SWAP n */
  /* Description: */
  /*     Swap upper & lower nibles of n. */
  /* Use with: */
  /*     n = A, B, C, D, E, H, L, (HL). */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Reset. */

  /* TODO: ???? */

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
  {0x27, "DDA", &unimplemented_instruction, 4, 1},

  /* 3. CPL */
  /* Description: */
  /*     Complement A register. (Flip all bits.) */
  /* Flags affected: */
  /*     Z - Not affected. */
  /*     N - Set. */
  /*     H - Set. */
  /*     C - Not affected. */
  {0x2f, "CPL", &unimplemented_instruction, 4, 1},

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
  {0x3f, "CCF", &unimplemented_instruction, 4, 1},

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
  {0x00, "NOP", &i_nop, 4, 1},

  /* 7. HALT */
  /* Description: */
  /*     Power down PU until an interrupt occurs. */
  /*     Use this when ever possible to reduce energy consumption. */
  {0x76, "HALT", &unimplemented_instruction, 4, 1},

  /* 8. STOP */
  /* Description: */
  /*     Halt CPU & LCD display until button pressed. */
  {0x10, "STOP", &unimplemented_instruction, 4, 2},
  
  /* TODO: ???? */

  /* 9. DI */
  /* Description: */
  /*     This instruction disables interrupts but not immediately. */
  /*     Interrupts are disabled after instruction after DI is executed. */
  {0xf3, "DI", &unimplemented_instruction, 4, 1},

  /* 10. EI */
  /* Description: */
  /*     Enable interrupts. */
  /*     This instruction enables interrupts but not immediately. */
  /*     Interrupts are enabled after instruction after EI is executed. */
  {0xfb, "EI", &unimplemented_instruction, 4, 1},

  /* 3.3.6 Rotates & Shifts */

  /* 1. RLCA */
  /* Description: */
  /*     Rotate A left. Old bit 7 Carry flag. */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 7 data. */
  {0x07, "RLCA", &unimplemented_instruction, 4, 1},

  /* 2. RLA */
  /* Description: */
  /*     Rotate A left through Carry flag. */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 7 data. */
  {0x17, "RLA", &unimplemented_instruction, 4, 1},

  /* 3. RRCA */
  /* Description: */
  /*     Rotate A right. Old bit 0 to Carry flag. */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 0 data. */
  {0x0f, "RRCA", &unimplemented_instruction, 4, 1},

  /* 4. RRA */
  /* Description: */
  /*     Rotate A right through Carry flag. */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 0 data. */
  {0x1f, "RRA", &unimplemented_instruction, 4, 1},

  /* 5. RLC n */
  /* Description: */
  /*     Rotate n left. Old bit 7 to Carry flag. */
  /* Use with: */
  /*     n = A,B,C,D,E,H,L,(HL) */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 7 data. */

  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */

  /* 6. RL n */
  /* Description: */
  /*     Rotate n left through Carry flag. */
  /* Use with: */
  /*     n = A,B,C,D,E,H,L,(HL) */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 7 data. */

  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */

  /* 7. RRC n */
  /* Description: */
  /*     Rotate n right. Old bit 0 to Carry flag. */
  /* Use with: */
  /*     n = A,B,C,D,E,H,L,(HL) */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 0 data. */

  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */

  /* 8. RRC n */
  /* Description: */
  /*     Rotate n right through Carry flag. */
  /* Use with: */
  /*     n = A,B,C,D,E,H,L,(HL) */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 0 data. */

  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */

  /* 9. SLA n */
  /* Description: */
  /*     Shift n left into Carry. LSB of n set to 0. */
  /* Use with: */
  /*     n = A,B,C,D,E,H,L,(HL) */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 7 data. */

  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */

  /* 10. SRA n */
  /* Description: */
  /*     Shift n right into Carry. MSB doesn't change. */
  /* Use with: */
  /*     n = A,B,C,D,E,H,L,(HL) */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 0 data. */

  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */

  /* 11. SRL n */
  /* Description: */
  /*     Shift n right into Carry. MSB set to 0. */
  /* Use with: */
  /*     n = A,B,C,D,E,H,L,(HL) */
  /* Flags affected: */
  /*     Z - Set if result is zero. */
  /*     N - Reset. */
  /*     H - Reset. */
  /*     C - Contains old bit 0 data. */

  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */

  /* 3.3.7 - Bit Opcodes*/

  /* 1. BIT b, r */
  /* Description: */
  /*     Test bit b in register r. */
  /* Use with: */
  /*     b = 0 - 7, r = A, B, C, D, E, H, L, (HL) */
  /* Flags affected: */
  /*     Z - Set if bit b of register r is 0. */
  /*     N - Reset. */
  /*     H - Set. */
  /*     C - Not affected. */

  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */

  /* 2. SET b, r */
  /* Description: */
  /*     Set bit b in register r. */
  /* Use with: */
  /*     b = 0 - 7, r = A, B, C, D, E, H, L, (HL) */

  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */

  /* 3. RES b, r */
  /* Description: */
  /*     Reset bit b in register r. */
  /* Use with: */
  /*     b = 0 - 7, r = A, B, C, D, E, H, L, (HL) */

  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */
  /* TODO: ???? */

  /* 3.3.8 - Jumps */

  /* 1. JP nn */
  /* Description: */
  /*     Jump to address nn. */
  /* Use with: */
  /*     nn = two byte immediate value. (LS byte first) */
  {0xc3, "", &i_jp_nn, 12, 3},
  

  /* 2. JP cc, nn */
  /* Description: */
  /*     Jump to address n if following condition is true. */
  /*     cc = NZ, Jump if Z flag is reset. */
  /*     cc = Z, Jump if Z flag is set. */
  /*     cc = NC, Jump if C flag is reset. */
  /*     cc = C, Jump if C flag is set. */
  /* Use with: */
  /*     nn = two byte immediate value. (LS byte first) */
  {0xc2, "JP NZ, nn", &unimplemented_instruction, 12, 3},
  {0xca, "JP Z, nn",  &unimplemented_instruction, 12, 3},
  {0xd2, "JP NC, nn", &unimplemented_instruction, 12, 3},
  {0xda, "JP C, nn",  &unimplemented_instruction, 12, 3},

  /* 3. JP (HL) */
  /* Description: */
  /*     Jump to address contained in HL. */
  {0xe9, "JP (HL)", &unimplemented_instruction, 4, 1},

  /* 4. JP n */
  /* Description: */
  /*     Add n to current address and jump to it. */
  /* Use with: */
  /*     n = one byte signed immediate value */
  {0x18, "JP n", &unimplemented_instruction, 8, 2},

  /* 5. JR cc, n */
  /* Description: */
  /*     If following condition is true then add n to current address and jump to it. */
  /*     cc = NZ, Jump if Z flag is reset. */
  /*     cc = Z, Jump if Z flag is set. */
  /*     cc = NC, Jump if C flag is reset. */
  /*     cc = C, Jump if C flag is set. */
  /* Use with: */
  /*     n = one byte signed immediate value. */
  {0x20, "JR NZ, #", &unimplemented_instruction, 8, 2},
  {0x28, "JR Z, #",  &unimplemented_instruction, 8, 2},
  {0x30, "JR NC, #", &unimplemented_instruction, 8, 2},
  {0x38, "JR C, #",  &unimplemented_instruction, 8, 2},

  /* 3.3.9 - Calls */


  /* 1. CALL nn */
  /* Description: */
  /*     Push address of next instruction onto stack and then jump to address nn. */
  /* Use with: */
  /*     nn = two byte immediate value. (LS byte first). */
  {0xcd, "CALL nn", &unimplemented_instruction, 12, 3},


  /* 2. CALL cc, nn */
  /* Description: */
  /*     Call address n if following condition is true: */
  /*     cc = NZ, Call if Z flag is reset */
  /*     cc = Z, Call if Z flag is set */
  /*     cc = NC, Call if C flag is reset */
  /*     cc = C, Call if C flag is set */
  /* Use with: */
  /*     nn = two byte immediate value. (LS byte first). */
  {0xc4, "CALL NZ, nn", &unimplemented_instruction, 12, 3},
  {0xcc, "CALL Z, nn",  &unimplemented_instruction, 12, 3},
  {0xd4, "CALL NC, nn", &unimplemented_instruction, 12, 3},
  {0xdc, "CALL C, nn",  &unimplemented_instruction, 12, 3},


  /* 3.3.10 - Restarts */

  /* 1. RST n */
  /* Description: */
  /*     Push present address onto stack. */
  /*     Jump to address $0000 + n. */
  /* Use with: */
  /*     n = $00, $08, $10, $18, $20, $28, $30, $38 */
  {0xc7, "RST 00H", &unimplemented_instruction, 32, 1},
  {0xcf, "RST 08H", &unimplemented_instruction, 32, 1},
  {0xd7, "RST 10H", &unimplemented_instruction, 32, 1},
  {0xdf, "RST 18H", &unimplemented_instruction, 32, 1},
  {0xe7, "RST 20H", &unimplemented_instruction, 32, 1},
  {0xef, "RST 28H", &unimplemented_instruction, 32, 1},
  {0xf7, "RST 30H", &unimplemented_instruction, 32, 1},
  {0xff, "RST 38H", &i_rst_38,                  32, 1},

  /* 3.3.11 - Returns */

  /* 1. RET */
  /* Description: */
  /*     Pop two bytes from stack & jump to that address. */
  {0xc9, "RET", &unimplemented_instruction, 8, 1},

  /* 2. RET cc */
  /* Description: */
  /*     Return if following condition is true. */
  /* Use with: */
  /*     cc = NZ, Return if Z flag is reset. */
  /*     cc = Z, Return if Z flag is set. */
  /*     cc = NC, Return if C flag is reset. */
  /*     cc = C, Return if C flag is set. */
  {0xc0, "RET NZ", &unimplemented_instruction, 8, 1},
  {0xc8, "RET Z",  &unimplemented_instruction, 8, 1},
  {0xd0, "RET NC", &unimplemented_instruction, 8, 1},
  {0xd8, "RET C",  &unimplemented_instruction, 8, 1},

  /* 3. RETI */
  /* Description: */
  /*     Pop two bytes from stack & jump to that address then enable interrupts. */
  {0xd9, "RETI", &unimplemented_instruction, 8, 1},

  /* Non-Documented */
  {0xcb, "PREFIX", &unimplemented_instruction, 4, 1},

  {0xd3, "", &unimplemented_instruction, 0, 1},
  {0xdb, "", &unimplemented_instruction, 0, 1},
  {0xdd, "", &unimplemented_instruction, 0, 1},
  {0xde, "", &unimplemented_instruction, 0, 1},
  {0xe3, "", &unimplemented_instruction, 0, 1},
  {0xe4, "", &unimplemented_instruction, 0, 1},
  {0xeb, "", &unimplemented_instruction, 0, 1},
  {0xec, "", &unimplemented_instruction, 0, 1},
  {0xed, "", &unimplemented_instruction, 0, 1},
  {0xf4, "", &unimplemented_instruction, 0, 1},
  {0xfc, "", &unimplemented_instruction, 0, 1},
  {0xfd, "", &unimplemented_instruction, 0, 1},
};
