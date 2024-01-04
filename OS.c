/*Name: Siddesh Mishra
Roll No. : 06
SJF
experiment 1*/
#include<stdio.h>
int main()
{
    int P[10],AT[10],BT[10],WT[10],TT[10],Pt[10],e[10],n,pos,temp;
    int burst=0,cmpl_T,flag=0, tt = 0, min, d;
    float Avg_WT,Avg_TT,Total=0, stat = 0, swt = 0;
    printf("Enter number of the process\n");
    scanf("%d",&n);
    printf("Enter Arrival time and Burst time of the process\n");
    printf("P  AT BT\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d",i+1);
        scanf("%d%d",&AT[i],&BT[i]);
        P[i]=i+1;
    }
    burst=0;
    for (int i = 0; i <n; i++)
    {
        pos=i;
        for (int j = i+1; j <n; j++)
        {
            if(BT[j]<BT[pos])
              pos=j;
        }
        temp=BT[i];
        BT[i]=BT[pos];
        BT[pos]=temp;

        temp=P[i];
        P[i]=P[pos];
        P[pos]=temp;

        temp = AT[i];
        AT[i] = AT[pos];
        AT[pos] = temp;
    }
    Pt[0]=burst;  //calculating completion time
    for(int i=1,j=0;i<=n;i++,j++)
    {
        burst+=BT[j];
        Pt[i]=burst;    
    }
    burst=0;
    for(int i=0;i<n;i++)
        if(AT[i]!=0) {
        flag=1;
        break;
    }
    if(flag==1){
         min = AT[0];
    for (int i = 0; i < n; i++)
    {
        if (min > AT[i])
        {
            min = AT[i];
            d = i;
        }
    }
    tt = min;
    e[d] = tt + BT[d];
    tt = e[d];
    for (int i = 0; i < n; i++)
    {
        if (AT[i] != min)
        {
            e[i] = BT[i] + tt;
            tt = e[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        TT[i] = e[i] - AT[i];
        stat = stat + TT[i];
        WT[i] = TT[i] - BT[i];
        swt = swt + WT[i];
    }
    Avg_TT = stat / n;
    Avg_WT = swt / n;
    }
    else{
    for(int i=0;i<n;i++)   // Logic for calculating Waiting time
    {
        if(i==0)
            WT[i]=AT[i];
        else
            WT[i]=burst-AT[i];
        burst+=BT[i];
        Total+=WT[i];
    }
    Avg_WT=Total/n;
    cmpl_T=0;  // Logic for calculating Turn around time
    Total=0;
    for(int i=0;i<n;i++)
    {
        cmpl_T+=BT[i];
        TT[i]=cmpl_T-AT[i];
        Total+=TT[i];
    }
    Avg_TT=Total/n;
    }
    int i, j;
    int last = Pt[n];
    printf("\n\nGANTT CHART\n");
    printf(" ");  // printing top bar
    for(i=0; i<n; i++) {
        for(j=0; j<BT[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n|"); // middle position
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
    int minus = 0;   // printing waiting time
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
    printf("%d\n\n", last);
    printf("Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnaround-time(s)\n");
    for (i = 1; i <=n; i++)
    {
        for(int x=0;x<n;x++)
        {
            if(i==P[x]){
                printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", P[x], AT[x], BT[x], WT[x], TT[x]);
                break;}
        }
    }
    printf("Average waiting time is : %.2f\n",Avg_WT);
    printf("Average turn around time is : %.2f\n",Avg_TT);
    return 0;
}