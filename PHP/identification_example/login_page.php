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

        <!-- Formulaire de login -->
        <form action="login.php" method="post">
            <!-- Login -->
            <label class="login" for="login">Login :</label>
            <input type="text" id="login" name="login" required>
            <br><br>
            <!-- Mot de passe -->
            <label class="mdp" for="mdp">Mot de passe :</label>
            <input type="password" id="mdp" name="mdp" required>
            <br><br>
            <!-- Bouton de validation -->
            <input type="submit" value="Submit">
        </form>
        <?php
            // Si le formulaire est rempli
            if (isset($_POST['login']) && isset($_POST['mdp'])) {

                // Connexion à la base de données (à modifier)
                $host = "";
                $user = "";
                $password = "";
                $database = "";
                $conn = mysqli_connect($host, $user, $password, $database);

                // On récupère les données du formulaire
                $login = $_POST['login'];
                $mdp = $_POST['mdp'];
                
                // On vérifie que le login et le mdp sont corrects
                if (($login == "login" && $mdp == "motdepasse")) {
                    // Initialise un cookie avec une valeur aléatoire de 10 octets
                    $cookie_value = bin2hex(openssl_random_pseudo_bytes(10));
                    // Enregistre le cookie dans le navigateur
                    setcookie("admin", $cookie_value, time() + 3600);

                    // Enregistre dans la table cookies le cookie, la date et l'heure, et la durée 
                    $sql = "INSERT INTO cookies (valeur, date_creation, heure_creation, duree_minutes) VALUES ('$cookie_value', CURDATE(), CURTIME(), 60)";
                    $command = mysqli_query($conn, $sql);

                    // Fermeture de la connexion
                    mysqli_close($conn);
                    
                    // On redirige vers le compte admin
                    header("Location: admin.php");
                } else {
                    // Si les credentials sont incorrectes, affichage d'un message d'erreur
                    echo "<br><br><p class='error'>Login ou mot de passe incorrect</p>";
                }
            }
        ?>
    </body>
</html>