#include<stdio.h>
#include<stdlib.h>
int main()
{
    int RQ[100],i,initial;
    float n,TotalHeadMoment=0;
    printf("Enter the number of Requests\n");
    scanf("%f",&n);
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d",&initial);
    for(i=0;i<n;i++)
    {
        TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
        initial=RQ[i];
    }
    printf("Total head moment is %f",TotalHeadMoment);
    printf("\nTotal  average head moment is %f",TotalHeadMoment/n);
    return 0;
}
