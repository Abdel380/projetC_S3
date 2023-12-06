#ifndef PROJET_C_MENU_H
#define PROJET_C_MENU_H
#include "agenda.h"

void menu(Agenda * agenda);

void header();
void page_1(Agenda * agenda);
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
