#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

void menu(AGENDA * agenda){
    clearScreen();
    header();
    page_1(agenda);
}

void header(){
    printf("######################################################\n");
    printf("###################### Agenda ########################\n");
    printf("######################################################\n");
}

void page_1(AGENDA * agenda){
    printBlue("\nEnter your prompt (help) :\n");
    printBlue(">>> ");
    char prompt[20];
    scanf("%s", prompt);
    cleanInputBuffer();
    if (strcmp("help", prompt) == 0){
        help();
        page_1(agenda);
    } else if (strcmp("clear", prompt) == 0){
        clearScreen();
        menu(agenda);
    } else if (strcmp("create", prompt) == 0){
        create(agenda);
        page_1(agenda);
    } else if (strcmp("display", prompt) == 0){
        display(*agenda);
        page_1(agenda);
    } else if (strcmp("add", prompt) == 0){
        add(agenda);
        page_1(agenda);
    } else if (strcmp("showRDV", prompt) == 0){
        showRDV(*agenda);
        printf("\n");
        page_1(agenda);
    }
    else if(strcmp("load",prompt)==0){
        load(agenda);
        printf("\n");
        page_1(agenda);
    }
    else if(strcmp("save",prompt) == 0){
        save(*agenda);
        printf("\n");
    }

    else {
        printRed("Commande not found\n");
        page_1(agenda);
    }
}

/*______________________________ FCTS ______________________________*/

void help(){
    printf("\nContact fonction :\n");
    printf("create  : Creation d'un nouveau contact.\n");
    printf("display : Affichage de tout les contact.\n");
    printf("search  : Afficher un contact s'il existe.\n\n");

    printf("Fonctions Rendez-Vous :\n");
    printf("add     : Ajouter un nouveau rendez vous.\n");
    printf("show : Afficher tout les rendez vous d'un contact.\n");
    printf("delete  : Supprimer un rendez vous.\n\n");

    printf("Fonctions Fichier :\n");
    printf("load    : Chargez les informations contenues dans le fichier sauvegarde.txt .\n");
    printf("save    : Sauvegardez les informations dans le fichiers sauvegarde.txt .\n");

    printf("\nclear : Nettoyer la page d'acceuil.\n");
    printf("mesure  : Mesurer le temp de calcul pour une insertion de nouveau contact.\n");
    printf("exit    : Quitter\n");
    printf("exitS   : Quitter en sauvgardant.\n\n");
}

void create(AGENDA * agenda){
    printBlue("Oh ! Un nouveau contact :\n");
    p_CONTACT contact1 = create_contact();
    insert_contact(agenda, contact1);
    printf("Eh op, c'est dans la boite !");
}

void display(AGENDA agenda){
    printBlue("Contact display\n");
    display_agenda(agenda);
    printf("\n");
}
void add(AGENDA * agenda){
    printBlue("Appointments being added :\n");
    create_rdv_for_contact(agenda);
    printBlue("Appointment added ! \n");
}

void showRDV(AGENDA agenda){
    printBlue("What is the contact's first name ? \n");
    char * name = scan_name();
    p_CONTACT contact = research_contact(agenda.contact_heads[3], name, 3);
    if(contact != NULL){
        display_Contact_rdv(*contact);
        printf("\n");
        return;
    }
    printBlue("The contact doesn't exist !\n");
}

void load(AGENDA* agenda){
    printBlue("loading...\n");
    load_appointment_from_file(agenda);
    printBlue("your contacts appointments have been loaded");
}

void save(AGENDA agenda){
    printf("saving...\n");
    FILE * appointment_file = fopen("../appointement.csv","w");
    while(agenda.contact_heads[0] != NULL){
        save_appointment_to_file(agenda.contact_heads[0]);
        agenda.contact_heads[0] = agenda.contact_heads[0]->nexts[0];

    }
    fclose(appointment_file);
    printf("your contacts appointment have been saved !\n");
}


/*______________________________ TOOLS ______________________________*/

// TOOLS
void clearScreen() {
#ifdef _WIN32
    system("cls");  // Utilise "cls" pour Windows
#elif defined(__unix__) || defined(__APPLE__) && defined(__MACH__)
    system("clear");  // Utilise "clear" pour Linux/Unix et macOS
#else
    // Code de secours pour d'autres systèmes d'exploitation non pris en charge
    printf("\033c");
#endif
}

void printRed(const char *text) {
    printf("\033[1;31m%s\033[0m", text);
}

void printBlue(const char *text) {
    printf("\033[1;34m%s\033[0m", text);
}