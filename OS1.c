/*Name : Siddesh Mishra
Roll no: 6
FCFS
experiment 1*/
#include<stdio.h>
int main()
{
    int P[10],AT[10],BT[10],WT[10],TT[10],Pt[10],n,pos,temp;
    int burst=0,cmpl_T;
    float Avg_WT,Avg_TT,Total=0;
    printf("Enter number of the process\n");
    scanf("%d",&n);
    printf("Enter Arrival time and Burst time of the process\n");
    printf("P  AT BT\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d",i+1);
        scanf(" %d %d",&AT[i],&BT[i]);
        P[i]=i+1;
    }
    Pt[0]=burst;
    for(int i=1,j=0;i<=n;i++,j++)
    {
        burst+=BT[j];
        Pt[i]=burst;
    }
    burst=0;    
    for(int i=0;i<n;i++) // Logic for calculating Waiting time
    {
        if(i==0)
            WT[i]=AT[i];
        else
            WT[i]=burst-AT[i];
        burst+=BT[i];
        Total+=WT[i];
    }
    Avg_WT=Total/n;
    cmpl_T=0; // Logic for calculating Turn around time
    Total=0;
    for(int i=0;i<n;i++)
    {
        cmpl_T+=BT[i];
        TT[i]=cmpl_T-AT[i];
        Total+=TT[i];
    }
    Avg_TT=Total/n;
         int i, j;
     int last = Pt[n];
    printf("\n\nGANTT CHART\n");
    printf(" ");  // printing top bar
    for(i=0; i<n; i++) {
        for(j=0; j<BT[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n|");  // middle position
    for(i=0; i<n; i++) {
        for(j=0; j<BT[i]-1; j++) printf(" ");
        printf("p%d", P[i]);
        for(j=0; j<BT[i]-1; j++) printf(" ");
        printf("|");
    }
    printf("\n "); // bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<BT[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n");
    int minus = 0;  // printing waiting time
    for(i=0; i<n; i++) {
        if(WT[i]>9) printf(" ");
        printf("%d", Pt[i]);
        if(WT[i+1]>9){
          minus = 1;
        }
        if(i+1 == n )  if (last>9) minus = 1;
        for(j=0; j<BT[i]-minus; j++) printf("  ");
    }
    if(last>9) printf(" ");
    printf("%d\n", last);
    printf("Process  Arrival-time(s)  Burst-time(s)  Waiting_time  TurnA_time\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,AT[i],BT[i],WT[i],TT[i]);
    }
    printf("Average waiting time is : %f\n",Avg_WT);
    printf("Average turn around time is : %f\n",Avg_TT);
    return 0;
}
