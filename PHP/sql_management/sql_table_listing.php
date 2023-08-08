<?php
    /* Exemple de listing de table SQL */
    // Tableau
    echo "<table>";
        // Ligne d'en-tête
        echo "<tr>";
            echo "<th>Colonne 1</th>";
            echo "<th>Colonne 2</th>";
            echo "<th>Colonne 3</th>";
        echo "</tr>";
        
        // Récupération des données de la table
        $sql = "SELECT * FROM $tableName";
        $command = mysqli_query($conn, $sql);

        // Affichage des données dans le tableau
        while($row = mysqli_fetch_assoc($command)){
            echo "<tr>";
                echo "<td>" . $row['colonne1'] . "</td>";
                echo "<td>" . $row['colonne2'] . "</td>";
                echo "<td>" . $row['colonne3'] . "</td>";
            echo "</tr>";
        }
    echo "</table>";

    // Fermeture de la connexion
    mysqli_close($conn);
?>