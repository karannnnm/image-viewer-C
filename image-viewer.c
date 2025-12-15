#include "SDL3/SDL_audio.h"
#include "SDL3/SDL_error.h"
#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_surface.h"
#include "SDL3/SDL_video.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>
#include <string.h>


int color[4] = {0xFFFF000F, 0XFF00FF00,0xFF00FFFF, 0x000000FF};

int main(){
    SDL_Init(SDL_INIT_AUDIO);
    printf("Hello!\n");

    /*
        creating window and a surface on it.
    */
    SDL_Window *pwindow = SDL_CreateWindow("window", 900,900,0);
    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
    
    
    /*
        creating audio specs, an audio device, a stream and binding them.
    */
    struct SDL_AudioSpec src_spec = {SDL_AUDIO_S32LE,2,1000};
    SDL_AudioSpec *psrc_spec = &src_spec; 
    struct SDL_AudioSpec dest_spec = {SDL_AUDIO_S32LE,2,1000};
    SDL_AudioSpec *pdest_spec = &dest_spec; 
    
    //create the stream
    SDL_AudioStream *pstream = SDL_CreateAudioStream(psrc_spec, pdest_spec);
    //create the audio device
    SDL_AudioDeviceID audio_device = SDL_OpenAudioDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);

    bool isStreamBinded =  SDL_BindAudioStream(audio_device, pstream);
    
    
    // int n = sizeof(color)/sizeof(color[0]);
    // int currentColorIndex = 0;

    // //init the event
    // bool isquit = false;
    // SDL_Event event;
    // //event loop
    // while (!isquit) {
    //     //poll the event
    //     if (SDL_PollEvent( & event)) {
    //         if (event.type == SDL_EVENT_QUIT) {
    //             isquit = true;
    //         }
    //     }
        

    //     SDL_FillSurfaceRect(psurface, NULL, color[currentColorIndex]);
    //     SDL_UpdateWindowSurface(pwindow);
        
    //     currentColorIndex = (currentColorIndex + 1) % n;
        
    //     SDL_Delay(100);
    // }
    //destroy the window
    SDL_DestroyWindow(pwindow);
    SDL_Quit();
    return 0;
    


}
