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

		<!-- Formulaire à deux actions -->
		<form action="two_actions_form.php" method="post">
			<label for="option">Option :</label>
			<input type="text" id="option" name="option"><br>
			<button type="submit" name="action" value="action_1">Action 1</button>
			<button type="submit" name="action" value="action_2">Action 2</button>
			<br>
		</form>
		<?php
			//Si le form a été rempli
			if(isset($_POST['action'])){
				// Récupération des données du formulaire
				$option = $_POST['option'];

				// Si l'utilisateur clique le premier bouton
				if ($_POST['action'] == "action_1"){
					/* CODE */

				// Si l'utilisateur clique le deuxième bouton
				} else if ($_POST['action'] == "action_2"){
					/* CODE */
				}						
			}
		?>
		<div id="footer">Copyright &copy; 2023 NXO</div>
	</body>
</html>

