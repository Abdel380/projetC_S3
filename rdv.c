#include "rdv.h"
#include "stdlib.h"
#include <string.h>
#include <ctype.h>


/*---------------------- TOOLS FUNCTION ----------------------*/
void cleanInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

char* scanstring() {
    char *chaine = malloc(sizeof(char)*100);
    fgets(chaine, 100, stdin);
    size_t length = strlen(chaine);
    if (length > 0 && chaine[length - 1] == '\n') {
        // Replace newline character with null character
        chaine[length - 1] = '\0';
    }
    return chaine;
}

char * scan_name() {
    char *prenom_nom,*nom_prenom,*prenom,*nom;

    nom_prenom = malloc(60 * sizeof(char)); // Size sufficient to store the name and first name
    do {

        printf("Enter your name and surname (format Name Surname): ");
        prenom_nom = scanstring();


        prenom = strtok(prenom_nom, " ");
        nom = strtok(NULL, " ");


        if (prenom == NULL || nom == NULL) {
            printf("Error : Incorrect format . Try again please.\n");
        }else {
            // Construct lastname_firstname only if both parts are non-zero
            strcpy(nom_prenom, nom);
            strcat(nom_prenom, "_");
            strcat(nom_prenom, prenom);
            convert_maj_min(nom_prenom);
        }
    }while (prenom == NULL || nom == NULL);
    return nom_prenom;
}

void convert_maj_min(char * chaine){
    int i=0;
    while(chaine[i] !='\0') {
        if ( chaine[i] >= 65 && chaine[i]<=90){ // Ascii code addition
            chaine[i]+=32;
        }
        i++;
    }
    return;
}

int compareDate(date date1, date date2){
    if(date1.year > date2.year){ // first the year
        return 1;
    }
    else if(date1.year == date2.year ){ // years are equals we have to compare the month
        if(date1.month > date2.month){
            return 1;
        }
        else if(date1.month == date2.month){ // and then the days
            if(date1.day > date2.day){
                return 1;
            }
        }
    }
    return 0;
}

int compareTime(app_hour time1,app_hour time2){ // same structure that compareDate
    if(time1.hour>time2.hour){
        return 1;
    }
    else if(time1.hour == time2.hour){
        if(time1.minute > time2.minute){
            return 1;
        }
    }
    return 0;
}


/*---------------------- CONTACT FUNCTIONS ----------------------*/
p_Contact empty_contact(){
    p_Contact contact = malloc(sizeof(t_Contact));
    contact->name = NULL;
    contact->app_head = NULL;
    contact->level = 0;
    contact->nexts = malloc(sizeof(t_Contact)*4); // allocate the memory
    for (int i=0; i<4; i++){
        *(contact->nexts+i) = NULL;
    }
    return contact;
}

p_Contact create_contact(){
    p_Contact contact = empty_contact();
    contact->name = scan_name();
    return contact;
}


void display_contact(t_Contact contact){
    printf("%s\n", contact.name);
    display_app(contact.app_head);
}



/*---------------------- APPOINTEMENT FUNCTIONS ----------------------*/
/*--- DATE ---*/
app_time  empty_time(){
    app_time * duree = malloc(sizeof(app_time));
    return *duree;
}

app_object empty_object(){
    app_object * objet = malloc(sizeof(app_object));
    objet->content = malloc(sizeof(char) * 100);
    return *objet;
}

date empty_date(){
    date * date = malloc(sizeof(date));
    return *date;
}

app_hour empty_hour(){
    app_hour * horaire = malloc(sizeof(app_hour));
    return *horaire;
}

p_app empty_app(){
    p_app app = malloc(sizeof(t_app));

    app->time = empty_time();
    app->d = empty_date();
    app->hour = empty_hour();
    app->object = empty_object();
    app->next = NULL;
    return app;
}

date create_date() {
    date date = empty_date();
    int result;

    do {
        printf("What is the date of your appointment (dd/mm/yyyy format): ");
        result = scanf("%d/%d/%d", &(date.day), &(date.month), &(date.year));

        if (result != 3) {
            printf("Incorrect format. Please use dd/mm/yyyy.\n");
            // Vider le tampon d'entrée en cas d'une saisie incorrecte
            while (getchar() != '\n');
        }

    } while (date.year < 2024 || (date.month <= 0 || date.month > 12) || (date.day <= 0) ||
             ((date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12) && (date.day > 31)) ||
             ((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) && (date.day > 30)) ||
             ((date.month == 2) && (date.day > 28))); // all conditions are not possible

    return date;
}


/*--- OBJECT ---*/
app_object create_object(){
    app_object objet = empty_object();
    printf("Write the reason for your appointment:");
    char* phrase = malloc(sizeof(char) * 100); // allocate the memory
    objet.content = scanstring();
    return objet;
}

int check_output(char * output){ // check the output to secure the entry and verifiy the correct keyboard character ':'

    int exit = 1;
    int i = 0;
    while(output[i] != '\0'){
        if ( output[i] == ':'){ // if there is the keybord character ":" --> the conition is true
            exit = 0;
        }
        i++;
    }

    return exit;
}


app_hour create_hour(){
    app_hour horaire = empty_hour();
    do{
        printf("What hour is votre appointment (hh:mm) :"); // assignment for the hour
        int result = scanf("%d%*[:]%d", &(horaire.hour), &(horaire.minute));

        // Check if the entry was successful correctly
        if (result != 2) {
            printf("incorrect format. Please use  hh:mm.\n");
            // Clear input buffer in case of incorrect entry
            while (getchar() != '\n');
        }

    }while ( horaire.hour < 0 || horaire.hour > 23 || horaire.minute < 0 || horaire.minute > 59);

    return  horaire;
}


app_time create_time(){

    app_time  duree = empty_time();

    do{
        printf("How long does your appointment last (hh:mm):");
        scanf("%d:%d", &(duree.hour), &(duree.minute));
    }while ( duree.hour < 0 || duree.hour > 23 ||  duree.minute < 0 || duree.hour > 59 ); // all entries impossible


    return duree;
}


p_app create_app(){
    p_app app = empty_app();


    app->object = create_object();
    app->d = create_date();
    app->hour = create_hour();
    app->time = create_time();
    cleanInputBuffer();



    return app;

}

void delete_appointment(p_Contact contact, p_app rdv){
    p_app temp = contact->app_head;
    p_app prev = NULL;

    if ( rdv == contact->app_head){ //the appointment exists ans is at the first of the list
        contact->app_head = contact->app_head->next;
        return;
    }

    while(temp != rdv && temp!=NULL){
        prev = temp;
        temp = temp->next;
    }

    if(temp==NULL) { // The appointment does not exist
        printf("The appointment does not exist");
        return;

    }
    if(temp == rdv){ // the appointment exists but is not at the end
        prev->next = temp->next;
        free(temp);
    }

    else{ // the appointment exists and is at the end of the list
        free(temp);
        prev->next = NULL;
    }
}



void insert_app(p_app app, p_Contact contact) {
    if (contact->app_head == NULL || compareDate(app->d, contact->app_head->d) == 0) {
        // Insert at the head
        app->next = contact->app_head;
        contact->app_head = app;
        return;
    }

    p_app temp = contact->app_head;
    p_app prev = NULL;

    // Find the appropriate place to insert
    while (temp != NULL && compareDate(app->d, temp->d) == 1) {
        prev = temp;
        temp = temp->next;
    }

    // Also compare the hour if the dates are equal
    while (temp != NULL && compareDate(app->d, temp->d) == 0 && compareTime(app->hour, temp->hour) == 1) {
        prev = temp;
        temp = temp->next;
    }

    // Insert the appointment
    if (prev != NULL) {
        prev->next = app;
    }

    app->next = temp;
}


int number_appointment(t_Contact contact){ // calculate the number of appointment

    int number = 0;
    while (contact.app_head != NULL){
        contact.app_head = contact.app_head->next;
        number++;
    }

    return number;
}

void display_app(p_app rdv){
    display_date(rdv->d);
    printf("\n");
    display_hour(rdv->hour);
    printf("\n");
    display_time(rdv->time);
    printf("\n");
    display_object(rdv->object);
    printf("\n");
    return;
}

void display_Contact_appointment(t_Contact contact){
    while(contact.app_head != NULL){

        display_app(contact.app_head);
        contact.app_head = contact.app_head->next;

    }
}


void display_object(app_object objet){
    printf("%s", objet.content);
    return;
}

void display_time(app_time duree){
    // for display
    if ( duree.minute < 10){
        printf("%dh0%d", duree.hour, duree.minute);
    }
    else{
        printf("%dh%d", duree.hour, duree.minute);
    }
    return;
}


void display_hour(app_hour horaire){
    if (horaire.minute < 10){
        printf("%d:0%d", horaire.hour, horaire.minute);
    }
    else{
        printf("%d:%d", horaire.hour, horaire.minute);
    }
    return;
}

void display_date(date date){
    printf("%d/%d/%d", date.day, date.month, date.year);
    return;
}


p_app search_appointment(char * objet, p_Contact contact){
    p_app temp = contact->app_head;

    while ( temp != NULL && strcmp(temp->object.content, objet) != 0 ){
        temp = temp->next;
    }

    return temp;
}

void save_appointment_to_file(p_Contact contact){
    FILE * appointment_file = fopen("../appointement.csv","a");

    if(appointment_file == NULL){
        fprintf(stderr,"Not able to open the file.\n");
        return;
    }
    fseek(appointment_file, 0, SEEK_END);// we move at the end of the file
    long file_size = ftell(appointment_file);  // get the length of the file

    // If the file is empty, write the header
    if (file_size == 0) {
        fprintf(appointment_file, "nom_contact,objet_rdv,date_rdv,heure_rdv,duree_rdv\n");
    }


    p_app app = contact->app_head;

    fprintf(appointment_file,"%s",contact->name);
    while(app!=NULL){
        fprintf(appointment_file, "[%s,%d/%d/%d,%d:%d,%d:%d]", app->object.content, app->d.day, app->d.month, app->d.year, app->hour.hour, app->hour.minute, app->time.hour, app->time.minute);
        app = app->next;
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








p_app get_appointment_characteristics(char * app_char, char*nom){

    p_app app = empty_app();

    char **result = (char **)malloc(10 * sizeof(char*)); // create a table to store information




    splitToken(app_char,&result);

    //assigns the different information to the correct variables

    strcpy(app->object.content, result[0]);

    get_date_characteristics(result[1],app);

    get_hour_characteristics(result[2],app);

    get_time_characteristics(result[3],app);



    return app;

}

void splitToken(char *token, char ***result) {

    // Using strtok to split the token into words

    char *tokenCopy = strdup(token); // strtok modifies the string, so make a copy

    char *word = strtok(tokenCopy, ","); // Use strtok to extract the first word from the tokenCopy string, using the comma as the delimiter

    int i = 0;
    while (word != NULL && i < 4) { // Cycles through the words in the string as long as the return value remains and to avoid an array overflow
        (*result)[i] = strdup(word); // the word is duplicated with strdup and stored in the array pointed to by result
        word = strtok(NULL, ","); // strtok is called with NULL to get the next word.
        i++;
    }

    free(tokenCopy);
}



void get_date_characteristics(char * date, p_app rdv){

    char * temp = date;
    temp= strtok(temp, "/"); // using temp to put the right information in variables
    rdv->d.day = atoi(temp); // we convert ascii to int
    temp = strtok(NULL, "/");
    rdv->d.month = atoi(temp);
    temp = strtok(NULL, "");
    rdv->d.year = atoi(temp);


}


void get_hour_characteristics(char * hour, p_app rdv) { // same strcuture that get_date_characteristics

    char * hour2 = hour;
    hour2 = strtok(hour, ":");
    rdv->hour.hour = atoi(hour2);
    hour2 = strtok(NULL, "");
    rdv->hour.minute = atoi(hour2);

}
void get_time_characteristics(char * duree, p_app rdv){ // same strcuture that get_hour_characteristics

    char * temp = duree;
    temp = strtok(duree, ":");
    rdv->time.hour = atoi(temp);
    temp = strtok(NULL, "");
    rdv->time.minute = atoi(temp);

}

