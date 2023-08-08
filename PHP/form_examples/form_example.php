<!DOCTYPE html> 
<!-- Exemple de page de login -->
<html>
	<head>
        <!-- Encodage -->
		<meta charset="UTF-8">

        <!-- CSS -->
		<link rel="stylesheet" type="text/css" href="style.css">

        <!-- Google Fonts -->
		<link rel="preconnect" href="https://fonts.googleapis.com">
		<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
		<link href="https://fonts.googleapis.com/css2?family=Roboto&display=swap" rel="stylesheet">

        <!-- Medias -->
		<link rel="icon" type="image/x-icon" href="../medias/flask-solid.svg">

        <!-- Titre -->
		<title>Title</title>
	</head>

    <body>
        <div class="banner">
            <!-- Logo et Titre-->
			<img src="flask-solid.svg" alt="Logo"/>
			<h1>Titre</h1>

            <!-- Navbar -->
			<div class="navbar">
                <a href="index.php">Accueil</a>
			</div>
		</div>

		<!-- Formulaire de selection d'un element et de caractéristiques -->
		<form action="form.php" method="post">

			<!-- Choix de l'élément -->
			<label class="elementchoice" for="element">Choix de l'élément :</label>
			<select id="element" name="element">
				<!-- Groupe 1 -->
				<optgroup label="groupe_1">
					<option value="option_1">Option 1</option>
					<option value="option_2">Option 2</option>
				</optgroup>

				<!-- Groupe 2 -->
				<optgroup label="groupe_2">
					<option value="option_3">Option 3</option>
					<option value="option_4">Option 4</option>
				</optgroup>
			</select>

			<!-- Choix de la durée -->
			<label class="duree" for="duree">Duree :</label>
			<select id="duree" name="duree">
				<?php
					// Affichage des options de 1 à 30 jours
					for ($i = 1; $i <= 30; $i=$i+1) {
						$jour = strval($i);
						echo "<option value='$jour'>$jour</option>";
					}
				?>
			</select>
				
			<!-- Options requises -->
			<label class="option_requise_1" for="option_requise_1">Option requise 1 :</label>
			<input type="text" id="option_requise_1" name="option_requise_1" required>
			<br>
			<label class="option_requise_2" for="option_requise_2">Option requise 2 :</label>
			<input type="text" id="option_requise_2" name="option_requise_2" required>
			
			<!-- Validation -->
			<button type="submit">Valider</button>
		</form>

		<?php
			// Si une demande a été faite
			if(isset($_POST['element']) && isset($_POST['duree']) && isset($_POST['option_requise_1']) && isset($_POST['option_requise_2'])) {
				// Récupération des données du formulaire
				$lab = $_POST['element'];
				$duration = $_POST['duree'];
				$nom = $_POST['option_requise_1'];
				$prenom = $_POST['option_requise_2'];

				/* RESTE DU CODE */
			}
		?>
		<div id="footer">Copyright &copy; 2023</div>
	</body>
</html>

