#ifndef PROJET_C_MENU_H
#define PROJET_C_MENU_H
#include "agenda.h"
#include "list.h"


void menu(Agenda * agenda, t_list * lst);
void header();
void page(Agenda * agenda, t_list * lst);

void menu_part2(Agenda * agenda, t_list * lst);
void header_part2();
void page_2(Agenda * agenda, t_list * lst);




void menu_part3(Agenda * agenda, t_list * lst);

void header_agenda();
void page_1(Agenda * agenda, t_list * lst);
void help();


//FCTS
void create(Agenda * agenda);
void display(Agenda agenda);
void add(Agenda * agenda);
void showRDV(Agenda agenda);

// TOOLS
void clearScreen();
void printRed(const char *text);
void printBlue(const char *text);
void load(Agenda* agenda);
void save(Agenda agenda);


#endif //PROJET_C_MENU_H
