<?php
	// SCRIPTS : Pour chaque fichier dans le dossier documents, on affiche un lien vers le fichier

	// Dossier contenant les documents
	$dir = "./documents/";

	// Recuperation de la liste des fichiers
	$files = scandir($dir);

	// Affichage des fichiers dans un tableau de 2 colonnes
	$column_index = 0;
	// Pour chaque fichier dans le dossier
	foreach ($files as $file) {

		// Si ce n'est pas un dossier
		if ($file != "." && $file != "..") {
			// Si c'est le premier élément de la ligne, création d'une nouvelle ligne
			if ($column_index == 0) {
				echo "<tr class=\"tr_align\">";
			}
				// On affiche le fichier
				echo "<td class=\"td_align\">";
					// Nom du fichier
					echo "<h3>Document $file</h3>";
					echo "<br>";
					// Lien vers le fichier
					echo "<p><a href=\"docs/$file\">$file</a></p>";
					echo "<br>";
				echo "</td>";
			
			// Si c'est le dernier élément de la ligne, on ferme la ligne
			if ($column_index == 1) {
				echo "</tr>";
				// On réinitialise l'index de colonne
				$column_index = 0;
			} else {
				// Sinon on incrémente l'index de colonne
				$column_index++;
			}
		}
	}
?>