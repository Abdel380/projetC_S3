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
    size_t length = strlen(chaine);
    if (length > 0 && chaine[length - 1] == '\n') {
        // Remplacer le caractère de nouvelle ligne par le caractère nul
        chaine[length - 1] = '\0';
    }
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
    contact->level = 0;
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
    rdv->next = NULL;


    return rdv;
}

DATE create_date() {
    DATE date = empty_date();
    int result;

    do {
        printf("Quelle est la date de votre rendez-vous (format jj/mm/aaaa) : ");
        result = scanf("%d/%d/%d", &(date.jour), &(date.mois), &(date.annee));

        if (result != 3) {
            printf("Format incorrect. Veuillez utiliser jj/mm/aaaa.\n");
            // Vider le tampon d'entrée en cas d'une saisie incorrecte
            while (getchar() != '\n');
        }

    } while (date.annee < 2024 || (date.mois <= 0 || date.mois > 12) || (date.jour <= 0) ||
             ((date.mois == 1 || date.mois == 3 || date.mois == 5 || date.mois == 7 || date.mois == 8 || date.mois == 10 || date.mois == 12) && (date.jour > 31)) ||
             ((date.mois == 4 || date.mois == 6 || date.mois == 9 || date.mois == 11) && (date.jour > 30)) ||
             ((date.mois == 2) && (date.jour > 28)));

    return date;
}



RDV_OBJET create_objet(){
    RDV_OBJET objet = empty_objet();

    printf("Ecrivez la raison de votre rdv :");
    char* phrase = malloc(sizeof(char) * 100);
    objet.contenu = scanstring();

    return objet;
}
int check_output(char * output){

    int exit = 1;
    int i = 0;
    while(output[i] != '\0'){
        if ( output[i] == ':'){
            exit = 0;
        }
        i++;
    }

    return exit;
}



RDV_HORAIRE create_horaire(){

    RDV_HORAIRE horaire = empty_horaire();
    do{
        printf("A quelle heure est votre rdv (hh:mm) :"); // assignation pour l'heure
        int result = scanf("%d%*[:]%d", &(horaire.heure), &(horaire.minutes));

        // Vérifier si la saisie a été réussie correctement
        if (result != 2) {
            printf("Format incorrect. Veuillez utiliser hh:mm.\n");
            // Effacer le tampon d'entrée en cas d'une saisie incorrecte
            while (getchar() != '\n');
        }

    }while ( horaire.heure < 0 || horaire.heure > 23 || horaire.minutes < 0 || horaire.minutes > 59);

    return  horaire;
}


RDV_DUREE create_duree(){

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

void delete_appointment(p_CONTACT contact,p_RDV rdv){
    p_RDV temp = contact->rdv_head;
    p_RDV prev = NULL;

    if ( rdv == contact->rdv_head){
        contact->rdv_head = contact->rdv_head->next;
        return;
    }

    while(temp != rdv && temp!=NULL){
        prev = temp;
        temp = temp->next;
    }

    if(temp==NULL) { // le rdv existe pas
        printf("Le rendez-vous n'existe pas");
        return;

    }
    if(temp == rdv){ // le rdv existe mais n'est pas à la fin
        prev->next = temp->next;
        free(temp);
    }

    else{ // le rdv existe et est à la fin de la liste
        free(temp);
        prev->next = NULL;
    }
}



void Insert_rdv(p_RDV rdv, p_CONTACT contact) {
    if (contact->rdv_head == NULL || compareDate(rdv->d, contact->rdv_head->d) == 0) {
        // Insérer en tête de liste
        rdv->next = contact->rdv_head;
        contact->rdv_head = rdv;
        return;
    }

    p_RDV temp = contact->rdv_head;
    p_RDV prev = NULL;

    // Trouver l'endroit approprié pour insérer
    while (temp != NULL && compareDate(rdv->d, temp->d) == 1) {
        prev = temp;
        temp = temp->next;
    }

    // Comparer également l'heure si les dates sont égales
    while (temp != NULL && compareDate(rdv->d, temp->d) == 0 && compareTime(rdv->horaire, temp->horaire) == 1) {
        prev = temp;
        temp = temp->next;
    }

    // Insérer le rendez-vous
    if (prev != NULL) {
        prev->next = rdv;
    }

    rdv->next = temp;
}


int number_rdv(t_CONTACT contact){

    int number = 0;
    while (contact.rdv_head != NULL){
        contact.rdv_head = contact.rdv_head->next;
        number++;
    }

    return number;
}

void display_rdv(p_RDV rdv){
   display_date(rdv->d);
    printf("\n");
    display_horaire(rdv->horaire);
    printf("\n");
    display_duree(rdv->duree);
    printf("\n");
    display_objet(rdv->objet);
    printf("\n");
    return;
}

void display_Contact_rdv(t_CONTACT contact){
    while(contact.rdv_head !=NULL){

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


p_RDV search_rdv(char * objet, p_CONTACT contact){
    p_RDV temp = contact->rdv_head;

    while ( temp != NULL && strcmp(temp->objet.contenu,objet) != 0 ){
        temp = temp->next;
    }

    return temp;
}

void save_appointment_to_file(p_CONTACT contact){
    FILE * appointment_file = fopen("../appointement.csv","a");

    if(appointment_file == NULL){
        fprintf(stderr,"Not able to open the file.\n");
        return;
    }
    fseek(appointment_file, 0, SEEK_END);// on se déplace a la fin du fichier
    long file_size = ftell(appointment_file);  // Obtenir la taille du fichier

    // Si le fichier est vide, écrire l'en-tête
    if (file_size == 0) {
        fprintf(appointment_file, "nom_contact,objet_rdv,date_rdv,heure_rdv,duree_rdv\n");
    }


    p_RDV ap = contact->rdv_head;

    fprintf(appointment_file,"%s",contact->nom);
    while(ap!=NULL){
        fprintf(appointment_file,"[%s,%d/%d/%d,%d:%d,%d:%d]",ap->objet.contenu,ap->d.jour,ap->d.mois,ap->d.annee,ap->horaire.heure,ap->horaire.minutes, ap->duree.heure, ap->duree.minutes);
        ap = ap->next;
    }
    fprintf(appointment_file,"~");
    fprintf(appointment_file,"\n");
    fclose(appointment_file);
    printf("Les données ont bien été enregistrées\n");
}

char * get_name_from_lign(const char * lign ){

        int i = 0;
        char * nom =  (char *)malloc(50 * sizeof(char));

        while(lign[i] != '['){
            nom[i] = lign[i];
            ++i;
        }
        nom[i] = '\0';
        return nom;

}








p_RDV get_appointment_characteristics(char * app,char*nom){

    p_RDV rdv = empty_rdv();

    char **result = (char **)malloc(10 * sizeof(char*));




    splitToken(app,&result);

    strcpy(rdv->objet.contenu,result[0]);

    get_date_characteristics(result[1],rdv);

    get_hour_characteristics(result[2],rdv);

    get_time_characteristics(result[3],rdv);



    return rdv;

}

void splitToken(char *token, char ***result) {

    // Utilisation de strtok pour diviser le token en mots
    char *tokenCopy = strdup(token); // strtok modifie la chaîne, donc faisons une copie

    char *word = strtok(tokenCopy, ",");

    int i = 0;
    while (word != NULL && i < 4) {
        (*result)[i] = strdup(word);
        word = strtok(NULL, ",");
        i++;
    }

    free(tokenCopy);
}



void get_date_characteristics(char * date,p_RDV rdv){

    char * temp = date;
    temp= strtok(temp, "/");
    rdv->d.jour = atoi(temp);
    temp = strtok(NULL, "/");
    rdv->d.mois = atoi(temp);
    temp = strtok(NULL, "");
    rdv->d.annee = atoi(temp);


}


void get_hour_characteristics(char * hour, p_RDV rdv) {

    char * hour2 = hour;
    hour2 = strtok(hour, ":");
    rdv->horaire.heure = atoi(hour2);
    hour2 = strtok(NULL, "");
    rdv->horaire.minutes = atoi(hour2);

}
void get_time_characteristics(char * duree, p_RDV rdv){

    char * temp = duree;
    temp = strtok(duree, ":");
    rdv->duree.heure = atoi(temp);
    temp = strtok(NULL, "");
    rdv->duree.minutes = atoi(temp);

}

