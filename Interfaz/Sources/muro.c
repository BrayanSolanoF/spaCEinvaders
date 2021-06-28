//
// Created by falei on 27/6/2021.
//


#include "../Headers/muro.h"

void pintarMuro(SDL_Renderer *gRenderer, SDL_Texture *myTexture, Muro *muro){
    Muro *miMuro= muro;
    SDL_Rect rectangulo;
    int i=0;
    while((miMuro!=NULL) && (miMuro->destruido != true)){
        rectangulo.w= MURO_WIDTH;
        rectangulo.h= MURO_HEIGHT;
        rectangulo.x= miMuro->x1;
        rectangulo.y= miMuro->y1;
        SDL_RenderCopy(gRenderer, myTexture, NULL, &rectangulo);
        miMuro=miMuro->siguiente;
        i++;
    }
    free(miMuro);
}

void crearMuros(Muro *muro){
    Muro *auxiliar= muro;
    int pos_x= muro->x1;
    int pos_y= muro->y1;

    for(int i=0; i<2; i++){
        auxiliar->siguiente= (Muro *) SDL_malloc(sizeof (Muro));
        if(i==1)
            pos_x= 800/2- MURO_WIDTH/2;
        else
            pos_x= 600/2+250+ MURO_WIDTH/2;
        auxiliar= auxiliar->siguiente;
        auxiliar->x1= pos_x;
        auxiliar->y1=pos_y;
        auxiliar->siguiente= NULL;
        auxiliar->colisiones=0;
        strcpy(auxiliar->path, "../images/muro.bmp");
    }
}
void colisionMuro(Muro *muro){
    muro->colisiones +=1;
    if(muro->colisiones >= 8){
        muro->destruido=true;
    }
    //enviar("192.168.50.254", 7000, "[EliminaMuro;Fatima;3;34;93]");
}
