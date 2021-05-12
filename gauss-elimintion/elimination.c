// solving linear system using gauss elimination
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
    for(i=0;i<n-1;i++) {
        // swapping rows if the diagonal is zero
        if (A[i][i]==0 ){
            for(k=i+1;k<n;k++) {
                if (A[k][i]!=0) {
                    for(j=0;j<=n;j++) {
                        float temp;
                        temp=A[i][j];
                        A[i][j]=A[k][j];
                        A[k][j]=temp;
                    }
                }
            }
        }
        //Begin the Gauss Elimination
        for(k=i+1;k<n;k++) {
            float term;
            term=A[k][i]/A[i][i];
            for(j=0;j<=n;j++)
                A[k][j]=A[k][j]-term*A[i][j];
        }        
    }
    printf("\nThe upper triangular matrix:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n+1;j++) {
            printf("%.2lf\t",A[i][j]);
        }
        printf("\n");
    }
    // condition for unique solution
    if (A[n-1][n-1]==0) {
        printf("\nSorry! No unique solution exists.");
    }
    else{
        //Start with the back-substitution
        for(i=n-1;i>=0;i--) {
            x[i]=A[i][n];
            for(j=i+1;j<n;j++) {
                x[i]=x[i]-A[i][j]*x[j];
            }
            x[i]=x[i]/A[i][i];
        } 
        printf("\nThe solution of linear equations:\n");
        for(i=0;i<n;i++)
            printf(" x[%d]= %.2lf\n",i+1,x[i]);
    }
}