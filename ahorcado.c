#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int intentosmax = 6;
int opciones = 5;
const char *palabras[] = {"snoopy", "lucy", "schroeder", "charlie", "woodstock"};
int intentos = 0;
char c;

void dibujo(int intentos){
    switch(intentos){
        case 0:
            printf("__________ \n |        | \n | \n | \n | \n | \n |_____________ \n");
            break;
        case 1:
            printf("__________ \n |        | \n |        O \n | \n | \n | \n |_____________ \n");
            break;
        case 2:
            printf("__________ \n |        | \n |        O \n |        | \n | \n | \n |_____________ \n");
            break;
        case 3:
            printf("__________ \n |        | \n |        O \n |       /| \n | \n | \n |_____________ \n");
            break;
        case 4:
            printf("__________ \n |        | \n |        O \n |       /|\\ \n | \n | \n |_____________ \n");
            break;
        case 5:
            printf("__________ \n |        | \n |        O \n |       /|\\ \n |       / \n | \n |_____________ \n");
            break;
        case 6:
            printf("__________ \n |        | \n |        O \n |       /|\\ \n |       / \\ \n | \n |_____________ \n");
            break;
    }
}

int main(){
    srand(time(0));
    const char *palabra = palabras[rand() % opciones];
    int largo = strlen(palabra); 
    char juego[largo]; 

    for(int i=0; i<largo; i++){
        juego[i] = '_';
    }

    juego[largo] = '\0'; // necesario para que no se imprima la basura, define el fin de la cadena
    
    printf("Bienvenido al juego del ahorcado de personajes de Peanuts! \n");

    while (intentos < intentosmax){
        dibujo(intentos);
        printf("Tu juego es: %s\n", juego);
        printf("Escribe una letra (siempre en minusculas): \n");
        scanf(" %c", &c);
        
        int acierto = 0; // Marcamos si hubo algún acierto en esta ronda
        for (int k = 0; k < largo; k++){
            if (palabra[k] == c){ // si c está en la palabra
                juego[k] = c; // reemplazo el guion bajo en su misma posición por c
                acierto = 1; 
            }
        }

        if (acierto == 1){
            printf("La letra ingresada es correcta!\n");
        } else {
            intentos++; // sumo uno a sus intentos
            printf("La letra ingresada no esta en la palabra.\n");
        }

        if (strcmp(juego, palabra) == 0){ // para comparar strings, no se pueden comprobar directamente
            printf("Ganaste! Felicidades :D");
            printf("El personaje era: %s", palabra);
            break;
        }
    }
    if (intentos == intentosmax) {
        dibujo(intentos);
        printf("Perdiste! Te quedaste sin intentos. El personaje era: %s\n", palabra);
    }
    return 0;
}
