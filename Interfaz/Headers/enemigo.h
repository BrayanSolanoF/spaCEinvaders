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
#include <windows.h>
#include "constantes.h"




typedef struct Enemigo Enemigo; /** Estructura que contiene caracteristicas referentes a los enemigos*/
typedef struct MisilEnemigo MisilEnemigo; /** Estructura que contiene característticas referentes a los misiles*/

/**
 * Funcion que se encarga de pintar los enemigos a cada instante de la actualizacion de la pantalla de juego
 * @param enemigo es el puntero al primer enemigo creado del cual parten ttodos los demás
 * @param gRenderer es el renderer de la librería SDL donde se deben dibujar los enemigos
 */
void pintar_Enemigos(Enemigo *enemigo, SDL_Renderer *gRenderer);

/**
 * Funcion que se encarga de actualizar automaticamente la posicion de los enemigos a cada instante
 * @param enemigo el puntero al primer enemigo creado de donde se parte el recorrido
 */
void movimiento_Enemigo(Enemigo *enemigo);

/**
 * Funcion que se llama una sola vez y se encarga de crear todos los objetos enemigo del juego
 * @param enemigo es el primer puntero creado desde el main y del cual se parte para crear todos
 * los demas.
 */
void crear_enemigos(Enemigo *enemigo);

/**
 *Funcion que se encarga de crear los misiles para los enemigos y solo se crea uno para cada enemigo
 * @param enemigo primer puntero a enemigo
 */
void crearMisilEnemigo(Enemigo *enemigo);

/**
 * Funcion que realiza el recorrido del misil del enemigo mientras este se encuentra activo
 * @param misilE el puntero al misil del enemigo
 */
void misilActivo(MisilEnemigo *misilE);

/**
 * Funcion que detecta si el misil del enemigo colisiona o se sale de la pantalla para eliminar al puntero
 * y hacer que el misil este inactivo nuevamente para el disparo de otro enemigo
 * @param misilE el misil correspondiente
 * @param enemigo el enemigo del misil correspondiente
 */
void colisionMisilE(MisilEnemigo *misilE, Enemigo *enemigo );

/**
 * Funcion que es llamada para que realice el movimiento del misil automáticamente revisando
 * constantemente si hay colisiones
 * @param enemigo el puntero al primer enemigo
 */
void movimiento_Misil(Enemigo *enemigo);
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
    bool colisionMuroFlag;
};

#endif //INTERFAZ_ENEMIGO_H
