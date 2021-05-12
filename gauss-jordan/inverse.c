// program for inverse of a matrix using gauss jordan method.
#include<stdio.h>
#include<math.h>

int main()
{
    int i,j,k,n;
    float a[10][10]={0},temp;
    printf("Enter order of matrix:");
    scanf("%d",&n);
    printf("Enter the elements of Matrix:\n");
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            printf("A[%d][%d]:",i,j);
            scanf("%f",&a[i][j]);
        }
    }
    //displaying the augmented Matrix
    printf("\nThe augmented matrix:\n");
    for (i=1;i<=n;i++){
        for (j=1;j<=2*n;j++){
            if (j==(i+n))
                a[i][j]=1;
            printf("%.2f\t",a[i][j]);
        }
        printf("\n");
    }
    //partial pivoting
    for (i=n;i>1;i--) {
        if (a[i-1][1]<a[i][1])
            //Swap the rows in the matrix
            for (j=1;j<=2*n;j++)
            {
                temp=a[i][j];
                a[i][j]=a[i-1][j];
                a[i-1][j]=temp;
            }
    }
    //Begin the Gauss Jordan
    for (i=1;i<=n;i++) {
        for (j=1;j<=2*n;j++)
            if (j!=i) {   
                temp=a[j][i]/a[i][i];
                for (k=1;k<=2*n;k++)
                    a[j][k]=a[j][k]-temp*a[i][k];
            }
    }
    // checking if the Ann value is 0 or nan(not a number)
    if (a[n][n]==0 || isnan(a[n][n])) {
        printf("\nSorry! Inverse matrix doesn't exist.");
    }
    else{
        //reducing to unit matrix
        for (i=1;i<=n;i++) {
            temp=a[i][i];
            for (j=1;j<=2*n;j++)
                a[i][j]=a[i][j]/temp;
        }
        //displaying Inverse Matrix
        printf("\nUsing Gauss Jordan Inverse of matrix:\n");
        for(i=1;i<=n;i++) {
            for(j=n+1;j<=2*n;j++) {
                printf("%0.3f\t",a[i][j]);
            }
        printf("\n");
        }
    }
}