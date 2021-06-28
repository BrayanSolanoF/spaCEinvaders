//
// Created by falei on 27/6/2021.
//

#include "../Headers/misil.h"


void MisilAvanza(Misil *misil, Enemigo *enemigo, Muro *muro){
    misil->x1 += misil->vel_x;
    misil->y1 += misil->vel_y;
    misil->x2 += misil->vel_x;
    misil->y2 += misil->vel_y;
    collision(misil,enemigo,muro);
}

void borrar_misil(Misil *misiles){
    Misil *ixMisil= misiles;
    if(ixMisil == NULL)
        return;
    Misil *auxMisil;
    while(ixMisil->siguiente != NULL){
        if(ixMisil->siguiente->y1 < 0){
            auxMisil= ixMisil->siguiente->siguiente;
            SDL_free(ixMisil->siguiente);
            ixMisil->siguiente=auxMisil;
        }else{
            ixMisil=ixMisil->siguiente;
        }
    }
}

void collision(Misil *misil, Enemigo *enemigo, Muro *muro){
    Enemigo *enemigoAux= enemigo;
    Muro *muroAux= muro;
    while(enemigoAux!=NULL){
        // Si colisionan
        if((misil->x2 > enemigoAux->x1) &&(misil->x2 < (enemigoAux->x1+ENEMIGO_WIDTH)) &&
           (misil->y2 < enemigoAux->y1+ENEMIGO_HEIGHT)&&(misil->y2 > enemigoAux->y1) &&
           misil->flag==false && enemigoAux->flag==true)
        {
            enemigoAux->flag = false;

            misil->flag=true;
        }
        enemigoAux= enemigoAux->siguiente;
    }
    while (muroAux!=NULL){
        if((misil->x2 > muroAux->x1) && (misil->x2 < (muroAux->x1+MURO_WIDTH)) &&
           (misil->y2 < muroAux->y1+MURO_HEIGHT)&&(misil->y2 > muroAux->y1) &&
           misil->flag==false && muroAux->destruido == false){
            misil->flag=true;
            colisionMuro(muroAux);
        }
        muroAux= muroAux->siguiente;
    }
}
