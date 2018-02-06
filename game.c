#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include"main.h"





int menu1 (int *n)
{
 int continuer=1;
    int x=0;
    int y;
    int test=0;
    TTF_Font *police = NULL;
     SDL_Color couleurNoire = {0, 0, 0};

    SDL_Surface *ecran = NULL, *texte=NULL, *imageDeFond = NULL, *Play_before = NULL, *Play_after =NULL, *Quit_before = NULL, *Quit_after = NULL, *Settings_before = NULL, *Settings_after = NULL;
    SDL_Event event;
    SDL_Rect positionFond, positiontexte, positionPlay_before, positionPlay_after, positionQuit_before, positionQuit_after, positionSettings_before, positionSettings_after;
 

  TTF_Init();
     if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer

   {

      printf("%s", Mix_GetError());

   }    
   //position texte
   positiontexte.x=0;
   positiontexte.y=0;
//position fond
    positionFond.x = 0;
    positionFond.y = 0;
//position play_before
    positionPlay_before.x = 303;
    positionPlay_before.y = 202;
//position play_after
    positionPlay_after.x = 304;
    positionPlay_after.y = 203;
//position quit_before
    positionQuit_before.x = 500;
    positionQuit_before.y = 202;
//position quit_after
    positionQuit_after.x = 501;
    positionQuit_after.y = 203;
//position settings_before
    positionSettings_before.x = 106;
    positionSettings_before.y = 202;
//position settings_after
    positionSettings_after.x = 107;
    positionSettings_after.y = 203;
    //doublebuf pour fluidite du mouvement + hwsurface utilisation de la carte graphique
    SDL_Init(SDL_INIT_VIDEO | SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);

  SDL_WM_SetCaption("SDL_Mixer", NULL);
 Mix_Music *musique; //Création du pointeur de type Mix_Music
  musique = Mix_LoadMUS("musique.mp3"); //Chargement de la musique
  Mix_PlayMusic(musique, -1);

/* Chargement de la police */
    police = TTF_OpenFont("caviar_dreams/CaviarDreams.ttf", 15);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
   texte = TTF_RenderText_Blended(police, "ESC to quit", couleurNoire);  

    // image de l'icone
    SDL_WM_SetIcon(IMG_Load("sdl_icone.bmp"), NULL);
    //*****************
    // video settings
    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
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
    Play_before = IMG_Load("images/play1 (before).png");
 
    //chargement du bouton play_after
     Play_after = IMG_Load("images/play1 (after).png");
     SDL_BlitSurface(Play_after, NULL, ecran, &positionPlay_after);

    //**********************************
    //chargement du bouton quit_before
    Quit_before = IMG_Load("images/QUIT(before).png");
    SDL_BlitSurface(Quit_before, NULL, ecran ,&positionQuit_before);
    //chargement du bouton quit_after
    Quit_after = IMG_Load("images/QUIT(after).png");

    //**********************************
    //chargement du bouton settings_before
    Settings_before = IMG_Load("images/settings1(before).png");
    SDL_BlitSurface(Settings_before, NULL, ecran, &positionSettings_before);
    //chargement du bouton settings_after
    Settings_after = IMG_Load("images/settings1(after).png");
    //***********************************
   



  SDL_BlitSurface(texte, NULL, ecran, &positiontexte); /* Blit du texte */

   
   while (continuer)
   {
    SDL_WaitEvent(&event);

        switch(event.type)
        {
            case SDL_KEYDOWN:
             switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    continuer = 0;
                    break;
                    // mouv clavier
                         case SDLK_RIGHT:
                         if (x==1)
                           x=4;
                         if (x==2)
                           x=3;
                         else
                          x=1;
                        break;
                        case SDLK_LEFT:
                         if (x==2)
                           x=4;
                         if (x==1)
                          x=3;
                          else  
                          x=2;
                        break;
                         case SDLK_RETURN:
                            if (x==3 || x==0)
                            {
                                 *n = 2;
                                 test=1;
                                 break;
                            }
                             break;
                }
                break;
                  case SDL_MOUSEMOTION:
                  //bouton play
                            if((event.motion.x >=400) &&(event.motion.x<430) && (event.motion.y>=300) &&(event.motion.y <= 315))
                            {
                                x=3;
                            }                            
                            
                //bouton settings
                            if((event.motion.x >=200) &&(event.motion.x<230) && (event.motion.y>=300) &&(event.motion.y <= 315))
                            {
                                x=2;
                            }   
                            if((event.motion.x >=500) &&(event.motion.x<530) && (event.motion.y>=300) &&(event.motion.y <= 315))
                            {
                                x=1;
                            }                             
                            break;

            
        }
        if (x==1){
SDL_BlitSurface(Play_before, NULL, ecran, &positionPlay_before);
SDL_BlitSurface(Quit_after, NULL, ecran, &positionQuit_after);
SDL_Flip(ecran);}

if (x==2){
SDL_BlitSurface(Play_before, NULL, ecran, &positionPlay_before);
SDL_BlitSurface(Settings_after, NULL, ecran, &positionSettings_after);
SDL_Flip(ecran);}

if (x==3){
SDL_BlitSurface(Settings_before, NULL, ecran, &positionSettings_before);
SDL_BlitSurface(Quit_before, NULL, ecran, &positionQuit_before);
SDL_BlitSurface(Play_after, NULL, ecran, &positionPlay_after);
SDL_Flip(ecran);}
if(test==1){break;}


}
   
    SDL_Flip(ecran);   
    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(Play_before);
     SDL_FreeSurface(Play_after);
    SDL_FreeSurface(Quit_before);
    SDL_FreeSurface(Quit_after);

    SDL_FreeSurface(Settings_before);
     SDL_FreeSurface(Settings_after);
      Mix_FreeMusic(musique); //Libération de la musique
    Mix_CloseAudio(); //Fermeture de l'API
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(texte);
    SDL_Quit();

 

    return EXIT_SUCCESS;
}

















int menu2 (int *n)
{

    int continuer=1;
    int x=0;
    int y;
    
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *Play_before = NULL, *Play_after =NULL;
    SDL_Event event;
    SDL_Rect positionFond, positionPlay_before, positionPlay_after;
 
//position fond
    positionFond.x = 0;
    positionFond.y = 0;
//position play_before
    positionPlay_before.x = 303;
    positionPlay_before.y = 202;
//position play_after
    positionPlay_after.x = 303;
    positionPlay_after.y = 0;

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
    Play_before = IMG_Load("images/play1 (before).png");
 
    //chargement du bouton play_after
     Play_after = IMG_Load("images/play1 (after).png");
     SDL_BlitSurface(Play_after, NULL, ecran, &positionPlay_after);
     //chargement du bouton back_before


    

 while (continuer)
   {
    SDL_WaitEvent(&event);

        switch(event.type)
        {
            case SDL_KEYDOWN:
             switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    continuer = 0;
                    break;
                    // mouv clavier
                         case SDLK_RIGHT:
                         if (x==1)
                           x=4;
                         if (x==2)
                           x=3;
                         else
                          x=1;
                        break;
                        case SDLK_LEFT:
                         if (x==2)
                           x=4;
                         if (x==1)
                          x=3;
                          else  
                          x=2;
                        break;
                         case SDLK_RETURN:
                            if (x==1)
                            *n = 2;
                            if (x==2)
                            *n=2;
                             break; 
                        
                       
                    // chargement menu autre
                    
                   
                }
            break;
        }
        if (x==1){
SDL_BlitSurface(Play_before, NULL, ecran, &positionPlay_before);

SDL_Flip(ecran);}

if (x==2){
SDL_BlitSurface(Play_before, NULL, ecran, &positionPlay_before);

SDL_Flip(ecran);}

if (x==3){

SDL_BlitSurface(Play_after, NULL, ecran, &positionPlay_after);
SDL_Flip(ecran);}


}

    

    

   SDL_Flip(ecran);   
    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(Play_before);
     SDL_FreeSurface(Play_after);

    SDL_Quit();

 

    return EXIT_SUCCESS;

}