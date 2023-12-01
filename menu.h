#ifndef PROJET_C_MENU_H
#define PROJET_C_MENU_H
#include "agenda.h"

void menu(AGENDA * agenda);

void header();
void page_1(AGENDA * agenda);
void help();

//FCTS
void create(AGENDA * agenda);
void display(AGENDA agenda);
void add(AGENDA * agenda);
void showRDV(AGENDA agenda);

// TOOLS
void clearScreen();
void printRed(const char *text);
void printBlue(const char *text);
void load(AGENDA* agenda);
void save(AGENDA agenda);


#endif //PROJET_C_MENU_H
