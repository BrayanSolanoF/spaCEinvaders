//
// Created by falei on 27/6/2021.
//

#include "../Headers/enemigo.h"
#include "../Headers/jugador.h"


void pintar_Enemigos(Enemigo *enemigo, SDL_Renderer *gRenderer){
    Enemigo *mi_enemigo= enemigo;

    //SDL_Surface* bmpSurface_ = NULL; //To hold bmp image
    //bmpSurface_ = SDL_LoadBMP(mi_enemigo->path);

    SDL_Rect rectangulo;

    while(mi_enemigo != NULL){
        SDL_SetRenderDrawColor(gRenderer,255,0,205,0);
        //Convert surface to texture for rendering
        //mi_enemigo->bmpTexture= SDL_CreateTextureFromSurface(gRenderer, bmpSurface_);
        if(mi_enemigo->flag==true){
            rectangulo.w = ENEMIGO_WIDTH;
            rectangulo.h = ENEMIGO_HEIGHT;
            rectangulo.x = mi_enemigo->x1;
            rectangulo.y = mi_enemigo->y1;
            //SDL_RenderCopy(gRenderer, mi_enemigo->bmpTexture, NULL, &mi_enemigo->targetRect); //Se pinta la imagen
            SDL_RenderDrawRect(gRenderer, &rectangulo);
            if(mi_enemigo->misil!=NULL){
                if(mi_enemigo->misil->activo==true){
                    SDL_SetRenderDrawColor(gRenderer,255,255,200,0);
                    SDL_RenderDrawLine(gRenderer, mi_enemigo->misil->x1, mi_enemigo->misil->y1,mi_enemigo->misil->x2,
                                       mi_enemigo->misil->y2);
                }
            }
        }
        mi_enemigo = mi_enemigo->siguiente;
    }
    //SDL_FreeSurface(bmpSurface_);
    movimiento_Enemigo(enemigo);
    free(mi_enemigo);
}

int movimientoEnemigoVal=ENEMIGO_VEL;
int enemigoDisparando=1;
bool alguienDisparando=false;
void movimiento_Enemigo(Enemigo *enemigo){
    Enemigo *enemigo_aux1= enemigo;
    bool limite=false;
    while(enemigo_aux1 != NULL){
        if(enemigo_aux1->x1  < 0){
            movimientoEnemigoVal= +SDL_abs(ENEMIGO_VEL);
            limite=true;
        }else if((enemigo_aux1->x1+ENEMIGO_WIDTH) > SCREEN_WIDTH){
            movimientoEnemigoVal= -SDL_abs(ENEMIGO_VEL);
            limite=true;
        }

        enemigo_aux1= enemigo_aux1->siguiente;
    }

    free(enemigo_aux1);
    Enemigo *enemigo_aux2= enemigo;

    while(enemigo_aux2 != NULL){
        if(limite==true){
            enemigo_aux2->y1 += 20;
        }
        enemigo_aux2->x1 += movimientoEnemigoVal;
        enemigo_aux2= enemigo_aux2->siguiente;
    }
    free(enemigo_aux2);
    movimiento_Misil(enemigo);

}
void movimiento_Misil(Enemigo *enemigo){
    int count=1;

    Enemigo *enemigo_aux3=enemigo;
    while(enemigo_aux3 != NULL){
        enemigo_aux3->x1 += movimientoEnemigoVal;
        if(enemigo_aux3->misil==NULL){
            crearMisilEnemigo(enemigo_aux3); //CAMBIAAR
        }
        if(enemigo_aux3->misil->colisionMuroFlag==true){
            //printf("alguien disparando ahora va a ser false\n");
            alguienDisparando=false;
            enemigo_aux3->misil->colisionMuroFlag=false;

        }
        else if(enemigo_aux3->misil!=NULL && count==enemigoDisparando) {
            if (enemigo_aux3->misil->activo == false && alguienDisparando == false) {
                //NO SE MUEVE EL MISIL
                //printf
                enemigo_aux3->misil->x1=enemigo_aux3->x1+ENEMIGO_WIDTH/2;
                enemigo_aux3->misil->x2= enemigo_aux3->x1+ENEMIGO_WIDTH/2;
                enemigo_aux3->misil->colisionMuroFlag= false;
                enemigo_aux3->misil->activo=true;
                alguienDisparando=true;

            } else if(enemigo_aux3->misil->activo == true && alguienDisparando == true){

                misilActivo(enemigo_aux3->misil);
                colisionMisilE(enemigo_aux3->misil, enemigo_aux3);
            }

        }

        enemigo_aux3= enemigo_aux3->siguiente;
        count++;
        if(enemigoDisparando>10){
            enemigoDisparando=1;
            alguienDisparando=false;
        }

    }
    free(enemigo_aux3);

}

void crear_enemigos(Enemigo *enemigo){
    int pos_y=80;
    int pos_x = 20;
    Enemigo *auxiliar= enemigo;

    for(int i = 1; i<10;i++){
        //Generar nuevo espacio en memoria para el nuevo enemigo

        auxiliar->siguiente= (Enemigo *) SDL_malloc(sizeof (Enemigo));
        // Setear caracter??sticas del nuevo enemigo a mano
        auxiliar= auxiliar->siguiente;
        auxiliar->x1= pos_x +ENEMIGO_WIDTH+10;
        auxiliar->y1 = pos_y;
        strcpy(auxiliar->path, "../images/amarillo.bmp");
        auxiliar->bmpTexture= NULL;
        auxiliar->siguiente=NULL;
        auxiliar->flag=true;
        auxiliar->misil=NULL;
        pos_x += 40;
    }
    free(auxiliar);
}

void crearMisilEnemigo(Enemigo *enemigo){
    enemigo->misil= (MisilEnemigo*)SDL_malloc(sizeof (MisilEnemigo));
    enemigo->misil->activo=false;
    enemigo->misil->x1= enemigo->x1+ENEMIGO_WIDTH/2;
    enemigo->misil->y1= enemigo->y1+ENEMIGO_HEIGHT;
    enemigo->misil->x2= enemigo->x1+ENEMIGO_WIDTH/2;
    enemigo->misil->y2= enemigo->y1+ENEMIGO_HEIGHT+MISIL_LEN;
    enemigo->misil->vel_x=0;
    enemigo->misil->vel_y=MISIL_VEL;
    enemigo->misil->colisionMuroFlag=false;
    //enemigo->misil->activo=false;
}

void misilActivo(MisilEnemigo *misilE){
    if(misilE->activo==true){
        misilE->x1 += misilE->vel_x;
        misilE->y1 += misilE->vel_y;
        misilE->x2 += misilE->vel_x;
        misilE->y2 += misilE->vel_y;
    }
}
void colisionMisilE(MisilEnemigo *misilE, Enemigo *enemigo){
    if(misilE->y1>SCREEN_HEIGHT){
        misilE->activo=false;
        misilE->y1= enemigo->y1+ENEMIGO_HEIGHT;
        misilE->x2= enemigo->x1+ENEMIGO_WIDTH/2;
        misilE->y2= enemigo->y1+ENEMIGO_HEIGHT+MISIL_LEN;
        misilE=NULL;
        enemigoDisparando++;
        alguienDisparando=false;
    }
}

