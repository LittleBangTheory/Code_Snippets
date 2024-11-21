`users_management.sh` crée des utilisateurs à partir de noms dans un CSV en respectant les règles UNIX suivantes :

- Il est interdit de réutiliser des uid lors de la création de compte.
- A la création du compte, un mot de passe aléatoire composé d’au moins 10 caractères (majuscule,minuscule, chiffre) dont au moins 1 caractère spécial (& ;,…) est généré et fourni à l’utilisateur. Ce mot de passe doit être changé lors de la première connexion.
- Par défaut un groupe principal (gid=uid) est crée par utlisateur, (mais un utilisateur peut aussi appartenir à des groupes supplémentaires).
- Un utilisateur temporaire (c’est à dire un utilisateur dont la date d’expiration du compte est connue) est soumis aux règles suivantes :
    - Le mot de passe est valide 60 jours, et l’utilisateur est prévenu 10 jours à l’avance de la nécéssité de changement de mot de passe.
    - Au bout de 30 jours d’inactivité, le compte est bloqué,
- Un utilisateur permanent (c’est à dire un utilisateur dont la date d’expiration du compte n’est pas connue) est soumis aux règles suivantes :
    - Le mot de passe est valide 120 jours, et l’utilisateur est prévenu 20 jours à l’avance de la nécéssité de changement de mot de passe.
    - Au bout de 30 jours d’inactivité, le compte est bloqué,
