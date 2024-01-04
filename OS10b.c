#include<stdio.h>
int absoluteValue(int); // Declaring function absoluteValue

void main()
{
    int queue[25],n,headposition,i,j,k,seek=0, maxrange,
    difference,temp,queue1[20],queue2[20],temp1=0,temp2=0;
    float averageSeekTime; 
    printf("Enter the maximum range of Disk: ");
    scanf("%d",&maxrange);
    printf("Enter the number of queue requests: ");
    scanf("%d",&n);
    printf("Enter the initial head position: ");
    scanf("%d",&headposition);
    printf("Enter the disk positions to be read(queue): ");
    for(i=1;i<=n;i++)   // Note that i varies from 1 to n instead of 0 to n-1
    {
        scanf("%d",&temp);  //Reading position value to a temporary variable

        if(temp>headposition)
        {
            queue1[temp1]=temp; //temp1 is the index variable of queue1[]
            temp1++; //incrementing temp1
        }
        else    //else if temp < current headposition,then push to array queue2[]
        {   
            queue2[temp2]=temp; //temp2 is the index variable of queue2[]
            temp2++;
        }
    }
    for(i=0;i<temp1-1;i++)  //SORTING array queue1[] in ascending order
    {
        for(j=i+1;j<temp1;j++)
        {
            if(queue1[i]>queue1[j])
            {
                temp=queue1[i];
                queue1[i]=queue1[j];
                queue1[j]=temp;
            }
        }
    }
    for(i=0;i<temp2-1;i++)  //SORTING array queue2[] in descending order
    {
        for(j=i+1;j<temp2;j++)
        {
            if(queue2[i]<queue2[j])
            {
                temp=queue2[i];
                queue2[i]=queue2[j];
                queue2[j]=temp;
            }
        }
    }    
    for(i=1,j=0;j<temp1;i++,j++) //Copying first array queue1[] into queue[]
    {
        queue[i]=queue1[j]; 
    }
    queue[i]=maxrange;
    for(i=temp1+2,j=0;j<temp2;i++,j++)  //Copying second array queue2[] after that first one is copied, into queue[]
    {
        queue[i]=queue2[j];
    }
    queue[i]=0;  //Setting queue[i] to 0. Because that is the innermost cylinder.
    queue[0]=headposition;
    // Calculating SEEK TIME. seek is initially set to 0 in the declaration part.
    for(j=0; j<=n; j++) //Loop starts from headposition. (ie. 0th index of queue) 
    {   
        difference = absoluteValue(queue[j+1]-queue[j]); // Finding the difference between next position and current position.
        seek = seek + difference; // Adding difference to the current seek time value
    }
    averageSeekTime = seek/(float)n;
    printf("Total Seek Time= %d\n", seek);
    printf("Average Seek Time= %f\n", averageSeekTime);
}
int absoluteValue(int x)  // Defining function absoluteValue
{
    if(x>0)
    {
        return x;
    }
    else
    {
        return x*-1;
    }
}
