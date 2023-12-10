#ifndef PROJET_C_RDV_H
#define PROJET_C_RDV_H
#include "stdlib.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

typedef struct{
    int day;
    int month;
    int year;
}date;

typedef struct{
    int hour;
    int minute;
}app_hour;

typedef struct{
    int hour;
    int minute;
}app_time;

typedef struct{
    char * content;
}app_object;

typedef struct s_App
{
    date d;
    app_hour hour;
    app_time time;
    app_object object;
    struct s_App * next; // tableau de pointeurs
} t_app, *p_app;


typedef struct s_Contact
{
    char * name;
    int level;
    p_app app_head; // tete de la liste
    struct s_Contact ** nexts ; // tableau de pointeur
} t_Contact, *p_Contact;

// TOOLS
char* scanstring();
int compareDate(date date1, date date2);
int compareTime(app_hour time1, app_hour time2);
void convert_maj_min(char * chaine);


//CONTACT
p_Contact empty_contact();
char* scan_name();
void cleanInputBuffer();

//APPOINTMENT CONTENT
date empty_date();
date create_date();
p_Contact create_contact();
app_hour empty_hour();
app_hour create_hour();
app_time empty_time();
app_time create_time();
app_object empty_object();
app_object create_object();
void insert_app(p_app app, p_Contact contact);
void delete_appointment(p_Contact contact, p_app rdv);
int number_appointment(t_Contact contact);


//DISPLAY
void display_contact(t_Contact);
void display_date(date);
void display_hour(app_hour);
void display_time(app_time);
void display_object(app_object);
void display_Contact_appointment(t_Contact contact);



//APPOINTMENT  &&  FILE EXPLORATION
p_app empty_app();
p_app create_app();
void display_app(p_app);
p_app search_appointment(char * objet, p_Contact contact);
void save_appointment_to_file(p_Contact contact);
char * get_name_from_lign(const char * );
p_app get_appointment_characteristics(char *, char * );
void get_date_characteristics(char *, p_app);
void get_hour_characteristics(char *, p_app);
void get_time_characteristics(char * , p_app);
void splitToken(char *token, char ***result);
int check_output(char *);

#endif //PROJET_C_RDV_H