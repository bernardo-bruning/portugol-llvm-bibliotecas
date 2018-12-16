#include <stdio.h>
#if ANDROID
#include <SDL.h>
#endif
#if WIN32
#include <SDL2/SDL.h>
#endif

/*
void escreva(char* valor) {
	printf(valor);
}*/

int main(int argc, char* argv[]) {
	inicio();
    return 1;
}