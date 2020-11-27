/*
 * Injección de código C
 *
 * Este es un ejemplo de como injectar comandos en C 
 * 
*/

// CWE-77: Improper Neutralization of Special Elements used in a Command ('Command Injection')

#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Se ejecuta el comando cat para mostrar un archivo
    char cmd[200] = "/usr/bin/cat ";
    // Se agrega el argumento de la consola sin validación
    strcat(cmd, argv[1]);
    system(cmd);
    return 0;
}

/*
Recomendaciones:

Evitar usar, o usar apropiadamente:

system(), popen(), execlp(), execvp()
 
 */


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
//Arguments:'/dev/null&&ss -tunlp'
