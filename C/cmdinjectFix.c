/*
 * Injección de código C
 *
 * Este es un ejemplo de como injectar comandos en C 
 * 
*/

// CWE-77: Improper Neutralization of Special Elements used in a Command ('Command Injection')

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const char * sanitize(char *input){
    char *sanitized;
    sanitized=(char*)malloc(strlen(input));
    int len = strlen( input );
    for (int i = 0; i < len; i++){
        if(input[i] == '&' || input[i] == ';')
            break;
        strncat(sanitized, &input[i], 1);
    }

    return (char *)sanitized;
}

int main(int argc, char *argv[]) {
    // Se ejecuta el comando cat para mostrar un archivo
    char cmd[200] = "/usr/bin/cat ";
    // Se guarda la cadena sanitizada
    const char *sanitized = sanitize(argv[1]);
    printf("Sanitized string %s\n\n\n", sanitized);
    // Se agrega el argumento de la consola sin validación
    strcat(cmd, sanitized);
    system(cmd);
    return 0;
}

/*
Primer caso de uso:
    Imprimir el código de este archivo
*/
//Arguments:./cmdinject.c 

/*
Segundo caso de uso:
    Imprimir el archivo /etc/shadow    
*/
//Arguments:/etc/shadow

/*
Tercer caso de uso:
    Listar contenido del directorio
*/
//Arguments:'/dev/null;ls -lastr'

/*
Cuarto caso de uso:
    Mostrar puertos que escuchan
*/
//Arguments:'/dev/null|ss -tunlp'

