<?php
    /*
    Script permettant de supprimer les cookies expirés de la table cookies de la base de données
    Doit s'accompagner d'un cron job pour être exécuté régulièrement
    */

    // Connexion à la base de données (à modifier)
    $host = "";
    $user = "";
    $password = "";
    $database = "";
    $conn = mysqli_connect($host, $user, $password, $database);

    // On supprime de la table cookies tous les cookies expirés (1h)
    $sql = "DELETE FROM cookies WHERE date_creation < CURDATE() OR (date_creation = CURDATE() AND heure_creation + duree/60 < CURTIME())";
    $command = mysqli_query($conn, $sql);
    
    // Fermerture de la connexion
    mysqli_close($conn);
?>