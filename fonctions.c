//
// Created by alex on 24/10/2023.
//

#include "fonctions.h"


CONTACT* empty_contact(){
    CONTACT * contact = malloc(sizeof(CONTACT));
    contact->nom = NULL;
    contact->prenom = NULL;

    return contact;
}

void saisir_contact(CONTACT * contact){
    printf("Quelle est votre prenom :");
    contact->prenom = scanstring();
    printf("Quelle est votre nom :");
    contact->nom = scanstring();
}



DATE* empty_date(){
    DATE * date = malloc(sizeof(DATE));
    return date;
}

void saisir_date(DATE * date){
    date = empty_date(); // alloue la memoire


    printf("En quelle annee est votre rdv :"); // assignation pour l'annee
    do{
        scanf("%d", &(date->annee));
    }while ( date->annee < 2024 );
    printf("\n");


    printf("En quelle mois est votre rdv :"); // assignation pour le mois
    do{
        scanf("%d", &(date->mois));
    }while ( date->mois < 0 || date->mois > 12 );
    printf("\n");


    int max;
    if ( date->mois == 1 || date->mois == 3 || date->mois == 5 || date->mois == 7 || date->mois == 8 || date->mois == 10 || date->mois == 12){
        max = 31;
    }
    else if ( date->mois == 2){
        max = 29;
    }
    printf("Quelle jour est votre rdv :");
    while ( date->jour < 0 || date->jour > max){
        scanf("%d", &(date->jour));
    }



    return;
}



RDV_HORAIRE * empty_horaire(){
    RDV_HORAIRE * horaire = malloc(sizeof(RDV_HORAIRE));
    return horaire;
}

void saisir_horaire(RDV_HORAIRE * horaire){
    horaire = empty_horaire();

    printf("A quelle heure est votre rdv :"); // assignation pour l'heure
    do{
        scanf("%d", &(horaire->heure));
    }while ( horaire->heure < 0 || horaire->heure > 23 );
    printf("\n");

    printf("A quelle minute precise est votre rdv :"); // assignation pour les minutes
    do{
        scanf("%d", &(horaire->minutes));
    }while ( horaire->minutes < 0 || horaire->heure > 59 );
    printf("\n");
}


RDV_DUREE * empty_duree(){
    RDV_DUREE * duree = malloc(sizeof(RDV_DUREE));
    return duree;
}

void saisir_duree(RDV_DUREE * duree){
    duree = empty_duree();

    printf("A quelle heure est votre rdv :"); // assignation pour l'heure
    do{
        scanf("%d", &(duree->heure));
    }while ( duree->heure < 0 || duree->heure > 23 );
    printf("\n");

    printf("A quelle minute precise est votre rdv :"); // assignation pour les minutes
    do{
        scanf("%d", &(duree->minutes));
    }while ( duree->minutes < 0 || duree->heure > 59 );
    printf("\n");
}


char* scanstring(void){
    char *chaine = malloc(sizeof(char)*30);
    fgets(chaine,30,stdin);
    int cpt = 0;
    while(chaine[cpt]!='\n'){
        cpt++;
    }
    chaine[cpt+1] = chaine[cpt+2];
    size_t length = strcspn(chaine, "\n");
    if (chaine[length] == '\n') {
        chaine[length] = '\0';
    }

    return chaine;
}

RDV_OBJET * empty_objet(){
    RDV_OBJET * objet = malloc(sizeof(RDV_OBJET));
    objet->contenu = NULL;

    return objet;
}

void saisir_objet(RDV_OBJET * objet){
    printf("Ecrivez la raison de votre rdv : ");
    objet->contenu = scanstring();
}


void display_contact(CONTACT contact){
    //printf("")
}
