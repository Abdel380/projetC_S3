#include "rdv.h"
#include "stdlib.h"
#include <string.h>
#include <ctype.h>


void cleanInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

char* scanstring() {
    char *chaine = malloc(sizeof(char)*100);
    fgets(chaine, 100, stdin);
    return chaine;
}

char * scan_name() {
    char *prenom_nom,*nom_prenom,*prenom,*nom;

    nom_prenom = malloc(60 * sizeof(char)); // Taille suffisante pour stocker le nom et le prénom
    do {

        printf("Entrez votre nom et prenom (format Prenom Nom): ");
        prenom_nom = scanstring();


        prenom = strtok(prenom_nom, " ");
        nom = strtok(NULL, " ");


        if (prenom == NULL || nom == NULL) {
            printf("Erreur : Format incorrect. Veuillez réessayer.\n");
        }else {
            // Construisez le nom_prenom seulement si les deux parties sont non nulles
            strcpy(nom_prenom, nom);
            strcat(nom_prenom, "_");
            strcat(nom_prenom, prenom);
            convert_maj_min(nom_prenom);
        }
    }while (prenom == NULL || nom == NULL);
    return nom_prenom;
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

int compareDate(DATE date1, DATE date2){
    if(date1.annee>date2.annee){
        return 1;
    }
    else if(date1.annee == date2.annee ){
        if(date1.mois >date2.mois){
            return 1;
        }
        else if(date1.mois == date2.mois){
            if(date1.jour>date2.jour){
                return 1;
            }
        }
    }
    return 0;
}

int compareTime(RDV_HORAIRE time1,RDV_HORAIRE time2){
    if(time1.heure>time2.heure){
        return 1;
    }
    else if(time1.heure == time2.heure){
        if(time1.minutes>time2.minutes){
            return 1;
        }
    }
    return 0;
}


//Fonctions pours les contacts


p_CONTACT empty_contact(){
    p_CONTACT contact = malloc(sizeof(t_CONTACT));
    contact->nom = NULL;
    contact->rdv_head = NULL;
    contact -> level = 0;
    contact->nexts = malloc(sizeof(t_CONTACT)*4);
    for (int i=0; i<4; i++){
        *(contact->nexts+i) = NULL;
    }
    return contact;
}

p_CONTACT create_contact(){
    p_CONTACT contact = empty_contact();
    contact->nom = scan_name();
    return contact;
}


void display_contact(t_CONTACT contact){
    printf("%s\n", contact.nom);
    display_rdv(contact.rdv_head);
}

/* FONCTION DATE */




RDV_DUREE  empty_duree(){
    RDV_DUREE * duree = malloc(sizeof(RDV_DUREE));
    return *duree;
}



RDV_OBJET empty_objet(){
    RDV_OBJET * objet = malloc(sizeof(RDV_OBJET));
    objet->contenu = malloc(sizeof(char)*100);

    return *objet;
}

DATE empty_date(){
    DATE * date = malloc(sizeof(DATE));
    return *date;
}
RDV_HORAIRE empty_horaire(){
    RDV_HORAIRE * horaire = malloc(sizeof(RDV_HORAIRE));
    return *horaire;
}

p_RDV empty_rdv(){
    p_RDV rdv = malloc(sizeof(t_RDV));

    rdv->duree = empty_duree();
    rdv->d = empty_date();
    rdv->horaire = empty_horaire();
    rdv->objet = empty_objet();


    return rdv;
}

DATE create_date(){
    DATE date = empty_date();
    do{
        printf("Quelle est la date de votre rendez vous (format jj/mm/aaaa)"); // assignation pour l'annee
        scanf("%d/%d/%d", &(date.jour), &(date.mois), &(date.annee));
    }while (date.annee < 2024 || ( date.mois <= 0 || date.mois > 12 ) || (date.jour <= 0) || ((date.mois == 1 || date.mois == 3 || date.mois == 5 || date.mois == 7 || date.mois == 8 || date.mois == 10 || date.mois == 12) && (date.jour > 31)) || ((date.mois == 4 || date.mois == 6 || date.mois == 9 || date.mois == 11) && (date.jour > 30)) || ((date.mois == 2) && (date.jour > 28)));
    return date;
}


RDV_OBJET create_objet(){
    RDV_OBJET objet = empty_objet();

    printf("Ecrivez la raison de votre rdv :");
    char* phrase = malloc(sizeof(char) * 100);
    objet.contenu = scanstring();

    return objet;
}

RDV_HORAIRE create_horaire(){

    RDV_HORAIRE horaire = empty_horaire();
    do{
        printf("A quelle heure est votre rdv (hh:mm) :"); // assignation pour l'heure
        scanf("%d:%d", &(horaire.heure),&(horaire.minutes));
    }while ( horaire.heure < 0 || horaire.heure > 23 || horaire.minutes < 0 || horaire.heure > 59);


    return  horaire;

}

RDV_DUREE  create_duree(){

    RDV_DUREE  duree = empty_duree();

    do{
        printf("Combien de temps dure votre rendez vous (hh:mm):");
        scanf("%d:%d", &(duree.heure), &(duree.minutes));
    }while ( duree.heure < 0 || duree.heure > 23 ||  duree.minutes < 0 || duree.heure > 59 );


    return duree;
}


p_RDV create_rdv(){
    p_RDV rdv = empty_rdv();


    rdv->objet = create_objet();
    rdv->d = create_date();
    rdv->horaire = create_horaire();
    rdv->duree = create_duree();
    cleanInputBuffer();


    return rdv;

}



void Insert_rdv(p_RDV rdv,p_CONTACT contact){
    if(contact->rdv_head == NULL){
        contact->rdv_head = rdv;
    }
    else{
        p_RDV temp = contact->rdv_head;
        while(compareDate(rdv->d,temp->d)>0 && temp!=NULL){
            temp = temp->next;
        }
        while(compareTime(rdv->horaire,temp->horaire)>0 && temp!=NULL){
            temp = temp->next;
        }
        if(temp == NULL){
            temp =rdv;
            temp->next = NULL;
            temp = temp->next;
            free(temp);
        }
    }
}



void display_rdv(p_RDV rdv){
    display_date(rdv->d);
    printf("\n");
    display_horaire(rdv->horaire);
    printf("\n");
    display_duree(rdv->duree);
    printf("\n");
    display_objet(rdv->objet);
    return;
}
void display_Contact_rdv(t_CONTACT contact){
    while(contact.rdv_head!=NULL){
        display_rdv(contact.rdv_head);
        contact.rdv_head = contact.rdv_head->next;
    }
}


void display_objet(RDV_OBJET objet){
    printf("%s", objet.contenu);
    return;
}

void display_duree(RDV_DUREE duree){
    if ( duree.minutes < 10){
        printf("%dh0%d", duree.heure, duree.minutes);
    }
    else{
        printf("%dh%d", duree.heure, duree.minutes);
    }
    return;
}


void display_horaire(RDV_HORAIRE horaire){
    if ( horaire.minutes < 10){
        printf("%d:0%d", horaire.heure, horaire.minutes);
    }
    else{
        printf("%d:%d", horaire.heure, horaire.minutes);
    }
    return;
}

void display_date(DATE date){
    printf("%d/%d/%d", date.jour, date.mois, date.annee);
    return;
}