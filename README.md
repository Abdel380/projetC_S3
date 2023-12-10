Projet Skip Lists 

Le projet se compose de 15 fichiers : 

cell.h / cell.c contenant les prototypes, structures et fonctions nécessaires pour créer une cellule dans une skip list. 

list.h / list.c qui contiennent les prototypes, structures et fonctions nécessaires pour créer, insérer, afficher, rechercher une cellule de manière brute ou de manière dichotomique ( en récursif). 

timer.h / timer.c qui permet de mesurer le temps d'exécution des différentes parties du projet, offrant ainsi une évaluation quantitative des performances.  

rdv.h / rdv.c qui contient les structures des rdv et les fonctions de création tels que les dates, les objets des rdv, l’heure, la date et le nom du contact. De plus, le fichier .c contient les fonctions de création, d’affichage, d’ajout et de suppression de rdv et enfin d’enregistrement des rdv dans un fichier. 

appointment.csv qui permet d’enregistrer les rdv dans le format : 
“nom_contact,objet_rdv,date_rdv,heure_rdv,duree_rdv” 

nat2021.csv qui contient tous les noms et prénoms des contacts à inclure dans la skip list 

agenda.h / agenda.c qui contient la structure de l’agenda et les fonctions d’insertion de contact dans celui-ci, création d’un rdv pour un contact, l’affichage de l’agenda et enfin la fonction qui permet d’enregistrer les rdv et les contacts dans un fichier. 

menu.h / menu.c qui est le gestionnaire de notre agenda, voici un petit guide : 

# Gestionnaire d'Agenda en C

## Description
Ce gestionnaire d'agenda en C offre une solution complète pour la gestion de contacts et de rendez-vous. Il fournit un menu interactif avec différentes fonctionnalités permettant à l'utilisateur de créer, afficher et gérer son agenda.

## Fonctionnalités Principales

Au début du programme, on vous demande de choisir entre le menu de la partie 2 ou de la partie 3. 



Menu de la partie 2 : 

### 1. Choisir la taille de la liste
- Sélectionnez l'option 1 pour définir la taille de la liste 

### 2. Affichage de la skip list
- Choisissez l’option 2 pour afficher l'ensemble de la skip list. 
- Les cellules sont organisées par niveaux pour une visualisation claire et structurée et qui respectent bien l’ordre avec un affichage correct et lisible. 

### 3. Rechercher une valeur 
- Choisissez l’option 3 pour rechercher une valeur dans la skip list, si la valeur n’existe pas, le programme vous le dira. 

### 4. temps d'exécution 
- Choisissez l’option 4 pour afficher le temps d'exécution d’une fonction. 

### 5. Rafraîchir la page
- Choisissez l’option 5 pour rafraîchir la page et avoir une page vide et lisible. 

 ### 6. Revenir au menu précédent 
- Choisissez l’option 6 revenir au menu précédent et changer de menu si vous le voulez. 

 ### 7. Quitter le programme
- Choisissez l’option 7 pour quitter le menu et fermer le programme


 





Menu de la partie 3 : 

### 1. Création d'un Nouveau Contact
- Sélectionnez l'option `create` pour créer un nouveau contact.
- Suivez les invites pour saisir les informations du contact, y compris le nom et les détails pertinents.
- Le contact sera ajouté à l'agenda.

### 2. Affichage de l'Agenda
- Choisissez `display` pour afficher l'ensemble des contacts dans l'agenda.
- Les contacts sont organisés par niveaux pour une visualisation claire et structurée.

### 3. Recherche d’un contact dans l’Agenda
- Choisissez `search` pour rechercher un contact dans l'agenda.
- Le programme renverra le contact s’il se trouve dans la liste, s’il n’y est pas, le programme vous en informera. 

### 4. Ajout d'un Rendez-vous
- Optez pour `add` pour ajouter un rendez-vous à un contact existant.
- Suivez les étapes pour sélectionner le contact et saisir les détails du rendez-vous, tels que l'objet, la date et l'heure.

### 5. Affichage des Rendez-vous d'un Contact
- Choisissez `showAPP` pour afficher tous les rendez-vous d'un contact spécifique.
- Entrez le nom du contact, et les rendez-vous associés seront affichés.

### 6. Suppression d’un Rendez-vous d'un Contact
- Choisissez `delete` pour supprimer un rdv d’un contact
- Entrez le nom du contact et le rdv que vous voulez supprimer. Si le contact et le rdv existent, le rdv sera supprimé, sinon, le programme vous indiquera qu’il n’existe pas. 

### 7. Chargement et Sauvegarde

- Utilisez `load` pour charger les contacts et rendez-vous à partir d'un fichier préexistant.

- Choisissez `save` pour sauvegarder les contacts et rendez-vous actuels dans un fichier.

### 8. Rafraîchir la page  

choisissez ‘back’ pour revenir au menu précédent. 

### 9. Quitter le programme 

- Utilisez `exit` pour quitter le programme sans sauvegarder 

- Choisissez `exitS’ pour quitter le programme tout en sauvegardant le fichier de l’agenda. 

IMPORTANT : Il faut exécuter le programme dans le terminal.  

