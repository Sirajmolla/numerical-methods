// solving linear system using gauss ordan
#include<stdio.h>
#include<math.h>

int main()
{
    int i,j,k,n;
    printf("Enter the order of matrix:");
    scanf("%d",&n);
    float A[n][n+1],x[n];
    printf("Enter the elements of augmented matrix row-wise:\n");
    for(i=0;i<n;i++) {
        for(j=0; j<n+1;j++) {
            printf("A[%d][%d]:",i,j);
            scanf("%f",&A[i][j]);
        }
    }
    for(i=0;i<n;i++) {
        //Partial Pivoting
        for(k=i+1;k<n;k++) {
            //If the diagonal element (absolute value) is smaller than any of the terms below it
            if(fabs(A[i][i])<fabs(A[k][i])) {
                //Swap the rows in the matrix
                for(j=0;j<=n;j++) {                
                    float temp;
                    temp=A[i][j];
                    A[i][j]=A[k][j];
                    A[k][j]=temp;
                }
            }
        }
        //Begin the Gauss Jordan
        for (k=0;k<n;k++) {
            if (k!=i){   
                float term;
                term=A[k][i]/A[i][i];
                for (j=0;j<=n;j++)
                    A[k][j]=A[k][j]-term*A[i][j];
            }
        }        
    }
    // condition for unique solution
    if (A[n-1][n-1]==0) {
        printf("\nSorry! No unique solution exists.");
    }
    else{
        printf("\nThe diagonal augmented matrix:\n");
        for(i=0;i<n;i++){
            for(j=0;j<n+1;j++){
                printf("%.2f\t",A[i][j]);
            }
            printf("\n");
        }
        // getting the x array
        for (i=0;i<n;i++)
            x[i]=A[i][n]/A[i][i]; 
        printf("\nThe solution of linear equations:\n");
        for(i=0;i<n;i++)
            printf(" x[%d]= %.2f\n",i+1,x[i]);
 
    }
}