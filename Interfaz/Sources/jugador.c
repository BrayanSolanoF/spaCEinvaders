//
// Created by falei on 27/6/2021.
//

#include "../Headers/jugador.h"

Nave *nave;

void pintar_Nave(Nave *minave, SDL_Rect targetRect,  SDL_Texture *bmpTexture, SDL_Renderer *gRenderer, Enemigo *enemigo, Muro *muro){
    //------------------PINTAR MISILES-----------------
    Misil *ixMisil=minave->misiles;
    nave = minave;
    while(ixMisil!= NULL){
        MisilAvanza(ixMisil, enemigo,muro);

        if(ixMisil->flag== false){
            SDL_RenderDrawLine(gRenderer, ixMisil->x1, ixMisil->y1,ixMisil->x2,
                               ixMisil->y2);
        }

        ixMisil=ixMisil->siguiente;
    }
    Enemigo *enemigoAux=enemigo;
    while(enemigoAux != NULL){
        if(enemigoAux->misil != NULL)
            if(enemigoAux->misil->activo==true){
                //printf("el misil era valido \n");
                //colisionConMuro(enemigoAux, muro);
                colisionConEnemigo(nave,enemigoAux);
            }
        enemigoAux= enemigoAux->siguiente;
    }
    //printf("salio del while \n");
    free(enemigoAux);
    //--------------------------PINTAR NAVE---------------------
    //Define el rectángulo sobre el que se va a pintar el jugador
    targetRect.w = NAVE_WIDTH;
    targetRect.h = NAVE_HEIGHT;
    targetRect.x = minave->x1;
    targetRect.y = minave->y1;
    SDL_RenderCopy(gRenderer, bmpTexture, NULL, &targetRect); //Se pinta la imagen
}

void avanza_horizontal(){
    nave->x1 += nave->vel_x;

}
void avanza_vertical(){
    nave->y1 += nave->vel_y;
}
void disparar(){
    if(nave->misiles ==NULL){
        nave->misiles = (Misil *) SDL_malloc(sizeof (Misil));
        nave->misiles->x1= nave->x1+NAVE_WIDTH/2;
        nave->misiles->y1= nave->y1;
        nave->misiles->x2= nave->x1 +NAVE_WIDTH/2;
        nave->misiles->y2= nave->y1-MISIL_LEN;
        nave->misiles->vel_x=0;
        nave->misiles->vel_y= -MISIL_VEL;
        nave->misiles->flag= false;
        nave->misiles->siguiente= NULL;
    }else{
        Misil *ixMisil= nave->misiles;
        while (ixMisil->siguiente != NULL){
            ixMisil = ixMisil->siguiente;
        }
        ixMisil->siguiente= (Misil *) SDL_malloc(sizeof (Misil));
        ixMisil= ixMisil->siguiente;
        ixMisil->x1= nave->x1+NAVE_WIDTH/2;
        ixMisil->y1=nave->y1;
        ixMisil->x2=nave->x1+NAVE_WIDTH/2;
        ixMisil->y2= nave->y1-MISIL_LEN;
        ixMisil->vel_x=0;
        ixMisil->vel_y=-MISIL_VEL;
        ixMisil->siguiente=NULL;
        ixMisil->flag=false;
    }
}

void colisionConEnemigo(Nave *nave, Enemigo *enemigo){
    //printf("entraaaa \n");
    MisilEnemigo *misilEnemigo= enemigo->misil;

    if((misilEnemigo->y2 > nave->y1) && (misilEnemigo->y2 < (nave->y1+NAVE_HEIGHT/4))
    && (misilEnemigo->x1 > nave->x1) && (misilEnemigo->x1 < (nave->x1 + NAVE_WIDTH)) ) {
        //BAJAR VIDAS DEL JUGADOR
        nave->vidas--;
        //printf("Vidas del jugador: %d \n", nave->vidas);
    }
}

void colisionConMuro(Enemigo *enemigo, Muro *muro){
    Muro *muroAux= muro;
    MisilEnemigo *misilAux= enemigo->misil;
    //printf("entro a colision con enemigo\n");
    while(muroAux!=NULL&&misilAux!=NULL){
        if(misilAux->activo==true){
            if((muroAux->x1<misilAux->x1)&&((muroAux->x1+MURO_WIDTH)>misilAux->x1) &&
                    (muroAux->y1<misilAux->y2)&&((muroAux->y1+MURO_HEIGHT) > misilAux->y2)){
                misilAux->activo=false;
                printf("misil ahora falso \n");
            }
        }
        muroAux=muroAux->siguiente;
    }
}

