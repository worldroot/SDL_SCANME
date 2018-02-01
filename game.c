#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>

#include <SDL/SDL_image.h> 
#include"main.h"
void pause()

{

    int continuer = 1;

    SDL_Event event;

 

    while (continuer)

    {

        SDL_WaitEvent(&event);

        switch(event.type)

        {

            case SDL_QUIT:

                continuer = 0;
                break;

            case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                {
                    // sortie du programme avec touche echape
                    case SDLK_ESCAPE:
                    continuer = 0;
                    break;
                }
                break;
        }



    }

}
