#include "fonctions.h"


p_CONTACT empty_contact(){
    p_CONTACT contact = malloc(sizeof(t_CONTACT));
    contact->nom = NULL;
    p_RDV rdv = NULL;
    contact->nexts = malloc(sizeof(t_CONTACT)*4);
    for (int i=0; i<4; i++){
        *(contact->nexts+i) = NULL;
    }
    return contact;
}

char * scan_name(){
    printf("Entrez votre nom et prenom (format Prenom Nom):");
    char * prenom_nom = scanstring();
    int i=0,j=0;
    char * prenom = malloc(sizeof(char)*20);
    char * nom_prenom = malloc(sizeof(char)*40);
    while (prenom_nom[i] != ' '){ // stocke le prenom
        prenom[i] = prenom_nom[i];
        i++;
    }
    i++;

    while (prenom_nom[i] != '\0'){ // mets le nom au debut
        nom_prenom[j] = prenom_nom[i];
        i++;
        j++;
    }
    nom_prenom[j] = '_';

    j++;
    i=0;
    while (prenom[i]!='\0'){ // rajoute le prenom a la fin
        nom_prenom[j] = prenom[i];
        j++;
        i++;
    }
    convert_maj_min(nom_prenom);
    return nom_prenom;
}

void saisir_contact(p_CONTACT contact){

    contact->nom = scan_name();


    return;
}

void display_contact(t_CONTACT contact){
    printf("%s\n", contact.nom);
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

p_RDV empty_rdv(){
    p_RDV rdv = malloc(sizeof(t_RDV));

    rdv->duree = empty_duree();
    rdv->d = empty_date();
    rdv->horaire = empty_horaire();
    rdv->objet = empty_objet();

    return rdv;
}

void saisir_rdv(p_RDV rdv){

    saisir_date(rdv->d);
    saisir_objet(rdv->objet);
    saisir_duree(rdv->duree);
    saisir_horaire(rdv->horaire);

    return;

}


void display_rdv(t_RDV rdv){

    display_date(*rdv.d);

    display_horaire(*rdv.horaire);

    display_duree(*rdv.duree);

    display_objet(*rdv.objet);

    return;

}