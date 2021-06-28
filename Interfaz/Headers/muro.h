//
// Created by falei on 27/6/2021.
//

#ifndef INTERFAZ_MURO_H
#define INTERFAZ_MURO_H


#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../socket.h"



#define MURO_WIDTH 90
#define MURO_HEIGHT 50

typedef struct Muro Muro;

struct Muro{
    int x1, y1;
    int colisiones;
    char path[60];
    Muro *siguiente;
    bool destruido;
};
void pintarMuro(SDL_Renderer *gRenderer,SDL_Texture *myTexture, Muro *muro);
void crearMuros(Muro *muro);
void colisionMuro(Muro *muro);


#endif //INTERFAZ_MURO_H
