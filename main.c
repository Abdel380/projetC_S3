#include "list.h"
#include "timer.h"
#include "time.h"
#include "menu.h"
#define MAXLINES 1000

int main() {
    t_list lst;
    Agenda agenda = empty_agenda();
    menu(&agenda, &lst);

    return 0;
}