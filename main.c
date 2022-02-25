#include <stdio.h>
#include <stdlib.h>
#include "conway.h"

int main()
{
    int length, width;
    char initial;

    printf("\nEnter the dimensions of borad.\nLength: ");
    scanf("%d",&length);
    printf("\nWidth: ");
    scanf("%d",&width);

    char grid_pre[length][width];
    char grid_next[length][width];

    char *ptr_grid_pre = grid_pre;
    char *ptr_grid_next = grid_pre;

    printf("\n\nDo you want to configure the initial board. If yes press Y.");
    initial = getch();

    if ((initial == 'Y')||(initial == 'y'))
        read_array(ptr_grid_pre, length, width);
    else
    {
        initialize_random(ptr_grid_pre, length, width);
        printf("\nBoard is initialized randomly\n");
    }

    print_array(ptr_grid_pre,length,width);
    getc(stdin);

    while((getc(stdin)!='q'))
    {
        next_tick(ptr_grid_pre, ptr_grid_next, length, width);
        print_array(ptr_grid_next,length,width);
        swap(ptr_grid_pre, ptr_grid_next,length,width);
    }

    return 0;
}
