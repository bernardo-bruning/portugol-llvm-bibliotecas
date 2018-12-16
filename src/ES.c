//Using SDL and standard IO
#include <stdio.h>
#include <stdarg.h>
#if ANDROID
#include <SDL.h>
#endif
#if WIN32
#include <SDL2/SDL.h>
#endif
#include "ES.h"

void escreva(const char *format, ...) {
	va_list	args;
	char	logstr[100000];

	va_start(args, format);
	vsprintf(logstr, format, args);
	SDL_Log("%s",logstr);
	va_end(args);
}

/*
void escreva(const char *format, ...) {
    va_list argptr;
    va_start(argptr, format);
    vfprintf(stderr, format, argptr);
    va_end(argptr);
    return 0;
}
*/