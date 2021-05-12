#include<stdio.h>
#include<math.h>

void printmat(int n,float mat[n][n+1]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            printf("%.2f\t",mat[i][j]);
        }
        printf("\n");
    } 
}
//Gaussian Elimination
//Parameters: (n) no of eq/rows,mat[n][n+1],x[n]
void gausselim(int n,float A[n][n+1],float x[]){
    int i,j,k;
    for(i=0;i<n-1;i++){
        // swapping rows if the diagonal is zero
        if (A[i][i]==0){
            for(k=i+1;k<n;k++) {
                if (A[k][i]!=0){
                    for(j=0;j<=n;j++){
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
            for(j=0;j<=n;j++){
                A[k][j]=A[k][j]-term*A[i][j];
            }
        }        
    }
    printf("\nThe upper triangular matrix:\n");
    printmat(n,A);
    if (A[n-1][n-1]==0){
        printf("\nSorry! No unique solution exists.");
    }
    else{
        //Start with the back-substitution
        for(i=n-1;i>=0;i--){
            x[i]=A[i][n];
            for(j=i+1;j<n;j++){
                x[i]=x[i]-A[i][j]*x[j];
            }
            x[i]=x[i]/A[i][i];
        } 
        printf("\nThe coefficients of the polynomial:\n");
        for(i=0;i<n;i++){
            printf(" a[%d]= %.2f\n",i,x[i]);
        }
    }          
}

int main()
{
    int i,j,n=5;    // no of points
    float A[n][n+1],a[n];
    float x[5]={2,3,4,5,6};
    float y[5]={2,6,5,5,6};
    // setting matrix elements to zero
    for(i=0;i<n;i++) {
        for(j=0;j<n+1;j++) {
        A[i][j]=0;
        }
    }
    for(i=0;i<n;i++) {
       for(j=0;j<n+1;j++) {
        A[i][j]=pow(x[i],j);
        }   
    }
    for(i=0;i<n;i++)
        A[i][n]=y[i];

    for(i=0;i<n;i++) {
       for(j=0;j<n+1;j++) { 
           printf("%.2f\t",A[i][j]);
       }
       printf("\n");
    }
    // finding the coefficients
    gausselim(n,A,a);

    FILE*fp=NULL;
    fp=fopen("vandermonde.txt","w");
    // defining the polynomial
    float X;
    for (X=2;X<=6;X+=0.01) {
        float sum=0;
        for (i=0;i<n;++i)
            sum += a[i]*pow(X,i);
        fprintf(fp,"%lf\t%lf\n",X,sum);
    }
}