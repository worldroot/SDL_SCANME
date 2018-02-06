prog:game.o main.o 
	gcc game.o main.o -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -o jeux
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
game.o:game.c
	gcc -c game.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf