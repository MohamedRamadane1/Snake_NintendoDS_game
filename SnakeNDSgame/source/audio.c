#include"audio.h"
void init_audio(void)
{
	   mmInitDefaultMem((mm_addr)soundbank_bin);
		mmLoadEffect(SFX_AUD);
		mmLoad(MOD_MUSICBG);
		mmLoad(MOD_WHATIS);
		if(music==1)
	    	mmStart(MOD_MUSICBG, MM_PLAY_LOOP);
		if(music==2)
			mmStart(MOD_WHATIS, MM_PLAY_LOOP);
	    sound.id = SFX_AUD;
		sound.rate    =	(int)(1.0f * (1<<10));	// rate
		sound.handle  = 0;
		sound.volume  = 125;
		sound.panning = 128;
		mmSetModuleVolume(512);
}
