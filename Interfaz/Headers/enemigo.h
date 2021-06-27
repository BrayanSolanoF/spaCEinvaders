//
// Created by falei on 27/6/2021.
//

#ifndef INTERFAZ_ENEMIGO_H
#define INTERFAZ_ENEMIGO_H


#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"
#include <windows.h>


#define ENEMIGO_WIDTH 30
#define ENEMIGO_HEIGHT 30
#define ENEMIGO_VEL 3


typedef struct Enemigo Enemigo;
typedef struct MisilEnemigo MisilEnemigo;

void pintar_Enemigos(Enemigo *enemigo, SDL_Renderer *gRenderer);
void movimiento_Enemigo(Enemigo *enemigo);
void crear_enemigos(Enemigo *enemigo);
void crearMisilEnemigo(Enemigo *enemigo);
void misilActivo(MisilEnemigo *misilE);
void colisionMisilE(MisilEnemigo *misilE, Enemigo *enemigo );
int rand_lim(int limit);
struct Enemigo{
    int x1,y1;
    Enemigo *siguiente;
    char path[60];
    SDL_Texture* bmpTexture; //To hold bmp image
    bool flag;
    MisilEnemigo *misil;
};

struct  MisilEnemigo{
    int x1,y1;
    int x2,y2;
    int vel_x, vel_y;
    bool activo;
};

#endif //INTERFAZ_ENEMIGO_H
