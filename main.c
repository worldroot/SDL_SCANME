#include <stdlib.h>

#include <stdio.h>

#include <SDL/SDL.h>

#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include"main.h"


 

int main()

{
    int n;
   int x,y;
   n=1;

    if (n==1)
        x=menu1(&n);
 if (n==2)
      x=menu2(&n);

   
    
  
       
    
    
 return 0;
}
