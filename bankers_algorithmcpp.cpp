#include<stdio.h>
int main() 
{
    int p, c, count = 0, i, j, alc[5][3], Max[5][3], need[5][3], safe[5], ava[3], stop[5], end = 0;
    printf("Enter the number of process ");
    scanf("%d", &p);
    printf("Enter the number resources ");
    scanf("%d", & c);
    printf("enter allocation of resource of all process %dx%d matrix", p, c);
    for (i = 0; i < p; i++) 
    {
        for (j = 0; j < c; j++) 
        {
            scanf("%d", & alc[i][j]);
        }
    }
    printf("enter the Max resource process required %dx%d matrix", p, c);
    for (i = 0; i < p; i++) 
    {
        for (j = 0; j < c; j++) 
        {
            scanf("%d", & Max[i][j]);
        }
    }
    printf("enter the  ava resource");
    for (i = 0; i < c; i++)
        scanf("%d", & ava[i]);

    printf("\n need resources matrix are\n");
    for (i = 0; i < p; i++) 
    {
        for (j = 0; j < c; j++) 
        {
            need[i][j] = Max[i][j] - alc[i][j];
            printf("%d\t", need[i][j]);
        }
    printf("\n");
    }
    for (i = 0; i < p; i++) 
    {
        stop[i] = 0;
    }
    while (count < p) 
    {
        for (i = 0; i < p; i++) 
        {
            if (stop[i] == 0) 
            {
                for (j = 0; j < c; j++) 
                {
                    if (need[i][j] > ava[j])
                    break;
                }
                if (j == c) 
                {
                    safe[count] = i;
                    stop[i] = 1;
                    for (j = 0; j < c; j++) 
                    {
                        ava[j] += alc[i][j];
                    }
                    count++;
                    end = 0;
                } 
                else 
                {
                    end++;
                }
            }
        }
        if (end == (p - 1)) 
        {
            printf("safe sequence does not exist");
            break;
        }
    }
    if (end != (p - 1)) 
    {
        printf("\n ava resource after completion\n");
        for (i = 0; i < c; i++) 
        {
            printf("%d\t", ava[i]);
        }
        printf("\n safe sequence are\n");
        for (i = 0; i < p; i++) 
        {
            printf("p%d\t", safe[i]);
        }
    }
    return 0;
}
