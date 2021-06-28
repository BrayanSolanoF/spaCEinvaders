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
#include "constantes.h"

typedef struct Nave Nave; /** Estructura que contiene las características de la nave*/
struct Nave{
    int x1, y1;
    int vel_x, vel_y;
    Misil *misiles;
    char path[60];
    int vidas;
    int puntos;
};
/**
 * Funcion que pinta la nave en pantalla en cada movimiento
 * @param nave la nave jugadora creada desde el main
 * @param targetRect el rectángulo de la librería SDL sobre el que se pinta la nave
 * @param bmpTexture la textura donde se debe pintar la nave
 * @param gRenderer el renderizador para plasmar la nave en la pantalla de juego
 * @param enemigo el puntero al primer enemigo
 * @param muro el puntero al primer muro creado
 */
void pintar_Nave(Nave *nave, SDL_Rect targetRect, SDL_Texture *bmpTexture, SDL_Renderer *gRenderer, Enemigo *enemigo, Muro *muro);

/**
 * Realiza el movimiento hacia los lados de la nave jugadora
 */
void avanza_horizontal();
/**
 * Realiza el movimiento hacia arriba o abajo de la nave jugadora
 */
void avanza_vertical();
/**
 * Activa misiles
 */
void disparar();
/**
 * Detecta se hay colisiones entre las balas de los enemigos y el jugador y resta vidas
 * @param nave es el puntero a la nave jugadora
 * @param enemigo es el puntero al primer enemigo
 */
void colisionConEnemigo(Nave *nave, Enemigo *enemigo);
/**
 * Detecta colisiones entre las balas de los enemigos y los muros para bajar nivel del muro
 * @param enemigo puntero al enemigo que se esta analizando
 * @param muro puntero al primer muro
 */
void colisionConMuro(Enemigo *enemigo, Muro *muro);




#endif //INTERFAZ_JUGADOR_H
