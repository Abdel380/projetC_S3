//
// Created by alex on 24/10/2023.
//

#include "fonctions.h"

DATE* initialise_date(){
    DATE * date = malloc(sizeof(DATE));
    return date;
}

void saisir_date(DATE * date){
    date = initialise_date(); // alloue la memoire


    printf("En quelle annee est votre rdv :"); // assignation pour l'annee
    while ( date->annee < 2023 ){
        scanf("%d", &(date->annee));
    }
    printf("\n");


    printf("En quelle mois est votre rdv :"); // assignation pour le mois
    while ( date->mois < 0 || date->mois > 12 ){
        scanf("%d", &(date->mois));
    }
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

CONTACT * initialise_contact(){
    CONTACT * contact = malloc(sizeof(CONTACT));

    return contact;
}

void saisir_contact(CONTACT * contact){
    contact = initialise_contact();
    printf("Entrez votre nom :");
    scanf("%s", contact->nom);
    printf("\n");
    
}
