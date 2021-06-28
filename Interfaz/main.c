//
// Created by falei on 24/6/2021.
//

#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "Headers/jugador.h"



//Definiciones de globales y macros
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//#define SCREEN_WIDTH 800
//#define SCREEN_HEIGHT 600
#define MS 20
//#define NAVE_WIDTH 50
//#define NAVE_HEIGHT 45
//#define NAVE_VEL 10

//#define MISIL_LEN 5
//#define MISIL_VEL 10
//#define ENEMIGO_WIDTH 30
//#define ENEMIGO_HEIGHT 30
//#define ENEMIGO_VEL 3

unsigned char *keys;
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer= NULL;

//Definiciones de funciones
bool init(); //inicializa pantalla
void close(); //cierra los punteros de la pantalla




bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else{
        gWindow = SDL_CreateWindow( "Space Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL ){
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else{
            gRenderer = SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
            keys= SDL_GetKeyboardState(NULL);
        }
    }
    return success;
}
void close()
{
    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}


int main( int argc, char* args[] )
{
    //Start up SDL and create window/*
    if( !init() ){
        printf( "Failed to initialize!\n" );
    }
    else
    {
        bool quit = false;
        bool GameOver= false;
        SDL_Event event;
        //---------------------------CREACION DEL JUGADOR----------------------------
        Nave *mi_nave= (Nave *) SDL_malloc(sizeof (Nave));

        mi_nave->x1= (SCREEN_WIDTH / 2 - NAVE_WIDTH / 2);
        //mi_nave->y1= (SCREEN_HEIGHT / 2 - NAVE_HEIGHT / 2);
        mi_nave->y1= SCREEN_HEIGHT-50;
        mi_nave->vel_x=NAVE_VEL;
        mi_nave->vel_y=NAVE_VEL;
        mi_nave->misiles= NULL;
        strcpy(mi_nave->path,"../images/nave.bmp");
        mi_nave->vidas=3;
        mi_nave->puntos=0;

        // OBJETOS PARA DIBUJAR AL JUGADOR
        SDL_Rect targetRect; //Rectangle to which pacman image will be drawn
        SDL_Surface* bmpSurface = NULL; //To hold bmp image
        SDL_Texture* bmpTexture = NULL; //To hold bmp image

        bmpSurface = SDL_LoadBMP(mi_nave->path);
        //Convert surface to texture for rendering
        bmpTexture = SDL_CreateTextureFromSurface(gRenderer, bmpSurface);
        SDL_FreeSurface(bmpSurface);

        //-----------------------------CREACION DEL PRIMER ENEMIGO------------------
        Enemigo  *enemigo= (Enemigo *) SDL_malloc(sizeof (Enemigo));
        enemigo->x1= 20;
        enemigo->y1 =80;
        enemigo->bmpTexture = NULL;
        strcpy(enemigo->path,"../images/rosado.bmp");
        enemigo->siguiente = NULL;
        enemigo->flag = true;
        enemigo->misil = NULL;

        crear_enemigos(enemigo);
        //------------------------- CRECION DEL PRIMER MURO ------------------------
        Muro *muro= (Muro *) SDL_malloc(sizeof (Muro));
        muro->x1= SCREEN_WIDTH/2-250- MURO_WIDTH/2;
        muro->y1=SCREEN_HEIGHT-160;
        muro->siguiente=NULL;
        muro->colisiones=0;
        muro->destruido=false;
        strcpy(muro->path, "../images/muro.bmp");
        crearMuros(muro);

        SDL_Surface* muroSurface = NULL; //To hold bmp image
        SDL_Texture* muroTexture = NULL; //To hold bmp image

        muroSurface = SDL_LoadBMP(muro->path);
        //Convert surface to texture for rendering
        muroTexture = SDL_CreateTextureFromSurface(gRenderer, muroSurface);
        SDL_FreeSurface(muroSurface);

        int flag= 1;

        // EL JUEGO SE VA A CREAR

        //While application is running
        while( !quit ) {
            //VENTANA DE INICIO
            if(flag==1){
                SDL_Rect targetRect_aux; //Rectangle to which pacman image will be drawn
                SDL_Surface* image = NULL; //To hold bmp image
                SDL_Texture* mytexture = NULL; //To hold bmp image
                image = SDL_LoadBMP("../images/intro.bmp");

                mytexture = SDL_CreateTextureFromSurface(gRenderer, image);
                SDL_FreeSurface(image);

                targetRect_aux.w = SCREEN_WIDTH;
                targetRect_aux.h = SCREEN_HEIGHT;
                targetRect_aux.x = 0;
                targetRect_aux.y = 0;

                while(flag==1){

                    SDL_UpdateWindowSurface(gWindow);
                    //SDL_SetRenderDrawColor(gRenderer,127,80,154,0);
                    SDL_RenderClear(gRenderer);

                    SDL_RenderCopy(gRenderer, mytexture, NULL, &targetRect_aux); //Se pinta la imagen
                    SDL_RenderPresent(gRenderer);
                    if(SDL_PollEvent(&event)) {
                        if (event.type == SDL_QUIT){
                            quit = true;
                            flag=0;
                        }
                        else if (event.type == SDL_KEYDOWN && keys[SDL_SCANCODE_SPACE]){
                            flag = 0;
                            SDL_DestroyTexture(mytexture);
                        }
                    }
                    SDL_Delay(MS);
                }
            }

            // -----------------EVENTOS TECLADO-------------
            if(SDL_PollEvent(&event)){
                if (event.type == SDL_QUIT)
                    quit = true;
                else if(event.type==SDL_MOUSEBUTTONDOWN){
                    if(SDL_GetMouseState(NULL,NULL)&
                       SDL_BUTTON(SDL_BUTTON_LEFT)){
                        disparar();
                    }
                } else if(event.type == SDL_KEYDOWN){
                    if(keys[SDL_SCANCODE_ESCAPE]){
                        quit=true;
                    } else if(keys[SDL_SCANCODE_LEFT]){
                        mi_nave->vel_x= -abs(mi_nave->vel_x);
                        avanza_horizontal();
                    }else if(keys[SDL_SCANCODE_RIGHT]){
                        mi_nave->vel_x= +abs(mi_nave->vel_x);
                        avanza_horizontal();
                    }else if(keys[SDL_SCANCODE_UP]){
                        mi_nave->vel_y= -abs(mi_nave->vel_y);
                        avanza_vertical();
                    }else if(keys[SDL_SCANCODE_DOWN]){
                        mi_nave->vel_y= +abs(mi_nave->vel_y);
                        avanza_vertical();
                    }else if(keys[SDL_SCANCODE_SPACE]){
                        disparar();
                    }
                }
            }

            //Update the surface
            borrar_misil(mi_nave->misiles);
            //---------------- PANTALLA ---------------
            SDL_UpdateWindowSurface(gWindow);
            SDL_SetRenderDrawColor(gRenderer,0,0,0,0);
            SDL_RenderClear(gRenderer);
            SDL_SetRenderDrawColor(gRenderer,255,255,255,0);
            //Nave *nave, SDL_Rect targetRect, SDL_Surface *bmpSurface, SDL_Texture *bmpTexture
            pintar_Nave(mi_nave, targetRect, bmpTexture,gRenderer, enemigo,muro);
            pintar_Enemigos(enemigo,gRenderer);
            pintarMuro(gRenderer, muroTexture, muro);

            SDL_RenderPresent(gRenderer);
            SDL_Delay(MS);
            Enemigo  *enemigoAux = enemigo;
            int counter_Marcador=0;

            while (enemigoAux != NULL){
                if(enemigoAux->flag==false)
                    counter_Marcador++;
                enemigoAux=enemigoAux->siguiente;
            }
            free(enemigoAux);
            mi_nave->puntos=counter_Marcador*30;

            printf("Marcador de jugador %d \n", mi_nave->puntos);

            // GAME OVER
            if(mi_nave->vidas==0){
                SDL_Rect rectangulo;
                rectangulo.y=0;
                rectangulo.x=0;
                rectangulo.w= SCREEN_WIDTH;
                rectangulo.h=SCREEN_HEIGHT;
                SDL_UpdateWindowSurface(gWindow);
                SDL_SetRenderDrawColor(gRenderer,127,80,154,0);
                SDL_RenderClear(gRenderer);
                SDL_RenderDrawRect(gRenderer,&rectangulo);
                //SDL_RenderCopy(gRenderer, mytexture, NULL, &targetRect_aux); //Se pinta la imagen
                SDL_RenderPresent(gRenderer);

                SDL_Delay(2000);
                quit=true;
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}

