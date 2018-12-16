//Using SDL and standard IO
#include <stdio.h>
#if ANDROID
#include <SDL.h>
#endif
#if WIN32
#include <SDL2/SDL.h>
#endif
#include <stdlib.h>
#include "Tipos.h"

int portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaTipos_real_para_inteiro(double valor) {
	return (int) valor;
}