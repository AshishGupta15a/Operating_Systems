//Page Replacement Algorithms
#include<stdio.h>
int main()
{
    int referenceString[20];
    int pageFaults=0,i,n,s,pages,frames;
    int hit;
    float hit_ratio,fault_ratio;
    printf("Enter the number of pages:");
    scanf("%d",&pages);
    printf("Enter the reference string values\n");
    for(i=0;i<pages;i++)
    {
        printf("Values Number.[%d]:\t",i+1);
        scanf("%d",&referenceString[i]);
    }
    printf("\nTotal number of frames :\t");
    scanf("%d",&frames);
    int temp[frames];
    for(i=0;i<frames;i++)
    {
        temp[i]=-1;
    }
    for(i=0;i<pages;i++)
    {
        s=0;
        for(n=0;n<frames;n++)
        {
            if(referenceString[i]==temp[n])
            {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;
        if((pageFaults<=frames)&&(s==0))
        {
            temp[i]=referenceString[i];
        }
        else if(s==0)
        {
            temp[(pageFaults-1)%frames]=referenceString[i];
        }
        printf("\n");
        for(n=0;n<frames;n++)
        {
            if(temp[n]!=-1)
                printf("%d\t",temp[n]);
            else
                printf("-\t");
        }
    }
    printf("\n Total number of Pages Faults:%d",pageFaults);
    hit=pages-pageFaults;
    printf("\n The total number of pages that are hit :%d",hit);
    hit_ratio=(float) hit/pages *100;
    printf("\n the hit ratio is:\t%f%",hit_ratio);
    fault_ratio=(float) pageFaults/pages *100;
    printf("\n the faults ratio is:\t%f%",fault_ratio);
	return 0;
}
 
