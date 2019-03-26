#include <nds.h>
#include <stdio.h>
#include "snak.h"
void initialise_map(int a);
void initialise_BG_MAIN(void);
void draw_snake(void);
void redraw_snake(void);
void redraw_snake2(void);
int return_tile_index(int x, int y);
void draw_food(void);
void draw_s_food(void);
void initialise_memory(void);
void display_score(void);
void display_score2(void);
void display_h_score(void);
void display_tutorial_screen(void);
void display_welcome_screen(void);
void display_setting_screen(void);
void draw_r_food(void);
//void recolor_tile_snake1(void);
void recolor_tile_snake(int a, int b ,int c);
void recolor_tile_snake2(void);
int welcome,tutorial;
int map_number;
int ini_arrow;
