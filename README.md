#PROJET SN
📌 Analyseur de Logs en C++

📝 Description

Ce projet est un programme en C++ permettant d'analyser un fichier de logs. Il peut afficher des statistiques, filtrer les logs par date, par type d'événement ou rechercher un mot-clé dans les messages.

🚀 Fonctionnalités

1. Lecture des logs depuis un fichier texte


2. Affichage des statistiques (nombre d'INFO, WARNING, ERROR)


3. Filtrage des logs

Par date (ex: 2024-01-29)

Par type d'événement (INFO, WARNING, ERROR)

Par mot-clé dans les messages



4. Interface interactive avec menu



🛠 Compilation et Exécution

📌 Compilation

g++ main.cpp -o analyseur

📌 Exécution

./analyseur

L'utilisateur doit entrer le nom du fichier log à analyser (ex: logs.txt).

📂 Format du fichier log

Chaque ligne doit être au format :

YYYY-MM-DD TYPE Message

Exemple de fichier test:

2024-01-29 INFO Démarrage du serveur
2024-01-29 WARNING Connexion instable
2024-01-29 ERROR Échec de connexion à la base de données

📌 Auteur

Développé par PAKOO  SUZI & NDZOULI WALTER.
