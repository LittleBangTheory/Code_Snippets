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

        <?php
            // On vérifie que le cookie admin est set 
            if(isset($_COOKIE['cookie_name'])){
                // On récupère la valeur du cookie
                $cookie_value = $_COOKIE['cookie_name'];

                // On se connecte à la base de données
                $host = "";
				$user = "";
				$password = "";
				$database = "";
                $conn = mysqli_connect($host, $user, $password, $database);

                // Verification que la valeur du cookie est bien dans la table cookies
                $sql = "SELECT valeur FROM cookies WHERE valeur='$cookie_value'";
                $command = mysqli_query($conn, $sql);
                $commandresult = mysqli_fetch_assoc($command);
                $result = $commandresult['valeur'];

                // Si la valeur du cookie est dans la table cookies
                if($result != ""){
                    // Executer le code de la page
                }
                else{
                    // Si le cookie d'admin est incorrect, redirection vers la page de connexion
                    header("Location: login.php");
                }
            // Si le cookie d'admin n'est pas set, redirection vers la page de connexion
            } else {
                header("Location: login.php");
            }
        ?>
        <div id="footer">Copyright &copy; 2023</div>
    </body>
</html>
