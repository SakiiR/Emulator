#include "resource.h"
#include "cpu.h"
#include "game.h"
#include "register.h"
#include "memory_ar.h"


int                 i_ld8_b_n(t_game *game)
{
  game->state.b = game->state.op8;
  return RETURN_SUCCESS;
}

int                 i_ld8_c_n(t_game *game)
{
  game->state.c = game->state.op8;
  return RETURN_SUCCESS;
}

int                 i_ld8_d_n(t_game *game)
{
  game->state.d = game->state.op8;
  return RETURN_SUCCESS;
}

int                 i_ld8_e_n(t_game *game)
{
  game->state.e = game->state.op8;
  return RETURN_SUCCESS;
}

int                 i_ld8_h_n(t_game *game)
{
  game->state.h = game->state.op8;
  return RETURN_SUCCESS;
}

int                 i_ld8_l_n(t_game *game)
{
  game->state.l = game->state.op8;
  return RETURN_SUCCESS;
}

/* Register loads */


int                 i_ld8_a_a(t_game *game)
{
  game->state.a = game->state.a;
  return RETURN_SUCCESS;
}

int                 i_ld8_a_b(t_game *game)
{
  game->state.a = game->state.b;
  return RETURN_SUCCESS;
}

int                 i_ld8_a_c(t_game *game)
{
  game->state.a = game->state.c;
  return RETURN_SUCCESS;
}

int                 i_ld8_a_d(t_game *game)
{
  game->state.a = game->state.d;
  return RETURN_SUCCESS;
}

int                 i_ld8_a_e(t_game *game)
{
  game->state.a = game->state.e;
  return RETURN_SUCCESS;
}

int                 i_ld8_a_h(t_game *game)
{
  game->state.a = game->state.h;
  return RETURN_SUCCESS;
}

int                 i_ld8_a_l(t_game *game)
{
  game->state.a = game->state.l;
  return RETURN_SUCCESS;
}

int                 i_ld8_a_hl(t_game *game)
{
  game->state.a = read_byte(game, game->state.hl);
  return RETURN_SUCCESS;
}

int                 i_ld8_b_b(t_game *game)
{
  game->state.b = game->state.b;
  return RETURN_SUCCESS;
}

int                 i_ld8_b_c(t_game *game)
{
  game->state.b = game->state.c;
  return RETURN_SUCCESS;
}

int                 i_ld8_b_d(t_game *game)
{
  game->state.b = game->state.d;
  return RETURN_SUCCESS;
}

int                 i_ld8_b_e(t_game *game)
{
  game->state.b = game->state.e;
  return RETURN_SUCCESS;
}

int                 i_ld8_b_h(t_game *game)
{
  game->state.b = game->state.h;
  return RETURN_SUCCESS;
}

int                 i_ld8_b_l(t_game *game)
{
  game->state.b = game->state.l;
  return RETURN_SUCCESS;
}

int                 i_ld8_b_hl(t_game *game)
{
  game->state.b = read_byte(game, game->state.hl);
  return RETURN_SUCCESS;
}

int                 i_ld8_c_b(t_game *game)
{
  game->state.c = game->state.b;
  return RETURN_SUCCESS;
}

int                 i_ld8_c_c(t_game *game)
{
  game->state.c = game->state.c;
  return RETURN_SUCCESS;
}

int                 i_ld8_c_d(t_game *game)
{
  game->state.c = game->state.d;
  return RETURN_SUCCESS;
}

int                 i_ld8_c_e(t_game *game)
{
  game->state.c = game->state.e;
  return RETURN_SUCCESS;
}

int                 i_ld8_c_h(t_game *game)
{
  game->state.c = game->state.h;
  return RETURN_SUCCESS;
}

int                 i_ld8_c_l(t_game *game)
{
  game->state.c = game->state.l;
  return RETURN_SUCCESS;
}

int                 i_ld8_c_hl(t_game *game)
{
  game->state.c = read_byte(game, game->state.hl);
  return RETURN_SUCCESS;
}

int                 i_ld8_d_b(t_game *game)
{
  game->state.d = game->state.b;
  return RETURN_SUCCESS;
}

int                 i_ld8_d_c(t_game *game)
{
  game->state.d = game->state.c;
  return RETURN_SUCCESS;
}

int                 i_ld8_d_d(t_game *game)
{
  game->state.d = game->state.d;
  return RETURN_SUCCESS;
}

int                 i_ld8_d_e(t_game *game)
{
  game->state.d = game->state.e;
  return RETURN_SUCCESS;
}

int                 i_ld8_d_h(t_game *game)
{
  game->state.d = game->state.h;
  return RETURN_SUCCESS;
}

int                 i_ld8_d_l(t_game *game)
{
  game->state.d = game->state.l;
  return RETURN_SUCCESS;
}

int                 i_ld8_d_hl(t_game *game)
{
  game->state.d = read_byte(game, game->state.hl);
  return RETURN_SUCCESS;
}

int                 i_ld8_e_b(t_game *game)
{
  game->state.e = game->state.b;
  return RETURN_SUCCESS;
}

int                 i_ld8_e_c(t_game *game)
{
  game->state.e = game->state.c;
  return RETURN_SUCCESS;
}

int                 i_ld8_e_d(t_game *game)
{
  game->state.e = game->state.d;
  return RETURN_SUCCESS;
}

int                 i_ld8_e_e(t_game *game)
{
  game->state.e = game->state.e;
  return RETURN_SUCCESS;
}

int                 i_ld8_e_h(t_game *game)
{
  game->state.e = game->state.h;
  return RETURN_SUCCESS;
}

int                 i_ld8_e_l(t_game *game)
{
  game->state.e = game->state.l;
  return RETURN_SUCCESS;
}

int                 i_ld8_e_hl(t_game *game)
{
  game->state.e = read_byte(game, game->state.hl);
  return RETURN_SUCCESS;
}

int                 i_ld8_h_b(t_game *game)
{
  game->state.h = game->state.b;
  return RETURN_SUCCESS;
}

int                 i_ld8_h_c(t_game *game)
{
  game->state.h = game->state.c;
  return RETURN_SUCCESS;
}

int                 i_ld8_h_d(t_game *game)
{
  game->state.h = game->state.d;
  return RETURN_SUCCESS;
}

int                 i_ld8_h_e(t_game *game)
{
  game->state.h = game->state.e;
  return RETURN_SUCCESS;
}

int                 i_ld8_h_h(t_game *game)
{
  game->state.h = game->state.h;
  return RETURN_SUCCESS;
}

int                 i_ld8_h_l(t_game *game)
{
  game->state.h = game->state.l;
  return RETURN_SUCCESS;
}

int                 i_ld8_h_hl(t_game *game)
{
  game->state.h = read_byte(game, game->state.hl);
  return RETURN_SUCCESS;
}

int                 i_ld8_l_b(t_game *game)
{
  game->state.l = game->state.b;
  return RETURN_SUCCESS;
}

int                 i_ld8_l_c(t_game *game)
{
  game->state.l = game->state.c;
  return RETURN_SUCCESS;
}

int                 i_ld8_l_d(t_game *game)
{
  game->state.l = game->state.d;
  return RETURN_SUCCESS;
}

int                 i_ld8_l_e(t_game *game)
{
  game->state.l = game->state.e;
  return RETURN_SUCCESS;
}

int                 i_ld8_l_h(t_game *game)
{
  game->state.l = game->state.h;
  return RETURN_SUCCESS;
}

int                 i_ld8_l_l(t_game *game)
{
  game->state.l = game->state.l;
  return RETURN_SUCCESS;
}

int                 i_ld8_l_hl(t_game *game)
{
  write_byte(game, game->state.hl, game->state.l);
  return RETURN_SUCCESS;
}

int                 i_ld8_hl_b(t_game *game)
{
  write_byte(game, game->state.hl, game->state.b);
  return RETURN_SUCCESS;
}

int                 i_ld8_hl_c(t_game *game)
{
  write_byte(game, game->state.hl, game->state.c);
  return RETURN_SUCCESS;
}

int                 i_ld8_hl_d(t_game *game)
{
  write_byte(game, game->state.hl, game->state.d);
  return RETURN_SUCCESS;
}

int                 i_ld8_hl_e(t_game *game)
{
  write_byte(game, game->state.hl, game->state.e);
  return RETURN_SUCCESS;
}

int                 i_ld8_hl_h(t_game *game)
{
  write_byte(game, game->state.hl, game->state.h);
  return RETURN_SUCCESS;
}

int                 i_ld8_hl_l(t_game *game)
{
  write_byte(game, game->state.hl, game->state.l);
  return RETURN_SUCCESS;
}

int                 i_ld8_hl_n(t_game *game)
{
  write_byte(game, game->state.hl, game->state.op8);
  return RETURN_SUCCESS;
}



int                 i_ld8_a_bc(t_game *game)
{
  game->state.a = read_byte(game, game->state.bc);
  return RETURN_SUCCESS;
}

int                 i_ld8_a_de(t_game *game)
{
  game->state.a = read_byte(game, game->state.de);
  return RETURN_SUCCESS;
}

int                 i_ld8_a_nn(t_game *game)
{
  game->state.a = read_byte(game, game->state.op16) ;
  return RETURN_SUCCESS;
}

int                 i_ld8_a_sharp(t_game *game)
{
  game->state.a = game->state.op8;
  return RETURN_SUCCESS;
}



int                 i_ld8_b_a(t_game *game)
{
  game->state.b = game->state.a;
  return RETURN_SUCCESS;
}

int                 i_ld8_c_a(t_game *game)
{
  game->state.c = game->state.a;
  return RETURN_SUCCESS;
}

int                 i_ld8_d_a(t_game *game)
{
  game->state.d = game->state.a;
  return RETURN_SUCCESS;
}

int                 i_ld8_e_a(t_game *game)
{
  game->state.e = game->state.a;
  return RETURN_SUCCESS;
}

int                 i_ld8_h_a(t_game *game)
{
  game->state.h = game->state.a;
  return RETURN_SUCCESS;
}

int                 i_ld8_l_a(t_game *game)
{
  game->state.l = game->state.a;
  return RETURN_SUCCESS;
}

int                 i_ld8_bc_a(t_game *game)
{
  write_byte(game, game->state.bc, game->state.a);
  return RETURN_SUCCESS;
}

int                 i_ld8_de_a(t_game *game)
{
  write_byte(game, game->state.de, game->state.a);
  return RETURN_SUCCESS;
}

int                 i_ld8_hl_a(t_game *game)
{
  write_byte(game, game->state.hl, game->state.a);
  return RETURN_SUCCESS;
}

int                 i_ld8_nn_a(t_game *game)
{
  write_byte(game, game->state.op16, game->state.a);
  return RETURN_SUCCESS;
}

int                 i_ld8_a_cp(t_game *game)
{
  game->state.a = read_byte(game, 0xFF00 + game->state.c);
  return RETURN_SUCCESS;
}

int                 i_ld8_cp_a(t_game *game)
{
  write_byte(game, game->state.c + 0xFF00, game->state.a);
  return RETURN_SUCCESS;
}

int                 i_ldd8_a_hl(t_game *game)
{
  game->state.a = read_byte(game, game->state.hl);
  --game->state.hl;
  return RETURN_SUCCESS;
}

int                 i_ldd8_hl_a(t_game *game)
{
  write_byte(game, game->state.hl, game->state.a);
  --game->state.hl;
  return RETURN_SUCCESS;
}

int                 i_ldi8_a_hl(t_game *game)
{
  game->state.a = read_byte(game, game->state.hl);
  ++game->state.hl;
  return RETURN_SUCCESS;
}

int                 i_ldi8_hl_a(t_game *game)
{
  write_byte(game, game->state.hl, game->state.a);
  ++game->state.hl;
  return RETURN_SUCCESS;
}

int                 i_ld_ff00_n_a(t_game *game)
{
  write_byte(game, 0xFF00 + game->state.op8, game->state.a);
  return RETURN_SUCCESS;
}

int                 i_ld_a_ff00_n(t_game *game)
{
  game->state.a = read_byte(game, 0xFF00 + game->state.op8);
  return RETURN_SUCCESS;
}

int                 i_ld16_hl_sp_n(t_game *game)
{
  uint8_t           op1 = game->state.sp;
  uint8_t           op2 = game->state.op8;

  game->state.hl = op1 + op2;
  reset_Z(&game->state.f);
  reset_N(&game->state.f);
  half_carry_check(&game->state.f, op1, op2);
  carry_check(&game->state.f, op1, op2, game->state.hl);
  return RETURN_SUCCESS;
}
