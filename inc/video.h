#ifndef VIDEO_H_
# define VIDEO_H_

# include <SDL/SDL.h>

# define SDL_WINDOW_X                       (640)
# define SDL_WINDOW_Y                       (480)

# define VRAM_START                         (0x8000)
# define VRAM_END                           (0x9FFF)

# define SCREEN_WIDTH                       (160)
# define SCREEN_HEIGHT                      (144)

# define HBLANK_CYCLES                      (204)
# define VBLANK_CYCLES                      (456)
# define OEM_SEARCH_CYCLES                  (80)
# define PIXEL_TRANSFER_CYCLES              (172)

# define OAM_START                          (0xfe00)
# define OAM_END                            (0xfe9f)

# define DEFAULT_COLOR                      (0xff)

# define SET_STAT_SCREEN_MODE(stat, mode)   (((stat) & (0xFF ^ 0x3)) | (mode))

enum                                        e_stat_screen_mode
{
  MODE_HBLANK         = 0,
  MODE_VBLANK         = 1,
  MODE_OEM_SEARCH     = 2,
  MODE_PIXEL_TRANSFER = 3
};

enum                                        e_lcdc
{
  LCDC_DISPLAY_ENABLE                   = 1 << 7, /* LCD Display Enable - 0b10000000 */
  LCDC_WINDOW_TILE_MAP_DISPLAY_SELECT   = 1 << 6, /* Window Tile Map Display Select - 0b01000000 */
  LCDC_WINDOW_DISPLAY_ENABLE            = 1 << 5, /* Window Display Enable - 0b00100000 */
  LCDC_BG_WINDOW_TILE_DATA_SELECT       = 1 << 4, /* BG & Window Tile Data Select - 0b00010000 */
  LCDC_BG_TILE_MAP_DISPLAY_SELECT       = 1 << 3, /* BG Tile Map Display Select 0b00001000 */
  LCDC_OBJ_SIZE                         = 1 << 2, /* OBJ Size - 0b00000010 */
  LCDC_OBJ_DISPLAY_ENABLE               = 1 << 1, /* OBJ Display Enable - 0b00000010 */
  LCDC_BG_WINDOW_DISPLAY_PRIORITY       = 1 << 0, /* BG/Window Display/Priority - 0b00000001 */
};

enum                                        e_oam_flag
{
  OAM_FLAG_PRIORITY = 1 << 7,
  OAM_FLAG_YFLIP    = 1 << 6,
  OAM_FLAG_XFLIP    = 1 << 5,
  OAM_FLAG_PALETTE  = 1 << 4,
};

typedef struct s_game                       t_game;

typedef struct                              s_gpu
{
  SDL_Surface                               *screen;
  unsigned long long                        cycles;
}                                           t_gpu;

typedef struct                              s_mode_handler
{
  void                                      (*handler)(struct s_game *game);
  unsigned long                             cycle_count;
}                                           t_mode_handler;

typedef struct                              s_oem
{
  uint8_t                                   y;
  uint8_t                                   x;
  uint8_t                                   tile;
  uint8_t                                   flags;
  /**
   *  Bit7   OBJ-to-BG Priority (0=OBJ Above BG, 1=OBJ Behind BG color 1-3)
   *         (Used for both BG and Window. BG color 0 is always behind OBJ)
   *  Bit6   Y flip          (0=Normal, 1=Vertically mirrored)
   *  Bit5   X flip          (0=Normal, 1=Horizontally mirrored)
   *  Bit4   Palette number  **Non CGB Mode Only** (0=OBP0, 1=OBP1)
   *  Bit3   Tile VRAM-Bank  **CGB Mode Only**     (0=Bank 0, 1=Bank 1)
   *  Bit2-0 Palette number  **CGB Mode Only**     (OBP0-7)
   */
}                                           t_oem;

SDL_Surface                                 *setup_SDL();
void                                        refresh(t_game *game);
void                                        destroy_SDL(SDL_Surface *screen);
int                                         gpu_step(t_game *game);
void                                        init_gpu(t_gpu *gpu);

#endif /* !VIDEO_H_ */
