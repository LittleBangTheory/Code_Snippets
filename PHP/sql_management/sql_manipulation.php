<?php
    // Variables de connexion à la base de données (à modifier)
    $host = "";
    $user = "";
    $password = "";
    $database = "";

    // Connection à la base de données
    $conn = mysqli_connect($host, $user, $password, $database);
    // Vérification de la connexion
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    // Selectionner l'ensemble des lignes d'une table
    $sql = "SELECT $column_name FROM $table_name WHERE $caracteristic"; 

    // Parcourir les résultats
    $result = mysqli_query($conn, $sql);
    while ($row = mysqli_fetch_assoc($result)) {
        $var = $row['$column_name'];
    }
?>