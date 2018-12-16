# Requisitos 

- [llvm 3.1](https://github.com/bernardo-bruning/portugol-core-llvm/releases/download/llvm3.1/LLVM.zip) 
- [MinGW](https://sourceforge.net/projects/mingw/files/Installer/mingw-get-setup.exe/download) 
- [SDL](https://www.libsdl.org/release/SDL2-devel-2.0.9-mingw.tar.gz) 
- [SDL_Image](https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.4-mingw.tar.gz) 
- [Android NDK r14b](https://dl.google.com/android/repository/android-ndk-r14b-windows-x86_64.zip) 
- Android SDK 


# Instalação 

## MinGW 

Após efetuar download a instalação do mingw-get deve-se executar o seguinte comando via prompt de comando. 

``` 
mingw-get install gcc mingw32-make msys 
``` 

Com a execução efetuada, deve-se então abrir abrir o arquivo `C:\MinGW\msys\1.0\msys.bats`. 

## Configuração Android SDK 
Com o download efetuado da SDK e instalado então vamos registrar a variável de ambiente ANDROID_HOME passando o path de instalação da SDK. Com a configuração de ambiente feita então se faz necessário a instalação do SDK Tool 25.2.5 e Plataforma android 23 Marshmallow. 


## Configuração compilação 
Com todo o processo realizado será necessário descompactar as pastas das bibliotecas SDL e SDL_Image em C:\MinGW. Com a instalação das bibliotecas altera-se o NDK path na pasta do projeto `.\src\Makefile` encontrando a variável NDK_PATH e colocando o caminho, por padrão o caminho da ndk é `C:\ndk` 

# Compilação 

## Compilação Android 

Antes de se compilar o projeto de teste, deve-se primeiramente se gerar os binários das bibliotecas do portugol, podendo ser gerada através do BAT que se encontra em `.\android\build.bat`. Com os binários das bibliotecas gerado então partimos para a geração do projeto de teste que pode ser gerado através do processo `.\teste\build-android.bat` o projeto após compilado deve rodar diretamente ao dispositivo conectado, caso seja necessário a instalação manual da apk deve-se copia-la do caminho `.\teste\android-project\bin\SDLActivity-debug.apk`. 
