// calculating Lagrange interpolated value
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

    float sum=0;
    for(i=0;i<n;i++){
        // initiating product part
        float prod=1;
        for(j=0;j<n;j++){
            if(j!=i)
            prod=prod*(x-X[j])/(X[i]-X[j]);
        }
        sum=sum+prod*Y[i];
    }
    printf("\nThe lagrange interpolated value at x=%.2f is %f",x,sum);

}