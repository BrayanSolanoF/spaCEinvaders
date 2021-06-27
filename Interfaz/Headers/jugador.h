//
// Created by falei on 27/6/2021.
//

#ifndef INTERFAZ_JUGADOR_H
#define INTERFAZ_JUGADOR_H


#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "misil.h"
#include "enemigo.h"
#include "muro.h"

#define NAVE_WIDTH 50
#define NAVE_HEIGHT 45
#define NAVE_VEL 10

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

typedef struct Nave Nave;
struct Nave{
    int x1, y1;
    int vel_x, vel_y;
    Misil *misiles;
    char path[60];
};
void pintar_Nave(Nave *nave, SDL_Rect targetRect, SDL_Texture *bmpTexture, SDL_Renderer *gRenderer, Enemigo *enemigo, Muro *muro);
void avanza_horizontal();
void avanza_vertical();
void disparar();





#endif //INTERFAZ_JUGADOR_H
