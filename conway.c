    void read_array(char *arr,int row,int col)
    {
        int cell_alive, flag=0;

        while(!flag)
        {
            printf("\nHow many cells you want to be alive?");
            scanf("%d",&cell_alive);
            if (cell_alive < (row*col))
                flag = 1;
        }

         int positions_alive[cell_alive][2];

        for(int i=0; i<cell_alive;i++)
        {
            printf("\n\nEnter the row coordinate for cell no %d between 0-%d: ", i+1, row-1);
            scanf("%d", &positions_alive[i][0]);

            printf("\nEnter the column coordinate for cell no %d between 0-%d: ", i+1, col-1);
            scanf("%d", &positions_alive[i][1]);
        }

        for(int i=0; i<row;i++)
            for(int j=0;j<col;j++)
                *((arr+i*col)+j) = ' ';

        for(int i=0; i<cell_alive;i++)
            *((arr+positions_alive[i][0]*col)+positions_alive[i][1])='*';

    }

    void print_array(char *arr,int row,int col)
    {
        for(int i=0; i<row;i++)
        {
            for(int j=0;j<col;j++)
                printf("%c\t",*((arr+i*col)+j));
            printf("\n");
        }
    }

    void print_int_array(int *arr,int row,int col)
    {
        for(int i=0; i<row;i++)
        {
            for(int j=0;j<col;j++)
                printf("%d\t",*((arr+i*col)+j));
            printf("\n");
        }
    }

    void initialize_random(char *arr, int row, int col)
    {
        int value;

        for(int i=0; i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                value = rand()% 5;  //generate a random no. between 0 and 5
                if (value > 2)
                    *((arr+i*col)+j) = '*';
                else
                    *((arr+i*col)+j) = ' ';
            }
            printf("\n");
        }
    }

    void count_neighbours(char * arr, int * neighbour, int row, int col)
    {
        for (int i=0; i<row; i++)
            for(int j=0; j<col; j++)
        {
            int counter = 0;

            for (int r=i-1; r<=i+1; r++)
            {
                if ((r <0) || (r > row))
                    continue;
                for(int c=j-1; c<=j+1; c++)
                {
                    if ((c <0) || (c >= col))
                        continue;
                    if ((r == i) && (c == j))
                        continue;
                    if (*((arr+r*col)+c) == '*')
                        counter++;
                }
            *((neighbour+i*col)+j) = counter;
            }
        }
    }

 void next_tick(char * ptr_prev, char *ptr_next, int row, int col)
{
    int neighbour[row][col];
    int *ptr_neighbour = neighbour;

    count_neighbours(ptr_prev, ptr_neighbour, row, col);
   // print_int_array(ptr_neighbour, row, col);

    for (int i=0; i<row; i++)
            for(int j=0; j<col; j++)
            {
                if (*((ptr_prev+i*col)+j) == '*')
                    {
                        if ((neighbour[i][j] <2) || (neighbour[i][j] > 3))
                            *((ptr_next+i*col)+j) = ' ';
                        else
                            *((ptr_next+i*col)+j) = '*';
                    }
              else
              {
                  if ( (*((ptr_prev+i*col)+j) == ' ') && (neighbour[i][j] == 3))
                        *((ptr_next+i*col)+j) = '*';
                  else
                        *((ptr_next+i*col)+j) = ' ';
              }
            }
}

void swap(char * ptr_prev, char *ptr_next, int row, int col)
{
    char temp;

    for (int i=0; i<row; i++)
            for(int j=0; j<col; j++)
            {
                temp = *((ptr_next+i*col)+j);
                *((ptr_next+i*col)+j) = *((ptr_prev+i*col)+j);
                *((ptr_prev+i*col)+j) = temp;
            }

}

