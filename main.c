#include <stdio.h>
#include "list.h"
int main() {
    p_cell cell = createCell(11,3);
    p_cell cell2 = createCell(10,2);
    p_cell cell3 = createCell(8,1);
    p_cell cell4 = createCell(9,1);
    t_list lst = create_empty_list(5);
    add_head_list(&lst,cell);
    add_head_list(&lst,cell2);
    add_head_list(&lst,cell3);


    //insert_cell(&lst,cell4);

    display_list(lst);
    return 0;
}
