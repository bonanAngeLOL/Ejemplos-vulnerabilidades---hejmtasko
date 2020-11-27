#include <stdio.h>

int main(int argc, char *argv[]){
    //Printf debería recibir al menos dos parametros, formato y texto
    //El parametro de formato permite inyectar código
    printf(argv[1]); 
}

/*
 * Caso 1
 *
 * Imprimir una simple cadena
 * */
//Arguments:"Esta cadena no es maliciosa :)" 

/*
 * Caso 2
 *
 * Muestra basura de la memoria stack
 * */
//Arguments:"%s%s%s%s%s%s%s%s%s%ss%s%s%s%s" 

/*
 * Caso 3
 *
 * Lanza la consola con privilegios de superusuario
 * */
//Arguments:"%s%n$(sudo bash)"

/*
 * Caso 4 
 *
 * Imprime la variable PATH y ejecuta un ls
 * */
//Arguments:"%s%n${PATH}\n$(ls)"
