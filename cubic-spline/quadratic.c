// calculating quadratic spline
#include <stdio.h>
#include <math.h>
int main()
{
    // Step 0
    int n,i,j;
    printf("Input no of points:");
    scanf("%d",&n);
    n--;
    float x[n+1],a[n+1];
    float b[n],c[n];

    printf("Input values of x:\n");
    for (i=0;i<n+1;++i)
        scanf("%f",&x[i]);
    printf("Input values of corresponding f(x):\n");
    for (i=0;i<n+1;++i)
        scanf("%f",&a[i]);
    // Step 1
    b[0]=0; // applying natural condition
    for (j=0;j<=n-2;++j) {
        b[j+1]=-b[j]+2*((a[j+1]-a[j])/(x[j+1]-x[j]));
    }
    // Step 2
    for (j=0;j<=n-2;++j) {
        c[j]=((b[j+1]-b[j])/(2*(x[j+1]-x[j])));
    }
    c[n-1]=(a[n]-a[n-1])/(pow((x[n]-x[n-1]),2))-b[n-1]/(x[n]-x[n-1]);
    // Step 3: printing the coefficients
    printf("i\tai\tbi\tci\n");
    for (i=0;i<n;++i)
        printf("%d\t%.2f\t%.2f\t%.2f\n",i,a[i],b[i],c[i]);

}