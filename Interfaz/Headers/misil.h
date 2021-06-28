//
// Created by falei on 27/6/2021.
//

#ifndef INTERFAZ_MISIL_H
#define INTERFAZ_MISIL_H


#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "enemigo.h"
#include "muro.h"
#include "constantes.h"

typedef struct Misil Misil; /** Estructura que contiene las caracteristicas del misil del jugador */
/**
 * Funcion que actualiza la posicion de cada disparo
 * @param misil el misil creado
 * @param enemigo el puntero al primer enemigo
 * @param muro puntero al primer muro
 */
void MisilAvanza(Misil *misil, Enemigo *enemigo, Muro *muro);
/**
 * Borra un misil si este se sale de los limites de la pantalla
 * @param misiles recibe el puntero al primer misil para recorrer todos y actualizar su estado
 */
void borrar_misil(Misil *misiles);
/**
 * Funcion que detecta colisiones entre balas del jugador y el enemigo o el muro
 * @param misil puntero al primer misil
 * @param enemigo puntero al primer enemigo
 * @param muro puntero al primer muro
 */
void collision(Misil *misil, Enemigo *enemigo, Muro *muro);

struct Misil{
    int x1,y1;
    int x2, y2;
    int vel_x, vel_y;
    Misil *siguiente;
    bool flag;
};

#endif //INTERFAZ_MISIL_H
