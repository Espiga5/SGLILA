#include <stdio.h>
#include <stdlib.h>	//to use system()
#include <string.h> //to use strcpy()
#include <stdio.h>

char* version = "v1.0.1";

void Ejecutar_archivo_guardado(char* archivo);
void menu();

int main(int charc, char* argv[]){
    
    if(charc == 2){
        if(strcmp(argv[1],"--version")==0)
            printf("SGLILA %s\n",version);
        Ejecutar_archivo_guardado(argv[1]);
    }else
        menu();
	
	return 0;
}

void menu(){
    printf("      _/_/_/    _/_/_/  _/        _/_/_/  _/          _/_/    \n");
    printf("   _/        _/        _/          _/    _/        _/    _/   \n");
    printf("    _/_/    _/  _/_/  _/          _/    _/        _/_/_/_/    \n");
    printf("       _/  _/    _/  _/          _/    _/        _/    _/     \n");
    printf("_/_/_/      _/_/_/  _/_/_/_/  _/_/_/  _/_/_/_/  _/    _/  %s\n",version);
    printf("Simple GZDOOM Linux Launcher by Spiga5\n\n");
}

void Ejecutar_archivo_guardado(char* nombre){
    FILE* archivo = fopen(nombre,"r");
    char* comando = (char*) malloc(300*sizeof(char));
    
    if(archivo!=NULL){
        fgets(comando,200,archivo);
        system(comando);
    }
}