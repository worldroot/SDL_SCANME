prog:game.o main.o 
	gcc game.o main.o -lSDL -lSDL_image -lSDL_mixer -o jeux
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer
game.o:game.c
	gcc -c game.c -lSDL -lSDL_image -lSDL_mixer