#include <stdlib.h>

#include <stdio.h>

#include <SDL/SDL.h>

#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include"main.h"


 

int main(int argc, char *argv[])

{

    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *Play_before = NULL, *Quit_before = NULL, *Settings_before = NULL;
    SDL_Event event;
    SDL_Rect positionFond, positionPlay_before, positionQuit_before, positionSettings_before;
 
//position fond
    positionFond.x = 0;
    positionFond.y = 0;
//position play_before
    positionPlay_before.x = 303;
    positionPlay_before.y = 202;
//position quit_before
    positionQuit_before.x = 500;
    positionQuit_before.y = 202;
//position settings_before
    positionSettings_before.x = 106;
    positionSettings_before.y = 202;
    //doublebuf pour fluidite du mouvement + hwsurface utilisation de la carte graphique
    SDL_Init(SDL_INIT_VIDEO | SDL_HWSURFACE | SDL_DOUBLEBUF);

 
    // image de l'icone
    SDL_WM_SetIcon(IMG_Load("sdl_icone.bmp"), NULL);
    //*****************
    // video settings
    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE );
    //*****************
    // titre de la fenetre
    SDL_WM_SetCaption("SCANME Game", NULL);
    //*****************
    // chargement de l'image de fond notre menu
    imageDeFond = IMG_Load("images/menu_blanc");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    /* Chargement d'un PNG avec IMG_Load
    Celui-ci est automatiquement rendu transparent car les informations de
    transparence sont codées à l'intérieur du fichier PNG */


    //chargement du bouton play_before
    Play_before = IMG_Load("images/play2.png");
    SDL_BlitSurface(Play_before, NULL, ecran, &positionPlay_before);
    //**********************************
    //chargement du bouton quit_before
    Quit_before = IMG_Load("images/QUIT(before).png");
    SDL_BlitSurface(Quit_before, NULL, ecran ,&positionQuit_before);
    //**********************************
    Settings_before = IMG_Load("images/settings2(before).png");
    SDL_BlitSurface(Settings_before, NULL, ecran, &positionSettings_before);



    SDL_Flip(ecran);

     pause();

 

    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(Play_before);
    SDL_FreeSurface(Quit_before);
    SDL_FreeSurface(Settings_before);
    SDL_Quit();

 

    return EXIT_SUCCESS;

}
