#include"game.h"
#include "audio.h"
//u8 random_state[8]={0,0,0,1,0,0,0,0};//
u8 timer_ticks=0;
u8 timer_ticks2=0;
u8 timer_ticks3=0;
u8 timer_ticks4=0;
void initialise_snake(void)
{
	write_h_score();
   snak[0].state=1;
   snak[0].x=16;
   snak[0].y=12;
   snak[0].dir=DRIGHT;
   snak[1].state=1;
   snak[1].x=16;
   snak[1].y=11;
   snak[2].state=1;
   snak[2].x=16;
   snak[2].y=10;
   snak[3].state=1;
   snak[3].x=16;
   snak[3].y=9;
   length=4;
   score=14;
   write_h_score();
   int k;
   for(k=length;k<60;k++)
	   snak[k].state=1;

}
void handle_input(void)
{
	 scanKeys();
     keys=keysDown();//
     unsigned held=keysHeld();
     if(activate_game==1)
     {
	if((keys & KEY_UP)&&(snak[0].dir!=DDOWN))
	{
		//printf("UP  %d  %d  %d /n " ,snak[5].x,snak[5].y ,length  );
		snak[0].dir=DUP;
		goto ADD1;
	    //move_snak();
	}
	if((keys & KEY_LEFT)&&(snak[0].dir!=DRIGHT))
	{
			snak[0].dir=DLEFT;
			goto ADD1;
	         //move_snak();
	}
	if((keys & KEY_RIGHT)&&(snak[0].dir!=DLEFT))
	{
		//printf("right   %d  %d /n" ,snak[0].x,snak[0].y );
			snak[0].dir=DRIGHT;
			goto ADD1;
			//move_snak();
	}

	if((keys & KEY_DOWN)&&(snak[0].dir!=DUP))
	{
		//printf("down  %d  %d /n" ,snak[0].x,snajkkjckjdsk[0].y );
			snak[0].dir=DDOWN;
			goto ADD1;
			//move_snak();
	}
ADD1:
if((keys & KEY_START))
	{
		if(sto_p==0)
		{
		   sto_p=1;
		   return;
		}
		if(sto_p==1)
		{
		    sto_p=0;
		    return;
		}
	}
	if(held & KEY_TOUCH)
	{
		touchPosition p;
		touchRead(&p);
		if(p.px || p.py)
		{
		if((p.px<85)&&(p.py<64))
			speed=14;

		if((p.px<170)&&(p.px>85)&&(p.py<64))
			speed=8;
		if((p.px>170)&&(p.px<255)&&(p.py<64))
			speed=2;
		if((p.px>85)&&(p.px<170)&&(p.py>153))
		{
			initialise_snake();
			initialise_snake2();
				map_number=1;
		}
		if((p.px>85)&&(p.px<170)&&(p.py<153)&&(p.py>115))
				{
					initialise_snake();
					initialise_snake2();
					map_number=0;
				}
		if((p.px<85)&&(p.py<153)&&(p.py>115))
						{
							initialise_snake();
							initialise_snake2();
							map_number=2;
						}
		if((p.px>170)&&(p.py<153)&&(p.py>115))
								{
									initialise_snake();
									initialise_snake2();
									map_number=3;
								}
		if((p.py>153)&&(p.px<85))
		{
			music=1;
			init_audio();
		}
		if((p.py>153)&&(p.px>170))
		{
			music=2;
			init_audio();
		}

	}
	}
	if(keys==KEY_SELECT)
	{
      if(s_gamer==1)
      {
    	  s_gamer=0;
    	  return;
      }
      if(s_gamer==0)
            {
    	//  initWifi();
    	//  openSocket();//
          	  s_gamer=1;
          	  return;
          	  //
            }
	}



	if(s_gamer==1)
	{
	if((keys & KEY_X)&&(snak2[0].dir!=DDOWN))
		{
			//printf("UP  %d  %d  %d /n " ,snak[5].x,snak[5].y ,length  );
			snak2[0].dir=DUP;
			goto ADD2;
		    //move_snak();
		}
		if((keys & KEY_Y)&&(snak2[0].dir!=DRIGHT))
		{
				snak2[0].dir=DLEFT;
				goto ADD2;
		         //move_snak();
		}
		if((keys & KEY_A)&&(snak2[0].dir!=DLEFT))
		{
			//printf("right   %d  %d /n" ,snak[0].x,snak[0].y );
				snak2[0].dir=DRIGHT;
				goto ADD2;
				//move_snak();
		}

		if((keys & KEY_B)&&(snak2[0].dir!=DUP))
		{
			//printf("down  %d  %d /n" ,snak[0].x,snajkkjckjdsk[0].y );
				snak2[0].dir=DDOWN;
				goto ADD2;
				//move_snak();
		}
	}

}
 ADD2:
 if(activate_game==0)
     {
	// printf("activate_game");
    	        if((keys == KEY_A)&&(ini_arrow==1))
    	     			activate_game=1;
    	     		//if((pos.px>84)&&(pos.px<168)&&(pos.py>76)&&(pos.py<115))
    	     		if((keys == KEY_A)&&(ini_arrow==0))
    	     		    {
    	     			//printf("key1 init arrwo   %d",ini_arrow);
    	     			if((welcome==1)&&(tutorial==0))
    	     			   		{

    	     			   		welcome=0;
    	     			   		tutorial=1;
    	     			   		//printf("we changed welcome to tutorial");

    	                           return;
    	                        //   printf("should not be displayed");
    	     			   		}
    	     			if((welcome==0)&&(tutorial==1))
    	     			{
    	     				welcome=1;
    	     				tutorial=0;
    	     				//printf("we changed tutorial to welcom");
    	     				return;
    	     			}
    	     		    }
    	     		if((keys & KEY_UP) || (keys & KEY_DOWN))
    	     		{
    	     			if(ini_arrow==1)
    	     			{
    	     				ini_arrow=0;
    	     				return;
    	     			}
    	     			if(ini_arrow==0)
    	     			{
    	     				ini_arrow=1;
    	     				return;
    	     			}
    	     		}
     }


	}


void move_snak(void)
{
   	int i;
   	if((snak[0].dir==DUP)&&((snak[0].y)>0))
   	   		{

   	   			for(i=length-1;i>0;i--)
   	   			{
   	   				snak[i].x=snak[i-1].x;
   	   				snak[i].y=snak[i-1].y;
   	   			}
   	   		snak[0].y=snak[0].y-1;
   	   			return;

   	   		}
 	if((snak[0].dir==DDOWN)&&((snak[0].y)<24))
   	   		{

   	   			for(i=length-1;i>0;i--)
   	   			{
   	   				snak[i].x=snak[i-1].x;
   	   				snak[i].y=snak[i-1].y;
   	   			}
   	   		snak[0].y=snak[0].y+1;
   	   			return;

   	   		}
	if((snak[0].dir==DLEFT)&&((snak[0].x)>0))
   	   		{

		for(i=length-1;i>0;i--)
   	   			{
   	   				snak[i].x=snak[i-1].x;
   	   				snak[i].y=snak[i-1].y;
   	   			}
   	   		snak[0].x=snak[0].x-1;
   	   			return;

   	   		}
	if((snak[0].dir==DRIGHT)&&((snak[0].x)<32))
	   	   		{

		for(i=length-1;i>0;i--)
	   	   			{
	   	   				snak[i].x=snak[i-1].x;
	   	   				snak[i].y=snak[i-1].y;
	   	   				//
	   	   			}
	   	   		snak[0].x=snak[0].x+1;
	   	   			return;

	   	   		}
	for(i=0;i<length;i++)
	{
		if(snak[i].x>=32)
		{
			snak[i].x=1;
		}
		if(snak[i].y>=24)
				{
					snak[i].y=1;
				}
		if(snak[i].x<=0)
				{
					snak[i].x=31;
				}
		if(snak[i].y<=0)
				{
					snak[i].y=23;
				}
	}
}
void check_obstacle(void)
{
if(snak[0].state!=7)
 {
   u8 val;
   val=return_tile_index(snak[0].x,snak[0].y);
        if(val==0)
           {
	          initialise_snake();
	          sound.rate = (int)(1.059f * 1024);
	          		mmEffectEx(&sound);
            }
   }

 }

void check_itself(void)
{
	if(snak[0].state!=7)
  {
    u8 i;
    for(i=3;i<length;i++)
    {
    	if((snak[0].x==snak[i].x)&&(snak[0].y==snak[i].y))
    	{
    		initialise_snake();
    		sound.rate = (int)(1.059f * 1024);
    			          		mmEffectEx(&sound);
    	}
    }
  }
}
void increment_snake(void)
{
   length++;//
   printf("inc");
   if(snak[0].dir==DUP)
   {
	   snak[length-1].x=snak[length-2].x;
	   snak[length-1].y=snak[length-2].y+1;
   }
   if(snak[0].dir==DDOWN)
     {
  	   snak[length-1].x=snak[length-2].x;
  	   snak[length-1].y=snak[length-2].y-1;
     }
   if(snak[0].dir==DRIGHT)
        {
     	   snak[length-1].x=snak[length-2].x-1;
     	   snak[length-1].y=snak[length-2].y;
        }
   if(snak[0].dir==DLEFT)
        {
     	   snak[length-1].x=snak[length-2].x+1;
     	   snak[length-1].y=snak[length-2].y;
        }

}
void generate_food(void)
{
	int a,b,i,val;
	a=rand()%30+1;
	b=rand()%22+1;
	val=return_tile_index(a,b);
	if(val!=0)
	{
	food.x=a;
	food.y=b;
	for(i=0;i<length;i++)
	{
		if((snak[i].x==food.x)&&(snak[i].y==food.y))
			generate_food();
		if((s_gamer==1)&&(snak2[i].x==food.x)&&(snak2[i].y==food.y))
			generate_food();
	}
	}
	if(val==0)
	{
		generate_food();
	}

}
void check_food(void)
{
   if(((snak[0].x)==(food.x))&&((snak[0].y)==(food.y)))
   {
	   generate_food();
	  // printf("hop   %d",length);
	   increment_snake();
	   score=score+1;
	   sound.rate = (int)(3.059f * 1024);
	   	          		mmEffectEx(&sound);
   }
   if(((snak[0].x)==(s_food.x))&&((snak[0].y)==(s_food.y))&&(s_food.state==2))
   {
	   increment_snake();
	   increment_snake();
	   increment_snake();
	    destroy_s_food();
	    score=score+3;
	    sound.rate = (int)(0.859f * 1024);
	   	   	          		mmEffectEx(&sound);

   }
   if(((snak[0].x)==(r_food.x))&&((snak[0].y)==(r_food.y))&&(r_food.state==2))
      {
   	    destroy_r_food();
   	    snak[0].state=7;
   	    score=score+3;
   	    sound.rate = (int)(0.859f * 1024);
   	   	   	          		mmEffectEx(&sound);
   	   	   if(s_gamer==1)
   	   	   {
   	   		   snak2[0].state=7;
   	   	   }

      }

   if(score>=h_score)
        {
	   h_score=score;
	   //write_h_score();
        }
}
void timer0_isr(void)
{
    timer_ticks++;//
    timer_ticks2++;
    if(timer_ticks==30)
    {
    	generate_s_food();
    }
    if(timer_ticks==40)
    {
       destroy_s_food();
       timer_ticks=0;
    }
    if(timer_ticks2==50)
        {
        	generate_r_food();
        }
    if(timer_ticks2==60)
        {
           destroy_r_food();
           timer_ticks2=0;
        }
    if(snak[0].state==7)
    {
    	timer_ticks3++;
    	if(timer_ticks3>15)
    	{
    		snak[0].state=1;
    		snak2[0].state=1;
    		timer_ticks3=0;
    	}
    }
}
void initialise_timer0(void)
{
      TIMER0_CR=TIMER_ENABLE | TIMER_DIV_1024 | TIMER_IRQ_REQ;
      TIMER_DATA(0)=TIMER_FREQ_1024(2);
      irqSet(IRQ_TIMER0,&timer0_isr);
      irqEnable(IRQ_TIMER0);
}
void generate_s_food(void)
{
  int a,b,i,val;
  a=rand()%30+1;
  	b=rand()%22+1;
  	val=return_tile_index(a,b);
  if(val!=0)
  {
	  s_food.x=a;
	  s_food.y=b;
	  s_food.state=2;
	  for(i=0;i<length;i++)
	  	{
	  		if((snak[i].x==s_food.x)&&(snak[i].y==s_food.y))
	  			generate_s_food();
	  		if((s_gamer==1)&&(snak2[i].x==s_food.x)&&(snak2[i].y==s_food.y))
	  			generate_s_food();
	  	}
  }
  if(val==0)
	  generate_s_food();

}
void destroy_s_food(void)
{
     s_food.state=0;
}
void generate_r_food(void)
{
	int a,b,i,val;
	  a=rand()%30+1;
	  	b=rand()%22+1;
	  	val=return_tile_index(a,b);
	  	if(val!=0)
	  	{
		  r_food.x=a;
		  r_food.y=b;
		  r_food.state=2;
		  for(i=0;i<length;i++)
		  	{
		  		if((snak[i].x==r_food.x)&&(snak[i].y==r_food.y))
		  			generate_r_food();
		  		if((s_gamer==1)&&(snak2[i].x==r_food.x)&&(snak2[i].y==r_food.y))
		  			generate_r_food();
		  	}
	  	}
	  	if(val==0)
	  		generate_r_food();
}
void destroy_r_food(void)
{
	r_food.state=0;
}
void write_h_score(void)
{
	DIR * di;
	di=opendir("/");
	FILE* file = fopen("/h_score.txt","w+");
		if(file != NULL)
		{   //
			//printf("we write on file");
			//Print the value in the file
			fprintf(file,"%i\n",h_score);
			//Close the file
			fclose(file);
		}
		closedir(di);
}
void read_h_score(void)
{
	DIR * di;
	di=opendir("/");
 	FILE * file = fopen("/h_score.txt","r");
		if(file != NULL)
		{
			printf("je suis entrer");
			//Read the value and put it into the variable
			fscanf(file,"%i",&h_score);
			// close the file
			fclose(file);
		}
		closedir(di);
}
////////   SNAKE 2 CODE
void initialise_snake2(void)
{
   snak2[0].state=1;
   snak2[0].x=16;
   snak2[0].y=6;
   snak2[0].dir=DRIGHT;
   snak2[1].state=1;
   snak2[1].x=16;
   snak2[1].y=5;
   snak2[2].state=1;
   snak2[2].x=16;
   snak2[2].y=4;
   snak2[3].state=1;
   snak2[3].x=16;
   snak2[3].y=3;
   length2=4;
   score2=14;
   int k;
   for(k=length2;k<60;k++)
	   snak2[k].state=1;

}




void move_snak2(void)
{
   	int i;
   	if((snak2[0].dir==DUP)&&((snak2[0].y)>0))
   	   		{

   	   			for(i=length2-1;i>0;i--)
   	   			{
   	   				snak2[i].x=snak2[i-1].x;
   	   				snak2[i].y=snak2[i-1].y;
   	   			}
   	   		snak2[0].y=snak2[0].y-1;
   	   			return;

   	   		}
 	if((snak2[0].dir==DDOWN)&&((snak2[0].y)<24))
   	   		{

   	   			for(i=length2-1;i>0;i--)
   	   			{
   	   				snak2[i].x=snak2[i-1].x;
   	   				snak2[i].y=snak2[i-1].y;
   	   			}
   	   		snak2[0].y=snak2[0].y+1;
   	   			return;

   	   		}
	if((snak2[0].dir==DLEFT)&&((snak2[0].x)>0))
   	   		{

		for(i=length2-1;i>0;i--)
   	   			{
   	   				snak2[i].x=snak2[i-1].x;
   	   				snak2[i].y=snak2[i-1].y;
   	   			}
   	   		snak2[0].x=snak2[0].x-1;
   	   			return;

   	   		}
	if((snak2[0].dir==DRIGHT)&&((snak2[0].x)<32))
	   	   		{

		for(i=length2-1;i>0;i--)
	   	   			{
	   	   				snak2[i].x=snak2[i-1].x;
	   	   				snak2[i].y=snak2[i-1].y;
	   	   				//
	   	   			}
	   	   		snak2[0].x=snak2[0].x+1;
	   	   			return;

	   	   		}
	for(i=0;i<length2;i++)
	{
		if(snak2[i].x>=32)
		{
			snak2[i].x=1;
		}
		if(snak2[i].y>=24)
				{
					snak2[i].y=1;
				}
		if(snak2[i].x<=0)
				{
					snak2[i].x=31;
				}
		if(snak2[i].y<=0)
				{
					snak2[i].y=23;
				}
	}
}
void check_obstacle2(void)
{
if(snak2[0].state!=7)
 {
   u8 val;
   val=return_tile_index(snak2[0].x,snak2[0].y);
        if(val==0)
           {
	          initialise_snake2();
	          sound.rate = (int)(1.059f * 1024);
	          		mmEffectEx(&sound);
            }

 }
}
void check_itself2(void)
{
	if(snak2[0].state!=7)
  {
    u8 i;
    for(i=3;i<length2;i++)
    {
    	if((snak2[0].x==snak2[i].x)&&(snak2[0].y==snak2[i].y))
    	{
    		initialise_snake2();
    		sound.rate = (int)(1.059f * 1024);
    			          		mmEffectEx(&sound);
    	}
    }
  }
}
void increment_snake2(void)
{
   length2++;//
   printf("inc");
   if(snak2[0].dir==DUP)
   {
	   snak2[length2-1].x=snak2[length2-2].x;
	   snak2[length2-1].y=snak2[length2-2].y+1;
   }
   if(snak2[0].dir==DDOWN)
     {
  	   snak2[length2-1].x=snak2[length2-2].x;
  	   snak2[length2-1].y=snak2[length2-2].y-1;
     }
   if(snak2[0].dir==DRIGHT)
        {
     	   snak2[length2-1].x=snak2[length2-2].x-1;
     	   snak2[length2-1].y=snak2[length2-2].y;
        }
   if(snak2[0].dir==DLEFT)
        {
     	   snak2[length2-1].x=snak2[length2-2].x+1;
     	   snak2[length2-1].y=snak2[length2-2].y;
        }

}

void check_food2(void)
{
   if(((snak2[0].x)==(food.x))&&((snak2[0].y)==(food.y)))
   {
	   generate_food();
	  // printf("hop   %d",length);
	   increment_snake2();
	   score2=score2+length2/4;
	   sound.rate = (int)(3.059f * 1024);
	   	          		mmEffectEx(&sound);
   }
   if(((snak2[0].x)==(s_food.x))&&((snak2[0].y)==(s_food.y))&&(s_food.state==2))
   {
	   increment_snake2();
	   increment_snake2();
	   increment_snake2();
	    destroy_s_food();
	    score2=score2+length2/2;
	    sound.rate = (int)(0.859f * 1024);
	   	   	          		mmEffectEx(&sound);

   }
   if(((snak2[0].x)==(r_food.x))&&((snak2[0].y)==(r_food.y))&&(r_food.state==2))
      {
   	    destroy_r_food();
   	    snak2[0].state=7;
   	    snak[0].state=7;
   	    score2=score2+length2/2;
   	    sound.rate = (int)(0.859f * 1024);
   	   	mmEffectEx(&sound);

      }

}

void game2(void)
{
	check_obstacle2();
	check_itself2();
	check_food2();
	display_score2();
	move_snak2();
	redraw_snake2();
}
