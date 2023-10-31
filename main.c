#include <stdio.h>
#include "list.h"
int main() {
    p_cell cell = createCell(11,4);
    p_cell cell2 = createCell(10,2);
    p_cell cell3 = createCell(9,5);
    p_cell cell4 = createCell(8,1);
    t_list lst = create_empty_list(5);
    add_head_list(&lst,cell);
    add_head_list(&lst,cell3);
    add_head_list(&lst,cell4);
    insert_cell(&lst,cell2);
    //printf("%d", get_size_list(lst))
    display_list(lst);
    return 0;
}