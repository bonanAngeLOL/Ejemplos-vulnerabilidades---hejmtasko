<?php 
    /*
     * Whitelist
     * */
    function valor($x){
        $valor = "Incorrecto";
        switch($x){
            case 1:
                $valor = "Este el mensaje 1";
                break;
            case "success":
                $valor = "Este es un mensaje de confirmación";
                break;
        }
        return $valor;
    }

    //Se recibe el valor desde la URL por el metogo GET
    $x = valor($_GET["message"]);
    @eval ("echo '" . $x . "';");

    echo '<br><br>';
    $sanitizado = htmlentities($_GET["message"]);
    //Sanitizado
    @eval ('echo "'.$sanitizado.'";');

    /*
     * Cuidado al usar
     *
     * exec(), system(), passthru() 
     *
     * */

/*
 * Caso de uso 1
 *
 * Mostrar un ls 
 * */
//Run:http://[Dirección de tu servidor]/badEvalFix.php?message=1;echo%20shell_exec(%27ls%20-lart%27) 

/*
 * Caso de uso 2
 *
 * Cadena ejemplo
 * */
//Run:http://[Dirección de tu servidor]/badEvalFix.php?message=asdf;

/*
 * Caso 3
 *
 * Intentar imprimir un phpinfo()
 * */
    //Run:http://[Dirección de tu servidor]/badEvalFix.php?message=1;phpinfo()

/*
 * Caso 4
 *
 * Se inyecta codigo primero en el eval, luego en la salida un alert que puede ver el usuario
 * */
//Run:http://[Dirección de tu servidor]/badEval.php?message=1;echo%20%27%3Cscript%3Ealert(%22asdf%22)%3C/script%3E%27

/*

    Tener cuidado con funciones que ejecutan comandos o que 
    evaluan strings como comandos o código.

    C:
        system(), popen(), execlp(), execvp()
 
    Python:
        exec(), eval(), os.system(), os.popen(), input()

    PHP:
        eval(), exec(), 

    También hay que tener cuidado con los permisos de ejecucióm.
 */
?>
