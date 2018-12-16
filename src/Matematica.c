//Using SDL and standard IO
#include <stdio.h>
#if ANDROID
#include <SDL.h>
#endif
#if WIN32
#include <SDL2/SDL.h>
#endif
#include <stdlib.h>
#include <math.h>
#include "Matematica.h"


double portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaMatematica_arredondar(double valor, int fixar) {
    return round(valor);
}

int portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaMatematica_valor_absoluto(double valor) {
    return round(valor);
}
