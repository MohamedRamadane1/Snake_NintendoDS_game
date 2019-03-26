#include "Graphics.h"
#include "game.h"
#include "BG.h"
#include "SWSCREEN.h"
#include "SWSUB.h"
#include "STUT.h"
u8 map_index=28;
u8 tile_index=7;
void initialise_BG_MAIN(void)
{
    VRAM_A_CR=VRAM_ENABLE | VRAM_A_MAIN_BG;
    REG_DISPCNT=MODE_5_2D | DISPLAY_BG1_ACTIVE | DISPLAY_BG2_ACTIVE;
    BGCTRL[1]=BG_MAP_BASE(map_index) | BG_TILE_BASE(tile_index) | BG_32x32 | BG_COLOR_256;//
    BGCTRL[2]=BG_MAP_BASE(0) | BgSize_B8_256x256;////
    VRAM_C_CR=VRAM_ENABLE | VRAM_C_SUB_BG;
    REG_DISPCNT_SUB=MODE_5_2D | DISPLAY_BG2_ACTIVE | DISPLAY_BG1_ACTIVE;
    BGCTRL_SUB[2]=BG_BMP_BASE(0) | BgSize_B8_256x256;//
    BGCTRL_SUB[1]=BG_MAP_BASE(map_index) | BG_TILE_BASE(tile_index) | BG_32x32 | BG_COLOR_256;
       REG_BG2PA = 256;
       REG_BG2PC = 0;
       REG_BG2PB = 0;
       REG_BG2PD = 256;
       REG_BG2PA_SUB = 256;
       REG_BG2PC_SUB = 0;
       REG_BG2PB_SUB = 0;
       REG_BG2PD_SUB = 256;

}
u8 tile_zero[64]=
{
		   0,3,3,3,3,3,3,0,
		   0,3,0,0,0,0,3,0,
		   0,3,0,0,0,0,3,0,
		   0,3,0,0,0,0,3,0,
		   0,3,0,0,0,0,3,0,
		   0,3,0,0,0,0,3,0,
		   0,3,0,0,0,0,3,0,
		   0,3,3,3,3,3,3,0,
};
u8 tile_one[64]=
{
		   0,0,0,0,3,0,0,0,
		   0,0,0,3,3,0,0,0,
		   0,0,3,0,3,0,0,0,
		   0,3,0,0,3,0,0,0,
		   0,0,0,0,3,0,0,0,
		   0,0,0,0,3,0,0,0,
		   0,0,0,0,3,0,0,0,
		   0,0,0,0,3,0,0,0
};
u8 tile_two[64]=
{
		   0,3,3,3,3,0,0,0,
		   0,3,0,0,3,0,0,0,
		   0,3,0,0,3,0,0,0,
		   0,3,3,3,3,0,0,0,
		   0,0,0,3,0,0,0,0,
		   0,0,3,0,0,0,0,0,
		   0,3,0,0,0,0,0,0,
		   3,3,3,3,3,3,3,3
};
u8 tile_three[64]=
{
		   3,3,3,3,3,0,0,0,
		   0,0,0,0,3,0,0,0,
		   0,0,0,0,3,0,0,0,
		   3,3,3,3,3,0,0,0,
		   0,0,0,0,3,0,0,0,
		   0,0,0,0,3,0,0,0,
		   0,0,0,0,3,0,0,0,
		   3,3,3,3,3,0,0,0
};
u8 tile_four[64]=
{
		0,0,0,0,3,0,0,0,
		0,0,0,3,3,0,0,0,
		0,0,3,0,3,0,0,0,
		0,3,3,3,3,3,3,0,
		0,0,0,0,3,0,0,0,
		0,0,0,0,3,0,0,0,
		0,0,0,0,3,0,0,0,
		0,0,0,0,3,0,0,0
};
u8 tile_five[64]=
{
		   0,0,3,3,3,3,3,3,
		   0,0,3,0,0,0,0,0,
		   0,0,3,0,0,0,0,0,
		   0,0,3,3,3,3,3,0,
		   0,0,0,0,0,0,3,0,
		   0,0,0,0,0,0,3,0,
		   0,0,0,0,0,0,3,0,
		   0,0,3,3,3,3,3,0,
};
u8 tile_six[64]=
{
		   0,0,3,3,3,3,3,0,
		   0,0,3,0,0,0,0,0,
		   0,0,3,0,0,0,0,0,
		   0,0,3,3,3,3,3,0,
		   0,0,3,0,0,0,3,0,
		   0,0,3,0,0,0,3,0,
		   0,0,3,0,0,0,3,0,
		   0,0,3,3,3,3,3,0,
};
u8 tile_seven[64]=
{
		 3,3,3,3,3,0,0,0,
		 0,0,0,0,3,0,0,0,
		 0,0,0,0,3,0,0,0,
		 0,3,3,3,3,0,0,0,
		 0,0,0,0,3,0,0,0,
		 0,0,0,0,3,0,0,0,
		 0,0,0,0,3,0,0,0,
		 0,0,0,0,3,0,0,0
};
u8 tile_eight[64]=
{
		0,3,3,3,3,3,3,0,
		0,3,0,0,0,0,3,0,
		0,3,0,0,0,0,3,0,
		0,3,3,3,3,3,3,0,
		0,3,0,0,0,0,3,0,
		0,3,0,0,0,0,3,0,
		0,3,0,0,0,0,3,0,
		0,3,3,3,3,3,3,0,
};
u8 tile_nine[64]=
{
		0,3,3,3,3,3,3,0,
		0,3,0,0,0,0,3,0,
		0,3,0,0,0,0,3,0,
		0,3,3,3,3,3,3,0,
		0,0,0,0,0,0,3,0,
		0,0,0,0,0,0,3,0,
		0,0,0,0,0,0,3,0,
		0,3,3,3,3,3,3,0,
};

u8 tile_obstacle[64]=
{
   255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255,
   255,255,255,255,255,255,255,255
};
u8 tile_transparent[64]=
{
   0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,
};
u8 snake_tile[64]=
{
   254,254,254,254,254,254,254,254,
   254,254,254,254,254,254,254,254,
   254,254,254,254,254,254,254,254,
   254,254,254,254,254,254,254,254,
   254,254,254,254,254,254,254,254,
   254,254,254,254,254,254,254,254,
   254,254,254,254,254,254,254,254,
   254,254,254,254,254,254,254,254
};
u8 tile_food[64]=
{
		   0,0,255,255,255,255,0,0,
		   0,0,0,0,255,0,0,0,
		   0,0,0,253,253,253,0,0,
		   0,0,253,253,253,253,253,0,
		   0,0,253,253,253,253,253,0,
		   0,0,253,253,253,253,253,0,
		   0,0,253,253,253,253,253,0,
		   0,0,0,253,253,253,0,0
};
u8 snake_head_right[64]=
{
		   254,254,0,0,0,0,0,0,
		   254,253,253,254,0,0,0,0,
		   254,253,253,254,254,254,0,0,
		   254,254,254,254,254,254,254,254,
		   254,253,253,254,254,254,254,254,
		   254,253,253,254,254,254,0,0,
		   254,254,254,254,0,0,0,0,
		   254,254,0,0,0,0,0,0
};
u8 snake2_head_right[64]=
{
		   254,254,0,0,0,0,0,0,
		   254,3,3,254,0,0,0,0,
		   254,3,3,254,254,254,0,0,
		   254,254,254,254,254,254,254,254,
		   254,3,3,254,254,254,254,254,
		   254,3,3,254,254,254,0,0,
		   254,254,254,254,0,0,0,0,
		   254,254,0,0,0,0,0,0
};
u8 snake_head_up[64]=
{
		0,0,0,254,254,0,0,0,
		0,0,0,254,254,0,0,0,
		0,0,254,254,254,254,0,0,
		0,0,254,254,254,254,0,0,
		0,0,254,254,254,254,0,0,
		0,254,254,254,254,254,254,0,
		0,254,253,253,254,253,253,0,
		254,254,253,253,254,253,253,254
};
u8 snake2_head_up[64]=
{
		0,0,0,254,254,0,0,0,
		0,0,0,254,254,0,0,0,
		0,0,254,254,254,254,0,0,
		0,0,254,254,254,254,0,0,
		0,0,254,254,254,254,0,0,
		0,254,254,254,254,254,254,0,
		0,254,3,3,254,3,3,0,
		254,254,3,3,254,3,3,254
};
u8 s_foodt[64]=
{
		   0,0,0,255,255,255,0,0,
		   0,0,0,0,255,0,0,0,
		   0,0,0,252,252,252,0,0,
		   0,0,252,252,252,252,252,0,
		   0,0,252,252,252,252,252,0,
		   0,0,252,252,252,252,252,0,
		   0,0,252,252,252,252,252,0,
		   0,0,0,252,252,252,0,0
};
u8 r_foodt[64]=
{
		           0,0,0,255,255,255,0,0,
				   0,0,0,0,255,0,0,0,
				   0,0,0,240,240,240,0,0,
				   0,0,240,240,240,240,240,0,
				   0,0,240,240,240,240,240,0,
				   0,0,240,240,240,240,240,0,
				   0,0,240,240,240,240,240,0,
				   0,0,0,240,240,240,0,0
};
void display_score(void)
{
	u8 a,b,c;
   if ((score>0)&&(score<10))
   {
	   a=score;
	   BG_MAP_RAM_SUB(map_index)[32*6+16]=a;
   }
   if ((score>=10)&&(score<100))
     {
  	   a=score/10;
  	   b=score-a*10;
  	   BG_MAP_RAM_SUB(map_index)[32*6+16]=a;
  	 BG_MAP_RAM_SUB(map_index)[32*6+17]=b;
     }
   if ((score>=100)&&(score<1000))
        {
     	   a=score/100;
     	   b=score-a*100;
     	   b=b/10;
     	   c=score-a*100-b*10;
     	   BG_MAP_RAM_SUB(map_index)[32*6+16]=a;
     	   BG_MAP_RAM_SUB(map_index)[32*6+17]=b;
     	  BG_MAP_RAM_SUB(map_index)[32*6+18]=b;
        }
}
void display_score2(void)
{
	u8 a,b,c;
   if ((score2>0)&&(score2<10))
   {
	   a=score2;
	   BG_MAP_RAM_SUB(map_index)[32*9+16]=a;
   }
   if ((score>=10)&&(score<100))
     {
  	   a=score2/10;
  	   b=score2-a*10;
  	   BG_MAP_RAM_SUB(map_index)[32*9+16]=a;
  	 BG_MAP_RAM_SUB(map_index)[32*9+17]=b;
     }
   if ((score>=100)&&(score<1000))
        {
     	   a=score2/100;
     	   b=score2-a*100;
     	   b=b/10;
     	   c=score2-a*100-b*10;
     	   BG_MAP_RAM_SUB(map_index)[32*9+16]=a;
     	   BG_MAP_RAM_SUB(map_index)[32*9+17]=b;
     	  BG_MAP_RAM_SUB(map_index)[32*9+18]=b;
        }
}
void display_h_score(void)
{
	u8 a,b,c;
   if ((h_score>0)&&(h_score<10))
   {
	   a=h_score;
	   BG_MAP_RAM_SUB(map_index)[32*15+16]=a;
   }
   if ((h_score>=10)&&(h_score<100))
     {
  	   a=h_score/10;
  	   b=h_score-a*10;
  	   BG_MAP_RAM_SUB(map_index)[32*15+16]=a;
  	 BG_MAP_RAM_SUB(map_index)[32*15+17]=b;
     }
   if ((score>=100)&&(score<1000))
        {
     	   a=h_score/100;
     	   b=h_score-a*100;
     	   b=b/10;
     	   c=h_score-a*100-b*10;
     	   BG_MAP_RAM_SUB(map_index)[32*15+16]=a;
     	   BG_MAP_RAM_SUB(map_index)[32*15+17]=b;
     	  BG_MAP_RAM_SUB(map_index)[32*15+18]=b;
        }
}
void initialise_memory(void)
{
	    BG_PALETTE[255]=ARGB16(1,0,31,20);
		BG_PALETTE[253]=ARGB16(1,31,0,0);
		BG_PALETTE[252]=ARGB16(1,0,0,31);
		BG_PALETTE_SUB[3]=ARGB16(1,0,50,0);
	    swiCopy(tile_obstacle,BG_TILE_RAM(tile_index),32);
	    swiCopy(tile_transparent,BG_TILE_RAM(tile_index)+32,32);
	    swiCopy(tile_food,BG_TILE_RAM(tile_index)+96,32);
	    swiCopy(snake_head_right,BG_TILE_RAM(tile_index)+128,32);
	    swiCopy(snake_head_up,BG_TILE_RAM(tile_index)+160,32);
	    swiCopy(s_foodt,BG_TILE_RAM(tile_index)+192,32);
	    swiCopy(r_foodt,BG_TILE_RAM(tile_index)+224,32);
	    swiCopy(snake2_head_up,BG_TILE_RAM(tile_index)+256,32);
	    swiCopy(snake2_head_right,BG_TILE_RAM(tile_index)+288,32);
	    swiCopy(snakBitmap,BG_MAP_RAM(0),snakBitmapLen/2);
	    swiCopy(snakPal,BG_PALETTE,snakPalLen/2);
	    // SUB
	    swiCopy(BGBitmap,BG_BMP_RAM_SUB(0),BGBitmapLen/2);
	    swiCopy(BGPal,BG_PALETTE_SUB,BGPalLen/2);
	    swiCopy(tile_zero,BG_TILE_RAM_SUB(tile_index),32);
	    swiCopy(tile_one,BG_TILE_RAM_SUB(tile_index)+32,32);
	    swiCopy(tile_two,BG_TILE_RAM_SUB(tile_index)+64,32);
	    swiCopy(tile_three,BG_TILE_RAM_SUB(tile_index)+96,32);
	    swiCopy(tile_four,BG_TILE_RAM_SUB(tile_index)+128,32);
	    swiCopy(tile_five,BG_TILE_RAM_SUB(tile_index)+160,32);
	    swiCopy(tile_six,BG_TILE_RAM_SUB(tile_index)+192,32);
	    swiCopy(tile_seven,BG_TILE_RAM_SUB(tile_index)+224,32);
	    swiCopy(tile_eight,BG_TILE_RAM_SUB(tile_index)+256,32);
	    swiCopy(tile_nine,BG_TILE_RAM_SUB(tile_index)+288,32);
	    swiCopy(tile_transparent,BG_TILE_RAM_SUB(tile_index)+320,32);
	    //swiCopy(snake_head_right,BG_TILE_RAM(tile_index)+352,32);


}
void display_welcome_screen(void)
{
	 int i,j;
	    for(i=0;i<24;i++)
	    {
	    	for(j=0;j<32;j++)
	    	{
	    		BG_MAP_RAM(map_index)[32*i+j]=1;
	    		BG_MAP_RAM_SUB(map_index)[32*i+j]=10;
	    	}
	    }
	swiCopy(SWSCREENBitmap,BG_MAP_RAM(0),SWSCREENBitmapLen/2);
	swiCopy(SWSCREENPal,BG_PALETTE,SWSCREENPalLen/2);
		    // SUB
	BG_PALETTE_SUB[254]=ARGB16(1,31,31,0);
			BG_PALETTE_SUB[253]=ARGB16(1,31,31,0);
	swiCopy(SWSUBBitmap,BG_BMP_RAM_SUB(0),SWSUBBitmapLen/2);
	swiCopy(SWSUBPal,BG_PALETTE_SUB,SWSUBPalLen/2);
	swiCopy(snake_head_right,BG_TILE_RAM_SUB(tile_index)+352,32);
    if(ini_arrow==1)
    {
    	BG_MAP_RAM_SUB(map_index)[32*6+5]=11;
    }
    if(ini_arrow==0)
    {
    	BG_MAP_RAM_SUB(map_index)[32*11+5]=11;
    }
}
void display_tutorial_screen(void)
{
	 int i,j;
	    for(i=0;i<24;i++)
	    {
	    	for(j=0;j<32;j++)
	    	{
	    		BG_MAP_RAM(map_index)[32*i+j]=1;
	    		BG_MAP_RAM_SUB(map_index)[32*i+j]=10;
	    	}
	    }
	swiCopy(STUTBitmap,BG_MAP_RAM(0),STUTBitmapLen/2);
	swiCopy(STUTPal,BG_PALETTE,STUTPalLen/2);
	BG_PALETTE_SUB[254]=ARGB16(1,25,10,10);
			BG_PALETTE_SUB[253]=ARGB16(1,25,10,10);
	swiCopy(snake_head_right,BG_TILE_RAM_SUB(tile_index)+352,32);
	if(ini_arrow==1)
	    {
	    	BG_MAP_RAM_SUB(map_index)[32*4+5]=11;
	    }
	    if(ini_arrow==0)
	    {
	    	BG_MAP_RAM_SUB(map_index)[32*11+5]=11;
	    }
}
void initialise_map(int a)
{


    int i,j;
    for(i=0;i<24;i++)
    {
    	for(j=0;j<32;j++)
    	{
    		BG_MAP_RAM(map_index)[32*i+j]=1;
    		BG_MAP_RAM_SUB(map_index)[32*i+j]=10;
    	}
    }
    if(a==0)
    {
    for(i=0;i<24;i++)
    {
    	BG_MAP_RAM(map_index)[32*i]=0;
    	BG_MAP_RAM(map_index)[32*i+31]=0;
    }
    for(j=0;j<32;j++)
    {
    	BG_MAP_RAM(map_index)[j]=0;
    	BG_MAP_RAM(map_index)[32*23+j]=0;
    }
    BG_MAP_RAM(map_index)[15]=1;
    BG_MAP_RAM(map_index)[16]=1;
    BG_MAP_RAM(map_index)[17]=1;
    BG_MAP_RAM(map_index)[32*23+15]=1;
    BG_MAP_RAM(map_index)[32*23+16]=1;
    BG_MAP_RAM(map_index)[32*23+17]=1;
    BG_MAP_RAM(map_index)[32*11]=1;
    BG_MAP_RAM(map_index)[32*12]=1;
    BG_MAP_RAM(map_index)[32*13]=1;
    BG_MAP_RAM(map_index)[32*11+31]=1;
    BG_MAP_RAM(map_index)[32*12+31]=1;
    BG_MAP_RAM(map_index)[32*13+31]=1;
     }
    if(a==1)
    {
    	for(i=0;i<24;i=i+4)
    	    {
    	    	BG_MAP_RAM(map_index)[32*i]=0;
    	    	BG_MAP_RAM(map_index)[32*i+31]=0;
    	    }
    	    for(j=0;j<32;j=j+4)
    	    {
    	    	BG_MAP_RAM(map_index)[j]=0;
    	    	BG_MAP_RAM(map_index)[32*23+j]=0;
    	    }
    	    for(i=4;i<20;i++)
    	    {
    	    	BG_MAP_RAM(map_index)[32*i+8]=0;
    	    	BG_MAP_RAM(map_index)[32*i+22]=0;
    	    }

    }
    if(a==2)
    {
    	       for(i=0;i<24;i=i+4)
    	    	    {
    	    	    	BG_MAP_RAM(map_index)[32*i]=0;
    	    	    	BG_MAP_RAM(map_index)[32*i+31]=0;
    	    	    }
    	    	    for(j=0;j<32;j=j+4)
    	    	    {
    	    	    	BG_MAP_RAM(map_index)[j]=0;
    	    	    	BG_MAP_RAM(map_index)[32*23+j]=0;
    	    	    }
    	    	    for(i=4;i<16;i=i+3)
    	    	    {
    	    	    	BG_MAP_RAM(map_index)[32*i+4]=0;
    	    	    	BG_MAP_RAM(map_index)[32*16+13+i]=0;
    	    	    }
    }
    if(a==3)
    {
        	       for(i=0;i<24;i=i+1)
        	    	    {
        	    	    	BG_MAP_RAM(map_index)[32*i]=0;
        	    	    	BG_MAP_RAM(map_index)[32*i+31]=0;
        	    	    }
        	    	    for(j=0;j<32;j=j+1)
        	    	    {
        	    	    	BG_MAP_RAM(map_index)[j]=0;
        	    	    	BG_MAP_RAM(map_index)[32*23+j]=0;
        	    	    }
        	    	    for(i=1;i<18;i=i+1)
        	    	    {
        	    	    	BG_MAP_RAM(map_index)[32*i+14]=0;
        	    	    	BG_MAP_RAM(map_index)[32*20+11+i]=0;
        	    	    }
        }
}



void draw_snake(void)
{
   swiCopy(snake_tile,BG_TILE_RAM(tile_index)+64,32);
   BG_PALETTE[254]=ARGB16(1,31,31,0);
   int i;
   for(i=1;i<length;i++)
   {
	   if((snak[i].y>=0)&&(snak[i].y<192)&&(snak[i].x>=0)&&(snak[i].x<252))
	   BG_MAP_RAM(map_index)[(32*(snak[i].y))+snak[i].x]=2;
   }
   if(snak[0].dir==DUP)
	   BG_MAP_RAM(map_index)[32*(snak[0].y)+snak[0].x]=5;
   if(snak[0].dir==DDOWN)
	   BG_MAP_RAM(map_index)[32*(snak[0].y)+snak[0].x]=5 | (1<<11);
   if(snak[0].dir==DRIGHT)
	   BG_MAP_RAM(map_index)[32*(snak[0].y)+snak[0].x]=4;
   if(snak[0].dir==DLEFT)
	   BG_MAP_RAM(map_index)[32*(snak[0].y)+snak[0].x]=4 | (1<<10);
}
void redraw_snake(void)
{
	if(snak[0].state==7)
	{
		recolor_tile_snake(25,10,9);
		//printf("snake tile %d  state 7 \n",snake_tile[5]);
	}
	if(snak[0].state==1)
	{
		recolor_tile_snake2();
		//printf("snake tile %d  state 1 \n ",snake_tile[5]);
	}
	int i;
	   for(i=1;i<length;i++)
	   {
		   BG_MAP_RAM(map_index)[(32*(snak[i].y))+snak[i].x]=2;
	   }
	   if(snak[0].dir==DUP)
	   	   BG_MAP_RAM(map_index)[32*(snak[0].y)+snak[0].x]=5;
	      if(snak[0].dir==DDOWN)
	   	   BG_MAP_RAM(map_index)[32*(snak[0].y)+snak[0].x]=5 | (1<<11);
	      if(snak[0].dir==DRIGHT)
	   	   BG_MAP_RAM(map_index)[32*(snak[0].y)+snak[0].x]=4;
	      if(snak[0].dir==DLEFT)
	   	   BG_MAP_RAM(map_index)[32*(snak[0].y)+snak[0].x]=4 | (1<<10);


}
void redraw_snake2(void)
{
	if(snak2[0].state==7)
	{
		recolor_tile_snake(25,10,9);
		//printf("snake tile %d  state 7 \n",snake_tile[5]);
	}
	if(snak2[0].state==1)
	{
		recolor_tile_snake2();
		//printf("snake tile %d  state 1 \n ",snake_tile[5]);
	}
	int i;
	   for(i=1;i<length2;i++)
	   {
		   if((snak2[i].y>=0)&&(snak2[i].y<192)&&(snak2[i].x>=0)&&(snak2[i].x<252))
		   BG_MAP_RAM(map_index)[(32*(snak2[i].y))+snak2[i].x]=2;
	   }
	   if(snak2[0].dir==DUP)
	   	   BG_MAP_RAM(map_index)[32*(snak2[0].y)+snak2[0].x]=8;
	      if(snak2[0].dir==DDOWN)
	   	   BG_MAP_RAM(map_index)[32*(snak2[0].y)+snak2[0].x]=8 | (1<<11);
	      if(snak2[0].dir==DRIGHT)
	   	   BG_MAP_RAM(map_index)[32*(snak2[0].y)+snak2[0].x]=9;
	      if(snak2[0].dir==DLEFT)
	   	   BG_MAP_RAM(map_index)[32*(snak2[0].y)+snak2[0].x]=9 | (1<<10);


}
int return_tile_index(int x, int y)
{
	u8 val;
	val=BG_MAP_RAM(map_index)[32*y+x];
	return val;
}
void draw_food(void)
{
	BG_MAP_RAM(map_index)[32*(food.y)+food.x]=3;
}
void draw_s_food(void)
{
	BG_MAP_RAM(map_index)[32*(s_food.y)+s_food.x]=6;
}
void draw_r_food(void)
{
	BG_MAP_RAM(map_index)[32*(r_food.y)+r_food.x]=7;
}
/*void recolor_tile_snake1(void)
{
  int i;
  for(i=0;i<64;i++)
  {
	  snake_tile[i]=251;
	  if(snake_head_up[i]==254)
	  {
		  snake_head_up[i]=251;
	  }
	  if(snake_head_right[i]==254)
	  	  {
	  		  snake_head_right[i]=251;
	  	  }
  }
        swiCopy(snake_tile,BG_TILE_RAM(tile_index)+64,32);
        swiCopy(snake_head_right,BG_TILE_RAM(tile_index)+128,32);
  	    swiCopy(snake_head_up,BG_TILE_RAM(tile_index)+160,32);
}*/
void recolor_tile_snake2(void)
{
	int i;
	  for(i=0;i<64;i++)
	  {
		  snake_tile[i]=254;
		  if(snake_head_up[i]==251)
		  {
			  snake_head_up[i]=254;
		  }
		  if(snake_head_right[i]==251)
		  	  {
		  		  snake_head_right[i]=254;
		  	  }
	  }
	        swiCopy(snake_tile,BG_TILE_RAM(tile_index)+64,32);
	        swiCopy(snake_head_right,BG_TILE_RAM(tile_index)+128,32);
	  	    swiCopy(snake_head_up,BG_TILE_RAM(tile_index)+160,32);
}
void recolor_tile_snake(int a, int b ,int c)
{
	BG_PALETTE[251]=ARGB16(1,a,b,c);
	int i;
	  for(i=0;i<64;i++)
	  {
		  snake_tile[i]=251;
		  if(snake_head_up[i]==254)
		  {
			  snake_head_up[i]=251;
		  }
		  if(snake_head_right[i]==254)
		  	  {
		  		  snake_head_right[i]=251;
		  	  }
	  }
	        swiCopy(snake_tile,BG_TILE_RAM(tile_index)+64,32);
	        swiCopy(snake_head_right,BG_TILE_RAM(tile_index)+128,32);
	  	    swiCopy(snake_head_up,BG_TILE_RAM(tile_index)+160,32);

}
// draw
