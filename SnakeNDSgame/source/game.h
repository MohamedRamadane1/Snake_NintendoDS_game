#include <nds.h>
#include <stdio.h>
#include "Graphics.h"
#include <sys/dir.h>
#include <fat.h>
#include <dirent.h>
#include "audio.h"
#define DUP 1
#define DRIGHT 2
#define DDOWN 3
#define DLEFT 4

typedef struct coord
{
   u8 x;
   u8 y;
   u8 dir;
   u8 state;
} coord ;
coord snak[150];
coord snak2[150];
coord food;
coord s_food;
coord r_food;
u8 length;
u8 length2;
void initialise_snake(void);
void initialise_snake2(void);
u32 keys;
void handle_input(void);
void handle_input0(void);
//void handle_input2(void);
void move_snak(void);
void move_snak2(void);
void check_obstacle(void);
void check_obstacle2(void);
void check_itself(void);
void check_itself2(void);
void increment_snake(void);
void increment_snake2(void);
void generate_food(void);
void check_food(void);
void check_food2(void);
void generate_s_food(void);
void destroy_s_food(void);
void generate_r_food(void);
void destroy_r_food(void);
void initialise_timer0(void);
//void initialise_timer1(void);
void write_h_score(void);
void read_h_score(void);
void game2(void);
int score;
int score2;
int h_score;
u8 sto_p;
u8 s_gamer;
u8 activate_game;
int speed;
