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
#include "constantes.h"

typedef struct Muro Muro; /** Estructura que contiene caracteristicas de los muros o escudos que protegen al jugador*/

struct Muro{
    int x1, y1;
    int colisiones;
    char path[60];
    Muro *siguiente;
    bool destruido;
};
/**
 * Pinta los muros en pantalla
 * @param gRenderer renderizador del juego sobre el que se pinta en pantalla
 * @param myTexture textura que se pinta en el gRenderer y contiene imagen
 * @param muro puntero al primer muro
 */
void pintarMuro(SDL_Renderer *gRenderer,SDL_Texture *myTexture, Muro *muro);
/**
 * Funcion que se llama una sola vez en el main y crea los muros del juego
 * @param muro el puntero al primer muro creado en el main
 */
void crearMuros(Muro *muro);
/**
 * Llamado si hay una colision y destruye el muro si las colisiones del muro llegan a su maximo de 30
 * @param muro puntero al muro correspondiente
 */
void colisionMuro(Muro *muro);


#endif //INTERFAZ_MURO_H
