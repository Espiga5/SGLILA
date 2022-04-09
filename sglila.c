#include <stdio.h>
#include <stdlib.h>	//to use system()
#include <string.h> //to use strcpy()
#include <stdio.h>

char* version = "v0.2.1";

void Ejecutar_archivo_guardado(char* archivo);
void agregar_juego();
void menu();

int main(int charc, char* argv[]){
    if(charc == 2){
        if(strcmp(argv[1],"--version")==0)
            printf("SGLILA %s\n",version);
        else if(strcmp(arg[1],"--help")==0)
            ayuda();
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
    printf("Simple GZDOOM Linux Launcher by Espiga5\n\n");
    agregar_juego();
    printf("Gracias por usar mi software\n");
}

void Ejecutar_archivo_guardado(char* nombre){
    FILE* archivo = fopen(nombre,"r");
    char* comando = (char*) malloc(301*sizeof(char));
    
    if(archivo!=NULL){
        fgets(comando,300,archivo);
        system(comando);
    }
}

void agregar_juego(){
    char* titulo = (char*) malloc(26*sizeof(char));
    char* comando = (char*) malloc(301*sizeof(char));
    char respuesta;
    int aux;

    printf("Título: ");
    fgets(titulo,25,stdin);
    titulo[strlen(titulo)-1]='\0';
    strcat(titulo,".txt");
    FILE* archivo = fopen(titulo,"r");
    if(archivo!=NULL){
        printf("Ya existe un juego con ese título. ¿Desea reemplazarlo? (s/n)\n");
        do{
            respuesta = (char) getchar();
            //printf("(%d||%d) %c",respuesta=='s',respuesta=='n',respuesta);
            do{
                aux=getchar();
            }while(aux!='\n'&&aux!=EOF);
            if(respuesta=='n'){
                agregar_juego();
                printf("(%d||%d) %c",respuesta=='s',respuesta=='n',respuesta);
            }else if(respuesta!='s'&&respuesta!='n'){
                printf("Respuesta invalida. Presiona \'s\' para reemplazar o \'n\' para no reemplazar y elegir otro nombre.\n");
            }
        }while(respuesta!='s'&&respuesta!='n');
    }
    if(archivo==NULL||respuesta=='s'){
        archivo = fopen(titulo,"w");
        printf("Escribe el comando para correr el juego:\n");
        fgets(comando,300,stdin);
        if(fputs(comando,archivo)!=EOF)
            printf("Juego agregado\n");
        else
            printf("Error al crear agregar juego\n");
        fclose(archivo);
    }
}

void ayuda(){
    printf("Se almacenan las instrucciones para ejecutar un juego compatible con GZDOOM en archivos txt.\n\nUso: ./sglila [titulo_de_juego]\n");
    printf("Opciones posibles:\n\n");
    printf("--help                       Muestra este pequeño manual\n");
    printf("--version                    Muestra versión del software\n");
    printf("[titulo_de_juego]            Ejecuta directamente un juego\n");
    printf("[sin_opcion]                 Muestra el menu de usuario\n");
}
