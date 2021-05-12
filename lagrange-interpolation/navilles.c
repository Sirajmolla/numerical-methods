// calculating Navilles interpolated value
#include<stdio.h>
#include<math.h>

int main()
{
    int n,i,j;
    printf("Input no of points:");
    scanf("%d",&n);

    float X[n],Y[n];
    printf("Input values of x:\n");
    for (i=0;i<n;++i)
        scanf("%f",&X[i]);
    printf("Input values of corresponding f(x):\n");
    for (i=0;i<n;++i)
        scanf("%f",&Y[i]);

    float x;
    printf("Input the x value at which you want to estimate y: ");
    scanf("%f",&x);

    double Q[n][n];
    // initialising null matrix
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            Q[i][j] = 0.0;
        }
        Q[i][0] = Y[i]; //setting first column as Y(or P0) values
    }
    for (i=1;i<n;i++){ //i=1 since first col is P0
        for (j=1;j<=i;j++){
            Q[i][j]=((x-X[i-j])*(Q[i][j-1])-(x-X[i])*(Q[i-1][j-1]))/(X[i]-X[i-j]);
        }
    }
    printf("\nThe navilles interpolated value at x=%.2f is %f",x,(Q[n-1][n-1]));

}