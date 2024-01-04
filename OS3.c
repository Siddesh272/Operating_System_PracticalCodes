#include <stdio.h> 
int main() 
{ 
	int n, r, i, j, k; 
	printf("Enter the no of processes:");
    scanf("%d",&n);//Indicates the Number of processes 
    printf("Enter the no of resorces:");
    scanf("%d",&r);//Indicates the Number of resources 
	int alloc[10][10] , max[10][10] , avail[3]; 
    printf("Enter the allocation matrix:\n");
    for(i=0;i<n;i++)
    {
       for(j=0;j<r;j++)
         {
            
            scanf("%d",&alloc[i][j]);
         }
    }
    printf("Enter the max matrix:\n");
    for(i=0;i<n;i++)
    {
       for(j=0;j<r;j++)
         {
           
            scanf("%d",&max[i][j]);
         }
    }
    printf("Enter the available matrix:\n");
    for(i=0;i<r;i++)
    {
     
      scanf("%d",&avail[i]);
    }
    int f[n], ans[n], ind = 0; 
	for (k = 0; k < n; k++) { 
		f[k] = 0; 
	} 
    printf("Need matrix is:\n");
	int need[n][r]; 
	for (i = 0; i < n; i++) { 
		for (j = 0; j < r; j++) 
		{
           need[i][j]=max[i][j]-alloc[i][j];
           printf("%d\t",need[i][j]);
         }
         printf("\n");	 
	} 
    int y = 0; 
	for (k = 0; k < 5; k++) { 
		for (i = 0; i < n; i++) { 
			if (f[i] == 0) { 
                int flag = 0; 
				for (j = 0; j < r; j++) { 
					if (need[i][j] > avail[j]){ 
						flag = 1; 
						break; 
					} 
				} 
                if (flag == 0) { 
					ans[ind++] = i; 
					for (y = 0; y < r; y++) 
						avail[y] += alloc[i][y]; 
					f[i] = 1; 
				} 
			} 
		} 
	} 
    printf("Th SAFE Sequence is as follows\n"); 
	for (i = 0; i < n - 1; i++) 
		printf(" P%d ->", ans[i]); 
	printf(" P%d", ans[n - 1]); 
    return (0); 
} 