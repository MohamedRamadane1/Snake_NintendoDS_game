/*
 * Template Nintendo DS
 */

#include <nds.h>
#include <stdio.h>
#include "Graphics.h"
#include "game.h"
#include "audio.h"
#include <sys/dir.h>
#include <fat.h>
#include <dirent.h>

int game_speed_ticks=0;
int memory_init;
void game(void)
{
		  initialise_map(map_number);
		  check_obstacle();//
		  draw_food();
		//  handle_input();
		  if((s_gamer==1)&&(sto_p==1))
		  {
			  game2();
		  }
		  if((s_food.state)==2)
		  {
			  draw_s_food();
		  }
		  if((r_food.state)==2)
		  {
			  draw_r_food();
		  }
		  check_itself();
		  check_food();
		 // handle_input();
		  display_score();
		  display_h_score();
		  if(sto_p==1)
		  {
		  move_snak();
		  redraw_snake();
	      //
		  }
		  if(sto_p==0)
		 {

			redraw_snake();//
			if(s_gamer==1)
				redraw_snake2();
		 }
	}

void snake(void)
{
	game_speed_ticks++;
 if(game_speed_ticks>=speed)
{
	 handle_input();
   	if(activate_game==0)
   	{
   		if((welcome==1)&&(tutorial==0))
   		{
   		display_welcome_screen();
   		}
   		if((welcome==0)&&(tutorial==1))
   		{
   	   		display_tutorial_screen();
   		}
   	}
   	if(activate_game==1)
   	{
   		if(memory_init==0)
   		{
   	       initialise_memory();
   		  initialise_timer0();
   	       food.x=13;
   	       food.y=9;
   	       memory_init=1;
   		}
   		game();
   	}
   	game_speed_ticks=0;
}
}

int main(void) {

	 	 initialise_BG_MAIN();
	 	 fatInitDefault();
	  	  s_gamer=0;
	  	  activate_game=0;
	  	  memory_init=0;
	  	  welcome=1;
	  	  tutorial=0;
	  	  initialise_snake();
	  	  initialise_snake2();
	  	  h_score=0;
	  	  read_h_score();
	  	  sto_p=1;
	  	  speed=8;
	  	  map_number=0;
	  	 // initialise_timer1();
	  	  //generate_food();
	  	  draw_snake();
	  	  ini_arrow=0;
	  	  music=1;
	  	  init_audio();
   // consoleDemoInit();//
  //  printf("game_sp= % d    activate_game=%d    welcom=%d   tutorial=%d",game_speed_ticks,activate_game,welcome,tutorial);
    //printf("%d  \n",h_score);
    	irqSet(IRQ_VBLANK,&snake);
    	irqEnable(IRQ_VBLANK);

    while(1)
    {
        swiWaitForVBlank();
    }
}
