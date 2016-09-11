//Using SDL and standard IO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#if ANDROID
#include <SDL_image.h>
#endif
#if WIN32
#include <SDL2/SDL_image.h>
#endif
#include "Graficos.h"

//Screen dimension constants
const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;

float escalaLargura;
float escalaAltura;

SDL_Window* window;
SDL_Surface* surface;
SDL_Renderer *renderer;

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_limpar() {
    #ifdef DEBUG
    printf("Limpando tela");
    #endif
    SDL_RenderClear(renderer);
    
}

int portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_criar_cor(int r, int g, int b) {
	#ifdef DEBUG
        printf("Criando cor r:%d g:%d b:%d \n", r, g, b);
    #endif
    int rgb = r;
    rgb = (rgb << 8) + g;
    rgb = (rgb << 8) + b;
	return rgb;
}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_definir_cor(int cor) {
    #ifdef DEBUG
        printf("Definindo cor \n", cor);
    #endif
    int red = (cor >> 16) & 0xFF;
    int green = (cor >> 8) & 0xFF;
    int blue = cor & 0xFF;

    
    SDL_SetRenderDrawColor(renderer, red, green, blue, 0);
}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_desenhar_ponto(int x, int y) {
    #ifdef DEBUG
        printf("Desenhando ponto na posi��o x:%d y:%d \n", x, y);
    #endif
    SDL_RenderDrawPoint(renderer, x, y); //Renders on middle of screen.
    SDL_PumpEvents();
}

int portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_carregar_imagem(char* caminho) {
    #ifdef DEBUG
        printf("Carregando imagem \"%s\" \n", caminho);
    #endif

    #ifdef ANDROID
        SDL_RWops *file = SDL_RWFromFile(caminho, "rb");
        SDL_Surface* image_endereco  = IMG_Load_RW(file, 1);
    #else
        SDL_Surface* image_endereco = IMG_Load(caminho);
    #endif
    
    if(image_endereco == NULL){
        printf("Imagem n�o encontrada para o caminho %s\n", caminho);
        return 0;
    } 

    int endereco = (int) image_endereco;    
    return endereco;
}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_iniciar_modo_grafico(int manter_visivel){
    #ifdef DEBUG
        printf("Iniciando modo grafico...\n");
    #endif

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Problemas ao inicializar o modo gr�fico: %s\n", SDL_GetError() );
    }

     else
    {
        //Cria janela
        window = SDL_CreateWindow("Programa", 50, 50, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

        //Define Escala
        int width = 0;
        int height = 0;

        SDL_GetWindowSize(window, &width, &height);

        escalaAltura = (float)height/(float)SCREEN_HEIGHT;
        escalaLargura = (float)width/(float)SCREEN_WIDTH;

        if( window == NULL )
        {
            printf( "Janela n�o foi criada: %s\n", SDL_GetError() );
        }
        else
        {
            //Atualiza tela
            SDL_UpdateWindowSurface(window);
        }
    }
}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_encerrar_modo_grafico(){
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_liberar_imagem(int endereco){
    return 0;
}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_renderizar(){
    SDL_RenderPresent(renderer);
    SDL_PumpEvents();
}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_renderizar_imagem(int largura, int altura){

}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_desenhar_imagem(int x, int y, int endereco){
    #ifdef DEBUG
        printf("Desenhando imagem x:%d y:%d endereco:%d \n", x, y, endereco);
    #endif    
    SDL_Surface* image_endereco = (SDL_Surface*) endereco;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image_endereco);

    SDL_Rect dest;
    dest.x = x*escalaLargura;
    dest.y = y*escalaAltura;
    dest.w = image_endereco->w * escalaLargura;
    dest.h = image_endereco->h * escalaAltura;

    SDL_RenderCopy(renderer, texture, NULL, &dest);
}
