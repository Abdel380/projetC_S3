#include "menu.h"
#include <stdio.h>
#include <stdlib.h>




/*______________________________ MENU PART 1 ______________________________*/


void menu_partie3(Agenda * agenda){
    clearScreen();
    header();
    page_1(agenda);
}

void header(){
    printf("######################################################\n");
    printf("###################### Agenda ########################\n");
    printf("######################################################\n");
}

void page_1(Agenda * agenda){
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
        menu_partie3(agenda);
    } else if (strcmp("create", prompt) == 0){
        create(agenda);
        page_1(agenda);
    } else if (strcmp("display", prompt) == 0){
        display(*agenda);
        page_1(agenda);
    } else if (strcmp("add", prompt) == 0){
        add(agenda);
        page_1(agenda);
    } else if (strcmp("showAPP", prompt) == 0){
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
    else if(strcmp("delete",prompt) == 0){
        printf("What is the object of the appointment you want to delete ?\n");
        char * object = scanstring();
        char * name = scan_name();
        p_Contact contact = research_contact(agenda->contact_heads[3],name,3);

        if(contact != NULL){

            p_app temp = contact->app_head;
            while(temp!=NULL && strcmp(temp->object.content,object)!=0){
                temp = temp->next;
            }
            if(temp!= NULL){
                delete_appointment(contact,temp);
            }
            else{
                printf("Appointment doesn't exist !!\n");
            }

        }

        else{
            printf("Contact doesn't exist !!\n");
        }
        page_1(agenda);
    }
    else {
        printRed("Command not found\n");
        page_1(agenda);
    }
}

/*______________________________ FCTS ______________________________*/

void help(){
    printf("\nContact function :\n");
    printf("create  : New contact creation.\n");
    printf("display : Display of all contacts.\n");
    printf("search  : Display a contact if it exists.\n\n");

    printf("Appointment Functions :\n");
    printf("add   : Add a new appointment.\n");
    printf("showAPP: View all appointments of a contact.\n");
    printf("delete : Delete an appointment.\n\n");

    printf("File functions :\n");
    printf("load   : Load the information contained in the backup.txt file.\n");
    printf("save   : Save the information in the backup.txt file.\n");

    printf("\nclear: Clean the acceuil page.\n");
    printf("measurement : Measure calculation time for re-contact insertion.\n");
    printf("exit   : Exit.\n");
    printf("exitS   : Leave by saving.\n\n");
}

void create(Agenda * agenda){
    printBlue("Oh ! A new contact :\n");
    p_Contact contact1 = create_contact();
    insert_contact(agenda, contact1);
}

void display(Agenda agenda){
    printBlue("Contact display\n");
    display_agenda(agenda);
    printf("\n");
}
void add(Agenda * agenda){
    printBlue("Appointments being added :\n");
    create_rdv_for_contact(agenda);
    printBlue("Appointment added ! \n");
}

void showRDV(Agenda agenda){
    printBlue("What is the contact's first name ? \n");
    char * name = scan_name();
    p_Contact contact = research_contact(agenda.contact_heads[3], name, 3);
    if(contact != NULL){
        display_Contact_appointment(*contact);
        printf("\n");
        return;
    }
    printBlue("The contact doesn't exist !\n");
}

void load(Agenda* agenda){
    printBlue("loading...\n");
    load_appointment_from_file(agenda);
    printBlue("Your contacts appointments have been loaded");
}

void save(Agenda agenda){
    printf("Saving...\n");
    FILE * appointment_file = fopen("../appointement.csv","w");
    while(agenda.contact_heads[0] != NULL){
        save_appointment_to_file(agenda.contact_heads[0]);
        agenda.contact_heads[0] = agenda.contact_heads[0]->nexts[0];

    }
    fclose(appointment_file);
    printf("Your contacts appointment have been saved !\n");
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