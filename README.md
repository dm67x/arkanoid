# Arkanoid - Université de Strasbourg

Nous avions pour but de concevoir et développer un jeu vidéo qui se nomme "Arkanoid".
Pour cela nous allons devoir utiliser les principes appris lors de notre cours de Programmation Avancée, tels que les designs patterns et le C++ en version 11 et plus.

## Groupe

Notre groupe est composé de deux personnes :
- Mehmet Ozkan (alias dm67x)
- El-hadi Serradj

## Comment compiler ?

Pour simplifier le travail de compilation nous sommes partis sur l'utilisation de CMake pour automatiser ce principe.

Donc voici les étapes à suivre (pour une compilation linux avec un Makefile) :
- `cmake .` dans la racine du projet
- `make sdl2` si SDL2 n'est pas installé sur la machine
- `make`

## Comment lancer ?

L'executable se situe dans le dossier "bin". Il suffit de le lancer avec un terminal (ou de double-cliquer dessus en fonction du système).