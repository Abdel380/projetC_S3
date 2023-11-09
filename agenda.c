//
// Created by alex on 09/11/2023.
//

#include "agenda.h"

AGENDA empty_agenda(){
    AGENDA agenda;
    agenda.contact_head = malloc(sizeof(agenda)*4);
    for(int i = 0;i<4;i++){
        *(agenda.contact_head+i) = NULL;
    }
    return agenda;
}


