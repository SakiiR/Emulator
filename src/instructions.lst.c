#include "instructions.h"

const t_instruction     g_instructions[] = {
  {0x00, "", &i_nop, 0, 1},
  {0x01, "", &i_ld16_bc_nn, 0, 1},
  {0x02, "", &unimplemented_instruction, 0, 1},
  {0x03, "", &unimplemented_instruction, 0, 1},
  {0x04, "", &unimplemented_instruction, 0, 1},
  {0x05, "", &unimplemented_instruction, 0, 1},
  {0x06, "", &unimplemented_instruction, 0, 1},
  {0x07, "", &unimplemented_instruction, 0, 1},
  {0x08, "", &unimplemented_instruction, 0, 1},
  {0x09, "", &unimplemented_instruction, 0, 1},
  {0x0a, "", &unimplemented_instruction, 0, 1},
  {0x0b, "", &unimplemented_instruction, 0, 1},
  {0x0c, "", &unimplemented_instruction, 0, 1},
  {0x0d, "", &unimplemented_instruction, 0, 1},
  {0x0e, "", &unimplemented_instruction, 0, 1},
  {0x0f, "", &unimplemented_instruction, 0, 1},
  {0x10, "", &unimplemented_instruction, 0, 1},
  {0x11, "", &unimplemented_instruction, 0, 1},
  {0x12, "", &unimplemented_instruction, 0, 1},
  {0x13, "", &unimplemented_instruction, 0, 1},
  {0x14, "", &unimplemented_instruction, 0, 1},
  {0x15, "", &unimplemented_instruction, 0, 1},
  {0x16, "", &unimplemented_instruction, 0, 1},
  {0x17, "", &unimplemented_instruction, 0, 1},
  {0x18, "", &unimplemented_instruction, 0, 1},
  {0x19, "", &unimplemented_instruction, 0, 1},
  {0x1a, "", &unimplemented_instruction, 0, 1},
  {0x1b, "", &unimplemented_instruction, 0, 1},
  {0x1c, "", &unimplemented_instruction, 0, 1},
  {0x1d, "", &unimplemented_instruction, 0, 1},
  {0x1e, "", &unimplemented_instruction, 0, 1},
  {0x1f, "", &unimplemented_instruction, 0, 1},
  {0x20, "", &unimplemented_instruction, 0, 1},
  {0x21, "", &i_ld16_hl_nn, 0, 1},
  {0x22, "", &unimplemented_instruction, 0, 1},
  {0x23, "", &unimplemented_instruction, 0, 1},
  {0x24, "", &unimplemented_instruction, 0, 1},
  {0x25, "", &unimplemented_instruction, 0, 1},
  {0x26, "", &unimplemented_instruction, 0, 1},
  {0x27, "", &unimplemented_instruction, 0, 1},
  {0x28, "", &unimplemented_instruction, 0, 1},
  {0x29, "", &unimplemented_instruction, 0, 1},
  {0x2a, "", &unimplemented_instruction, 0, 1},
  {0x2b, "", &unimplemented_instruction, 0, 1},
  {0x2c, "", &unimplemented_instruction, 0, 1},
  {0x2d, "", &unimplemented_instruction, 0, 1},
  {0x2e, "", &unimplemented_instruction, 0, 1},
  {0x2f, "", &unimplemented_instruction, 0, 1},
  {0x30, "", &unimplemented_instruction, 0, 1},
  {0x31, "", &unimplemented_instruction, 0, 1},
  {0x32, "", &unimplemented_instruction, 0, 1},
  {0x33, "", &unimplemented_instruction, 0, 1},
  {0x34, "", &unimplemented_instruction, 0, 1},
  {0x35, "", &unimplemented_instruction, 0, 1},
  {0x36, "", &unimplemented_instruction, 0, 1},
  {0x37, "", &unimplemented_instruction, 0, 1},
  {0x38, "", &unimplemented_instruction, 0, 1},
  {0x39, "", &unimplemented_instruction, 0, 1},
  {0x3a, "", &unimplemented_instruction, 0, 1},
  {0x3b, "", &unimplemented_instruction, 0, 1},
  {0x3c, "", &unimplemented_instruction, 0, 1},
  {0x3d, "", &unimplemented_instruction, 0, 1},
  {0x3e, "", &unimplemented_instruction, 0, 1},
  {0x3f, "", &unimplemented_instruction, 0, 1},
  {0x40, "", &unimplemented_instruction, 0, 1},
  {0x41, "", &unimplemented_instruction, 0, 1},
  {0x42, "", &unimplemented_instruction, 0, 1},
  {0x43, "", &unimplemented_instruction, 0, 1},
  {0x44, "", &unimplemented_instruction, 0, 1},
  {0x45, "", &unimplemented_instruction, 0, 1},
  {0x46, "", &unimplemented_instruction, 0, 1},
  {0x47, "", &unimplemented_instruction, 0, 1},
  {0x48, "", &unimplemented_instruction, 0, 1},
  {0x49, "", &unimplemented_instruction, 0, 1},
  {0x4a, "", &unimplemented_instruction, 0, 1},
  {0x4b, "", &unimplemented_instruction, 0, 1},
  {0x4c, "", &unimplemented_instruction, 0, 1},
  {0x4d, "", &unimplemented_instruction, 0, 1},
  {0x4e, "", &unimplemented_instruction, 0, 1},
  {0x4f, "", &unimplemented_instruction, 0, 1},
  {0x50, "", &unimplemented_instruction, 0, 1},
  {0x51, "", &unimplemented_instruction, 0, 1},
  {0x52, "", &unimplemented_instruction, 0, 1},
  {0x53, "", &unimplemented_instruction, 0, 1},
  {0x54, "", &unimplemented_instruction, 0, 1},
  {0x55, "", &unimplemented_instruction, 0, 1},
  {0x56, "", &unimplemented_instruction, 0, 1},
  {0x57, "", &unimplemented_instruction, 0, 1},
  {0x58, "", &unimplemented_instruction, 0, 1},
  {0x59, "", &unimplemented_instruction, 0, 1},
  {0x5a, "", &unimplemented_instruction, 0, 1},
  {0x5b, "", &unimplemented_instruction, 0, 1},
  {0x5c, "", &unimplemented_instruction, 0, 1},
  {0x5d, "", &unimplemented_instruction, 0, 1},
  {0x5e, "", &unimplemented_instruction, 0, 1},
  {0x5f, "", &unimplemented_instruction, 0, 1},
  {0x60, "", &unimplemented_instruction, 0, 1},
  {0x61, "", &unimplemented_instruction, 0, 1},
  {0x62, "", &unimplemented_instruction, 0, 1},
  {0x63, "", &unimplemented_instruction, 0, 1},
  {0x64, "", &unimplemented_instruction, 0, 1},
  {0x65, "", &unimplemented_instruction, 0, 1},
  {0x66, "", &unimplemented_instruction, 0, 1},
  {0x67, "", &unimplemented_instruction, 0, 1},
  {0x68, "", &unimplemented_instruction, 0, 1},
  {0x69, "", &unimplemented_instruction, 0, 1},
  {0x6a, "", &unimplemented_instruction, 0, 1},
  {0x6b, "", &unimplemented_instruction, 0, 1},
  {0x6c, "", &unimplemented_instruction, 0, 1},
  {0x6d, "", &unimplemented_instruction, 0, 1},
  {0x6e, "", &unimplemented_instruction, 0, 1},
  {0x6f, "", &unimplemented_instruction, 0, 1},
  {0x70, "", &unimplemented_instruction, 0, 1},
  {0x71, "", &unimplemented_instruction, 0, 1},
  {0x72, "", &unimplemented_instruction, 0, 1},
  {0x73, "", &unimplemented_instruction, 0, 1},
  {0x74, "", &unimplemented_instruction, 0, 1},
  {0x75, "", &unimplemented_instruction, 0, 1},
  {0x76, "", &unimplemented_instruction, 0, 1},
  {0x77, "", &unimplemented_instruction, 0, 1},
  {0x78, "", &unimplemented_instruction, 0, 1},
  {0x79, "", &unimplemented_instruction, 0, 1},
  {0x7a, "", &unimplemented_instruction, 0, 1},
  {0x7b, "", &unimplemented_instruction, 0, 1},
  {0x7c, "", &unimplemented_instruction, 0, 1},
  {0x7d, "", &unimplemented_instruction, 0, 1},
  {0x7e, "", &unimplemented_instruction, 0, 1},
  {0x7f, "", &unimplemented_instruction, 0, 1},
  {0x80, "", &unimplemented_instruction, 0, 1},
  {0x81, "", &unimplemented_instruction, 0, 1},
  {0x82, "", &unimplemented_instruction, 0, 1},
  {0x83, "", &unimplemented_instruction, 0, 1},
  {0x84, "", &unimplemented_instruction, 0, 1},
  {0x85, "", &unimplemented_instruction, 0, 1},
  {0x86, "", &unimplemented_instruction, 0, 1},
  {0x87, "", &unimplemented_instruction, 0, 1},
  {0x88, "", &unimplemented_instruction, 0, 1},
  {0x89, "", &unimplemented_instruction, 0, 1},
  {0x8a, "", &unimplemented_instruction, 0, 1},
  {0x8b, "", &unimplemented_instruction, 0, 1},
  {0x8c, "", &unimplemented_instruction, 0, 1},
  {0x8d, "", &unimplemented_instruction, 0, 1},
  {0x8e, "", &unimplemented_instruction, 0, 1},
  {0x8f, "", &unimplemented_instruction, 0, 1},
  {0x90, "", &unimplemented_instruction, 0, 1},
  {0x91, "", &unimplemented_instruction, 0, 1},
  {0x92, "", &unimplemented_instruction, 0, 1},
  {0x93, "", &unimplemented_instruction, 0, 1},
  {0x94, "", &unimplemented_instruction, 0, 1},
  {0x95, "", &unimplemented_instruction, 0, 1},
  {0x96, "", &unimplemented_instruction, 0, 1},
  {0x97, "", &unimplemented_instruction, 0, 1},
  {0x98, "", &unimplemented_instruction, 0, 1},
  {0x99, "", &unimplemented_instruction, 0, 1},
  {0x9a, "", &unimplemented_instruction, 0, 1},
  {0x9b, "", &unimplemented_instruction, 0, 1},
  {0x9c, "", &unimplemented_instruction, 0, 1},
  {0x9d, "", &unimplemented_instruction, 0, 1},
  {0x9e, "", &unimplemented_instruction, 0, 1},
  {0x9f, "", &unimplemented_instruction, 0, 1},
  {0xa0, "", &unimplemented_instruction, 0, 1},
  {0xa1, "", &unimplemented_instruction, 0, 1},
  {0xa2, "", &unimplemented_instruction, 0, 1},
  {0xa3, "", &unimplemented_instruction, 0, 1},
  {0xa4, "", &unimplemented_instruction, 0, 1},
  {0xa5, "", &unimplemented_instruction, 0, 1},
  {0xa6, "", &unimplemented_instruction, 0, 1},
  {0xa7, "", &unimplemented_instruction, 0, 1},
  {0xa8, "", &unimplemented_instruction, 0, 1},
  {0xa9, "", &unimplemented_instruction, 0, 1},
  {0xaa, "", &unimplemented_instruction, 0, 1},
  {0xab, "", &unimplemented_instruction, 0, 1},
  {0xac, "", &unimplemented_instruction, 0, 1},
  {0xad, "", &unimplemented_instruction, 0, 1},
  {0xae, "", &unimplemented_instruction, 0, 1},
  {0xaf, "", &i_xor_a, 0, 1},
  {0xb0, "", &unimplemented_instruction, 0, 1},
  {0xb1, "", &unimplemented_instruction, 0, 1},
  {0xb2, "", &unimplemented_instruction, 0, 1},
  {0xb3, "", &unimplemented_instruction, 0, 1},
  {0xb4, "", &unimplemented_instruction, 0, 1},
  {0xb5, "", &unimplemented_instruction, 0, 1},
  {0xb6, "", &unimplemented_instruction, 0, 1},
  {0xb7, "", &unimplemented_instruction, 0, 1},
  {0xb8, "", &unimplemented_instruction, 0, 1},
  {0xb9, "", &unimplemented_instruction, 0, 1},
  {0xba, "", &unimplemented_instruction, 0, 1},
  {0xbb, "", &unimplemented_instruction, 0, 1},
  {0xbc, "", &unimplemented_instruction, 0, 1},
  {0xbd, "", &unimplemented_instruction, 0, 1},
  {0xbe, "", &unimplemented_instruction, 0, 1},
  {0xbf, "", &unimplemented_instruction, 0, 1},
  {0xc0, "", &unimplemented_instruction, 0, 1},
  {0xc1, "", &unimplemented_instruction, 0, 1},
  {0xc2, "", &unimplemented_instruction, 0, 1},
  {0xc3, "", &i_jp_nn, 0, 1},
  {0xc4, "", &unimplemented_instruction, 0, 1},
  {0xc5, "", &unimplemented_instruction, 0, 1},
  {0xc6, "", &unimplemented_instruction, 0, 1},
  {0xc7, "", &unimplemented_instruction, 0, 1},
  {0xc8, "", &unimplemented_instruction, 0, 1},
  {0xc9, "", &unimplemented_instruction, 0, 1},
  {0xca, "", &unimplemented_instruction, 0, 1},
  {0xcb, "", &unimplemented_instruction, 0, 1},
  {0xcc, "", &unimplemented_instruction, 0, 1},
  {0xcd, "", &unimplemented_instruction, 0, 1},
  {0xce, "", &unimplemented_instruction, 0, 1},
  {0xcf, "", &unimplemented_instruction, 0, 1},
  {0xd0, "", &unimplemented_instruction, 0, 1},
  {0xd1, "", &unimplemented_instruction, 0, 1},
  {0xd2, "", &unimplemented_instruction, 0, 1},
  {0xd3, "", &unimplemented_instruction, 0, 1},
  {0xd4, "", &unimplemented_instruction, 0, 1},
  {0xd5, "", &unimplemented_instruction, 0, 1},
  {0xd6, "", &unimplemented_instruction, 0, 1},
  {0xd7, "", &unimplemented_instruction, 0, 1},
  {0xd8, "", &unimplemented_instruction, 0, 1},
  {0xd9, "", &unimplemented_instruction, 0, 1},
  {0xda, "", &unimplemented_instruction, 0, 1},
  {0xdb, "", &unimplemented_instruction, 0, 1},
  {0xdc, "", &unimplemented_instruction, 0, 1},
  {0xdd, "", &unimplemented_instruction, 0, 1},
  {0xde, "", &unimplemented_instruction, 0, 1},
  {0xdf, "", &unimplemented_instruction, 0, 1},
  {0xe0, "", &unimplemented_instruction, 0, 1},
  {0xe1, "", &unimplemented_instruction, 0, 1},
  {0xe2, "", &unimplemented_instruction, 0, 1},
  {0xe3, "", &unimplemented_instruction, 0, 1},
  {0xe4, "", &unimplemented_instruction, 0, 1},
  {0xe5, "", &unimplemented_instruction, 0, 1},
  {0xe6, "", &unimplemented_instruction, 0, 1},
  {0xe7, "", &unimplemented_instruction, 0, 1},
  {0xe8, "", &unimplemented_instruction, 0, 1},
  {0xe9, "", &unimplemented_instruction, 0, 1},
  {0xea, "", &unimplemented_instruction, 0, 1},
  {0xeb, "", &unimplemented_instruction, 0, 1},
  {0xec, "", &unimplemented_instruction, 0, 1},
  {0xed, "", &unimplemented_instruction, 0, 1},
  {0xee, "", &unimplemented_instruction, 0, 1},
  {0xef, "", &unimplemented_instruction, 0, 1},
  {0xf0, "", &unimplemented_instruction, 0, 1},
  {0xf1, "", &unimplemented_instruction, 0, 1},
  {0xf2, "", &unimplemented_instruction, 0, 1},
  {0xf3, "", &unimplemented_instruction, 0, 1},
  {0xf4, "", &unimplemented_instruction, 0, 1},
  {0xf5, "", &unimplemented_instruction, 0, 1},
  {0xf6, "", &unimplemented_instruction, 0, 1},
  {0xf7, "", &unimplemented_instruction, 0, 1},
  {0xf8, "", &unimplemented_instruction, 0, 1},
  {0xf9, "", &unimplemented_instruction, 0, 1},
  {0xfa, "", &unimplemented_instruction, 0, 1},
  {0xfb, "", &unimplemented_instruction, 0, 1},
  {0xfc, "", &unimplemented_instruction, 0, 1},
  {0xfd, "", &unimplemented_instruction, 0, 1},
  {0xfe, "", &unimplemented_instruction, 0, 1},
  {0xff, "", &i_rst_38, 0, 1}
};
