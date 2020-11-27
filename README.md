# Ejemplos vulnerabilidades

Estos son los archivos que se mostraron en la presentación, puedes usar tu IDE preferido para correrlos

## Uso

El código es vulnerable, para poder explotar sus vulnerabilidades hay comentarios en la parte de abajo para poder recrear el ejercicio.
Deberías intentar correrlos con permisos de administrador o superusuario en Linux para apreciar mejor el ejemplo.


### C

En los comentarios se muestran los argumentos que se deben usar desde la linea de comandos

```C
//Arguments:arg1 arg2 arg3 ...
```

Puedes compilar el código con gcc y después ejecutarlo con los comandos del comentario:

```Bash
./programa arg1 arg2 arg3 ... 
```

### PHP

Puedes correr los scripts vulnerables en cualquier versión de PHP, en teoría deberían funcionar.
Hay comentarios el final que muestran las URL que deben ser probadas para replicar el caso de uso:

```PHP
//Run:http://[dirección de tu servidor]/[archivo]?parametro=valor...
```
