#include "genesis.h"

#include "meshs.h"
#include "res/resources.h"

#include <string.h>

#define MUSIC 64
started = FALSE;

const char intro_text[21] = "Penguin Music Player";

void showText(char s[]){
	VDP_drawText(s, 20 - strlen(s)/2 ,15);
}

void start(){
	VDP_clearTextArea(0,10,40,10);

	started = TRUE;
}

void myJoyHandler( u16 joy, u16 changed, u16 state)
{
	if(state & BUTTON_START){
        if(!started){
            start();
        }
    }
}

int main(u16 hard) {
    JOY_init();
    JOY_setEventHandler( &myJoyHandler );

    showText(intro_text);

    VDP_loadTileSet(bgtile.tileset,1,DMA);
    VDP_setPalette(PAL1, bgtile.palette->data);
    VDP_fillTileMapRect(BG_B,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,1),0,0,40,30);

    XGM_setPCM(MUSIC, music, sizeof(music));
    XGM_startPlayPCM(music,1,SOUND_PCM_CH2);

    while(1)
    {
        // ... code
        VDP_waitVSync();
    }

    return 0;
}