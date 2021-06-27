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

#define MISIL_LEN 5
#define MISIL_VEL 10

typedef struct Misil Misil;

void MisilAvanza(Misil *misil, Enemigo *enemigo, Muro *muro);
void borrar_misil(Misil *misiles);
void collision(Misil *misil, Enemigo *enemigo, Muro *muro);

struct Misil{
    int x1,y1;
    int x2, y2;
    int vel_x, vel_y;
    Misil *siguiente;
    bool flag;
};

#endif //INTERFAZ_MISIL_H
