<?php
    // obtenir le chemin absolu d'un programme au chemin relatif ../dossier/sousdossier/programme.php
    $programPath = realpath(__DIR__ . '/..'.'/dossier/sousdossier/programme.php');

    // Appeler un autre fichier avec arguments et exécution en arrière plan
    $command = "php other_file.php $arg1 $arg2 > /dev/null &";
    exec($command, $output, $return_var);
?>