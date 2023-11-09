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
    convert_maj_min(contact->prenom);

    printf("Quelle est votre nom :");
    contact->nom = scanstring();
    convert_maj_min(contact->nom);

    return;
}

void display_contact(CONTACT contact){
    printf("%s_%s\n", contact.nom, contact.prenom);
    return;
}

DATE* empty_date(){
    DATE * date = malloc(sizeof(DATE));
    return date;
}

void saisir_date(DATE * date){




    do{
        printf("En quelle annee est votre rdv :"); // assignation pour l'annee
        scanf("%d", &(date->annee));

    }while ( date->annee < 2024 );
    printf("\n");



    do{
        printf("En quelle mois est votre rdv :"); // assignation pour le mois
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

    do{
        printf("Quelle jour est votre rdv :");
        scanf("%d", &(date->jour));
    }while ( date->jour < 0 || date->jour > max);



    return;
}

void display_date(DATE date){
    printf("%d/%d/%d\n", date.jour, date.mois, date.annee);
    return;
}

RDV_HORAIRE * empty_horaire(){
    RDV_HORAIRE * horaire = malloc(sizeof(RDV_HORAIRE));
    return horaire;
}

void saisir_horaire(RDV_HORAIRE * horaire){


    do{
        printf("A quelle heure est votre rdv :"); // assignation pour l'heure
        scanf("%d", &(horaire->heure));
    }while ( horaire->heure < 0 || horaire->heure > 23 );



    do{
        printf("A quelle minute precise est votre rdv :"); // assignation pour les minutes
        scanf("%d", &(horaire->minutes));
    }while ( horaire->minutes < 0 || horaire->heure > 59 );

}

void display_horaire(RDV_HORAIRE horaire){
    if ( horaire.minutes < 10){
        printf("%d:0%d\n", horaire.heure, horaire.minutes);
    }
    else{
        printf("%d:%d\n", horaire.heure, horaire.minutes);
    }
    return;
}


RDV_DUREE * empty_duree(){
    RDV_DUREE * duree = malloc(sizeof(RDV_DUREE));
    return duree;
}

void saisir_duree(RDV_DUREE * duree){


    do{
        printf("A quelle heure est votre rdv :"); // assignation pour l'heure
        scanf("%d", &(duree->heure));
    }while ( duree->heure < 0 || duree->heure > 23 );



    do{
        printf("A quelle minute precise est votre rdv :"); // assignation pour les minutes
        scanf("%d", &(duree->minutes));
    }while ( duree->minutes < 0 || duree->heure > 59 );
    printf("\n");
}

void display_duree(RDV_DUREE duree){
    if ( duree.minutes < 10){
        printf("%d:0%d\n", duree.heure, duree.minutes);
    }
    else{
        printf("%d:%d\n", duree.heure, duree.minutes);
    }
    return;
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

    return;
}

void display_objet(RDV_OBJET objet){
    printf("%s\n", objet.contenu);
    return;
}

void convert_maj_min(char*chaine){
    int i=0;
    while(chaine[i] !='\0') {
        if ( chaine[i] >= 65 && chaine[i]<=90){
            chaine[i]+=32;
        }
        i++;
    }
    return;
}

RDV * empty_rdv(){
    RDV * rdv = malloc(sizeof(RDV));

    rdv->duree = empty_duree();
    rdv->d = empty_date();
    rdv->horaire = empty_horaire();
    rdv->objet = empty_objet();

    return rdv;
}

void saisir_rdv(RDV * rdv){

    saisir_date(rdv->d);
    saisir_objet(rdv->objet);
    saisir_duree(rdv->duree);
    saisir_horaire(rdv->horaire);

    return;

}


void display_rdv(RDV rdv){

    display_date(*rdv.d);

    display_horaire(*rdv.horaire);

    display_duree(*rdv.duree);

    display_objet(*rdv.objet);

}