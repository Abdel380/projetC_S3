#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

/*_________________________________________________________________________*/
/*______________________________ MENU PART ________________________________*/
/*_________________________________________________________________________*/
void menu(Agenda * agenda, t_list * lst){
    clearScreen();
    header();
    page(agenda, lst);
}

void header(){
    printf("╔════════════════════════════════════════════════════╗\n");
    printf("║                SKIP LIST PROJECT                   ║\n");
    printf("╚════════════════════════════════════════════════════╝\n");
}

void page(Agenda * agenda, t_list * lst){
    printBlue("1. Part 1 & 2\n"
              "2. Part 3\n"
              "3. Quit\n"
              "Which part of the project do you want to look at?\n>>> ");
    char* choice = scanstring();
    if (strcmp(choice,"1")==0){
        clearScreen();
        menu_part2(agenda, lst);
    } else if (strcmp(choice,"2")==0){
        clearScreen();
        menu_part3(agenda, lst);
    } else if (strcmp(choice,"3")==0){
        printRed("Bye ...\n");
        return;
    } else {
        printRed("Command not found\n");
        page(agenda, lst);
    }
}
/*_________________________________________________________________________*/
/*______________________________ MENU PART 3 ______________________________*/
/*_________________________________________________________________________*/
void menu_part2(Agenda * agenda, t_list * lst){
    clearScreen();
    header_part2();
    printBlue("What is the size of your base (2^n)? \n>>> ");
    int size;
    do{
        scanf("%d", &size);
    } while (size<1);
    cleanInputBuffer();
    *lst = create_list(size);
    page_2(agenda, lst);
}

void header_part2(){
    printf("╔════════════════════════════════════════════════════╗\n");
    printf("║                      PART 2                        ║\n");
    printf("╚════════════════════════════════════════════════════╝\n");
}


void page_2(Agenda * agenda, t_list * lst){
    printBlue("1. Redefine base size\n"
              "2. Display list\n"
              "3. Search a value\n"
              "4. Compare execution times\n"
              "5. Clear screen\n"
              "6. Go home\n"
              "7. Quit\n");
    printBlue("\nEnter your prompt (help) :\n");
    printBlue(">>> ");
    int choice;
    scanf("%d", &choice);
    cleanInputBuffer();
    if (choice == 1){
        printBlue("What is the size of your base (2^n)? \n>>> ");
        int size;
        scanf("%d", &size);
        *lst = create_list(size);
        page_2(agenda, lst);
    } else if (choice == 2) {
        printRed("\n\nLIST DISPLAY\n");
        display_list(*lst);
        printf("\n");
        page_2(agenda, lst);
    } else if (choice == 3){
        printBlue("What value are you looking for ?\n>>> ");
        int val;
        scanf("%d", &val);
        val = dichotomic_research(*lst, val);
        if (val == 1)
            printf("The sought-after value is present\n\n");
        else
            printf("The searched value is not present\n\n");
        page_2(agenda, lst);
    } else if (choice == 4){
        printBlue("How big would your list be?\n>>> ");
        int size;
        scanf("%d", &size);
        timer_listNumber(size);
    } else if (choice == 5){
        clearScreen();
        page_2(agenda, lst);
    } else if (choice == 6){
        clearScreen();
        menu(agenda, lst);
    } else if (choice == 7){
        return;
    } else {
        printRed("Command Not Found\n");
        page_2(agenda, lst);
    }
    cleanInputBuffer();
}

/*_________________________________________________________________________*/
/*______________________________ MENU PART 3 ______________________________*/
/*_________________________________________________________________________*/
void menu_part3(Agenda * agenda, t_list * lst){
    clearScreen();
    header();
    page_1(agenda, lst);
}

void header_agenda(){
    printf("╔════════════════════════════════════════════════════╗\n");
    printf("║                      Agenda                        ║\n");
    printf("╚════════════════════════════════════════════════════╝\n");
}

void page_1(Agenda * agenda, t_list * lst){
    printBlue("\nEnter your prompt (help) :\n");
    printBlue(">>> ");
    char prompt[20];
    scanf("%s", prompt);
    if (strcmp("help", prompt) == 0){
        help();
        page_1(agenda, lst);
    } else if (strcmp("clear", prompt) == 0){
        clearScreen();
        menu_part3(agenda, lst);
    } else if (strcmp("create", prompt) == 0){
        create(agenda);
        page_1(agenda, lst);
    } else if (strcmp("display", prompt) == 0){
        display(*agenda);
        page_1(agenda, lst);
    } else if (strcmp("add", prompt) == 0){
        add(agenda);
        page_1(agenda, lst);
    } else if (strcmp("showAPP", prompt) == 0){
        showRDV(*agenda);
        printf("\n");
        page_1(agenda, lst);
    }
    else if(strcmp("loadApp",prompt)==0){
        load(agenda);
        printf("\n");
        page_1(agenda,lst);
    }
    else if (strcmp("loadContact",prompt) == 0){
        load_contact_from_file(agenda);
        page_1(agenda,lst);
    }
    else if(strcmp("save",prompt) == 0){
        save(*agenda);
        page_1(agenda, lst);
    }
    else if (strcmp("back", prompt) == 0){
        clearScreen();
        menu(agenda, lst);
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
        page_1(agenda, lst);
    }
    else if(strcmp("exitS",prompt) == 0){
        save(*agenda);
        printf("Goodbye !\n");
        return;
    }
    else if (strcmp("exit", prompt) == 0){
        return;
    }
    else {
        printRed("Command not found\n");
        page_1(agenda, lst);
    }
}

/*______________________________ FCTS ______________________________*/

void help(){
    printf("\nContact function :\n");
    printf("create  : New contact creation.\n");
    printf("display : Display of all contacts.\n");
    printf("search  : Display a contact if it exists.\n\n");

    printf("Appointment Functions :\n");
    printf("add     : Add a new appointment.\n");
    printf("showAPP : View all appointments of a contact.\n");
    printf("delete  : Delete an appointment.\n\n");

    printf("File functions :\n");
    printf("load    : Load the information contained in the backup.txt file.\n");
    printf("save    : Save the information in the backup.txt file.\n");

    printf("\nclear   : Clean the acceuil page.\n");
    printf("back    : Back to main menu\n");
    printf("exit    : Exit.\n");
    printf("exitS   : Exit by saving.\n\n");
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