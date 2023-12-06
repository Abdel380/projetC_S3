#include "agenda.h"

Agenda empty_agenda(){
    Agenda agenda;
    agenda.contact_heads = malloc(sizeof(Agenda)*4); // we allocate the memory we need to store the contacts
    for(int i = 0;i<4;i++){
        *(agenda.contact_heads+i) = NULL; // we allocate the memory for each levels
    }
    return agenda;
}

void insert_contact(Agenda* agenda,p_Contact contact){
    p_Contact temp = agenda->contact_heads[0]; // Initialisation du premier contact
    p_Contact prev = temp;


    if (temp == NULL){ // cas ou l'agenda est vide (aucun contact)
        for (int i=0; i<4; i++) // agenda is empty we fill the heads with the cells
            insert_by_level(agenda, contact, i, temp, 0);
    }
    else if (strcmp(contact->name, temp->name) < 0){ // Cas où il y'a faut il inserer directement à gauche
        int level_next;
        // On calcule le niveau de la cellule suivante après cette insertion
        if (temp->name[0] != contact->name[0]){
            level_next = 3;
        }
        else if (temp->name[0] == contact->name[0] && temp->name[1] != contact->name[1]){
            level_next = 2;
        }
        else if (temp->name[0] == contact->name[0] && temp->name[1] == contact->name[1] && temp->name[2] != contact->name[2]){
            level_next = 1;
        }
        else {
            level_next = 0;
        }
        for (int i=0; i<4; i++) // we insert the contact at all levels we need
            insert_by_level(agenda, contact, i, temp, level_next);
    }
    else{ // Cas ou : - la liste n'est ni vide,  - ni besoin d'inseret directement au debut.
        int level_next;
        while (strcmp(contact->name, temp->name) > 0 && temp->nexts[0] != NULL){ // determine in what place we have to insert the contact
            prev = temp;
            temp = temp->nexts[0];
        }
        // Case where next->next = NULL and contact > next
        if (strcmp(contact->name, temp->name) > 0 && temp->nexts[0] == NULL){
            prev = temp;
            temp = NULL;
            level_next = 0;
        }
        // for the next (not covered if we are at the end of the chain)
        if (temp != NULL){
            if (temp->name[0] != contact->name[0]){
                level_next = 3;
            }
            else if (temp->name[0] == contact->name[0] && temp->name[1] != contact->name[1]){
                level_next = 2;
            }
            else if (temp->name[0] == contact->name[0] && temp->name[1] == contact->name[1] && temp->name[2] != contact->name[2]){
                level_next = 1;
            }
            else {
                level_next = 0;
            }
        }

        // we determine with the prev in how many levels we insert the contact
        if (prev->name[0] != contact->name[0]){
            for(int i=3; i>=0; i--)
                insert_by_level(agenda, contact, i, temp,  level_next);
        }
        else if (prev->name[0] == contact->name[0] && prev->name[1] != contact->name[1]){
            for (int i=2; i>=0; i--)
                insert_by_level(agenda, contact, i, temp, level_next);
        }
        else if (prev->name[0] == contact->name[0] && prev->name[1] == contact->name[1] && prev->name[2] != contact->name[2]){
            insert_by_level(agenda, contact, 0, temp, level_next);
            insert_by_level(agenda, contact, 1, temp, level_next);
        } else{
            insert_by_level(agenda, contact, 0, temp, level_next);
        }

    }
}
void insert_by_level(Agenda* agenda,p_Contact contact,int level, p_Contact temp, int level_next){
    p_Contact next = NULL;
    next = agenda->contact_heads[level];
    p_Contact prev = next;
    if ( agenda->contact_heads[level] == NULL){ // the head is empty
        agenda->contact_heads[level] = contact;
        contact->nexts[level] = NULL;
        return;
    }

    if ( agenda->contact_heads[level]->nexts[level] == NULL && strcmp(contact->name, next->name) > 0){ // if we have one cell and we have to insert it on the right
        agenda->contact_heads[level]->nexts[level] = contact;
        return;
    }

    if (strcmp(contact->name, next->name) < 0){  //we insert at the left
        contact->nexts[level] = agenda->contact_heads[level];
        agenda->contact_heads[level] = contact;
        if (level <= level_next){
            contact->nexts[level] = temp;
        }
        else{
            contact->nexts[level] = temp->nexts[level];
        }

        return;
    }

    while ( next->nexts[level] != NULL && strcmp(contact->name, next->name) > 0 ){ // Either next = Null or we find the location to insert the contact
        prev = next;
        next = next->nexts[level];
    }

    if ( next->nexts[level] == NULL && strcmp(contact->name, next->name) > 0){ // if we insert at the end
        next->nexts[level] = contact;
        contact->nexts[level] = NULL;
        return;
    }
    else if( next->nexts[level] == NULL && strcmp(contact->name, next->name) < 0){ // we insert before the last cell
        prev->nexts[level] = contact;
        if (level>level_next)
            contact->nexts[level] = NULL;
        else

            contact->nexts[level] = next;
        return;
    }

    // chaining for the nexts refer to the level next
    if (level <= level_next){
        prev->nexts[level] = contact;
        contact->nexts[level] = temp;
    }
    else{ // we point the prev on the contact , the contact on the nexts of temp and we put the pointers in the array of temp->next to null
        prev->nexts[level] = contact;
        contact->nexts[level] = temp->nexts[level];
        temp->nexts[level] = NULL;
        temp->level = level_next; // we put the level of temps to le
    }
}

void display_agenda_by_level(Agenda agenda, int level){
    level--; // By convention on the display of line 0 for level one
    printf("[list head_%d @-]", level);  // same structure that insert_cell in list
    p_Contact base = agenda.contact_heads[0];
    p_Contact cell = agenda.contact_heads[level];
    while (base != NULL){
        if (base == cell){
            printf("-->[%s|%d|@-]", cell->name, cell->level);
            cell = cell->nexts[level];
        }
        else{
            printf("----------");
        }
        base = base->nexts[0];
    }
    printf("-->NULL\n");
}

void display_agenda(Agenda agenda){ // display the next(s) level(s)
    for (int i=1; i<= 4; i++) {
        display_agenda_by_level(agenda, i);
    }
}


p_Contact research_contact(p_Contact head, char *nom, int level) {
    if (head == NULL ||strcmp(head->name, nom) > 0){
        return NULL;
    }

    if (strcmp(nom, head->name) == 0) {
        return head;
    }

    if (level == 3 && nom[0] > head->name[0]) {
        head = head->nexts[3];
        return research_contact(head, nom, level);
    }

    else if (level == 3 && nom[0] == head->name[0]) {
        return research_contact(head, nom, level - 1);
    }

    if (level == 2 && nom[1] != head->name[1]) {
        head = head->nexts[2];
        return research_contact(head, nom, level);
    }

    else if (level == 2 && nom[1] == head->name[1]) {
        return research_contact(head, nom, level - 1);
    }

    if (level == 1 && nom[2] != head->name[2]) {

        head = head->nexts[1];
        return research_contact(head, nom, level);
    }

    else if (level == 1 && nom[2] == head->name[2]) {
        return research_contact(head, nom, level - 1);
    }

    if (level == 0 && strcmp(head->name, nom) < 0) {
        head = head->nexts[0];
        return research_contact(head, nom, level);
    }


    return NULL;
}

void create_rdv_for_contact(Agenda *agenda) {
    char *nom = scan_name();

    // Contact search in agenda
    p_app app = create_app();
    p_Contact tmp = research_contact(agenda->contact_heads[3], nom, 3);
    if (tmp == NULL) {
        // If the contact does not exist, create a new contact
        p_Contact contact = empty_contact();


        contact->name =  nom;


        insert_contact(agenda, contact);

        insert_app(app, contact);

        // Insert the new contact in the agenda

    } else {

        // If the contact exists, insert the appointment

        insert_app(app, tmp);

    }

}

void load_appointment_from_file(Agenda * agenda){
    FILE * appointment_file = fopen("../appointement.csv","r"); // we open the file
    char * temp=  (char *)malloc(100 * sizeof(char));
    int j = 0;
    char * app_char = (char *)malloc(150 * sizeof(char));
    int k =0;
    unsigned int l,i;
    char * name;
    char lign[100];  // We make sure that the size is sufficient
    while (fgets(lign, sizeof(lign), appointment_file) != NULL) {
        if(strcmp(lign,"nom_contact,objet_rdv,date_rdv,heure_rdv,duree_rdv\n")!=0){ // if the lign different from this string
            j=0;
            name = get_name_from_lign(lign);     //we get the first name and surname
            i = strlen(name);

            p_Contact contact = empty_contact();
            while(lign[i]!='~'){  //while we aren't at the end of the lign
                if(lign[i] == '['){
                    k = 0;
                    l = i+1; // we go to the next character after [

                    while(lign[l]!=']'){ //to the next appointment
                        app_char[k] = lign[l]; //we take what's inside []
                        k++;
                        l++;

                    }
                    app_char[k]='\0';

                    p_app app  = get_appointment_characteristics(app_char, name); //we separate the differents characteristics of an appointment and create one
                    contact->name =name;
                    insert_app(app, contact);


                }

                ++i;
            }

            insert_contact(agenda,contact);


        }



    }

    fclose(appointment_file);// close the file
    free(temp);
    free(app_char);


}


void load_contact_from_file(Agenda * agenda){
    FILE * first_name_file = fopen("../nat2021.csv","r");
    char * first_name = malloc(30 * sizeof(char));
    char* surname = malloc(30 * sizeof(char));
    char lign[100];
    char * surname_name = malloc(60 * sizeof(char));
    int cpt = 0;


    while (fgets(lign, sizeof(lign), first_name_file) != NULL){
        strcpy(first_name, strtok(lign, " "));
        strcpy(surname, strtok(NULL, ""));


        strcpy(surname_name, surname);
        strcat(surname_name, "_"); // add _ at the end of the surname
        strcat(surname_name, first_name);

        convert_maj_min(surname_name);
        p_Contact contact = empty_contact();
        contact->name = strdup(surname_name); // create a copy


        insert_contact(agenda,contact);






    }
    fclose(first_name_file);
}

