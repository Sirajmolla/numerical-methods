// calculating linear spline
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
    float b[n];

    printf("Input values of x:\n");
    for (i=0;i<n+1;++i)
        scanf("%f",&x[i]);
    printf("Input values of corresponding f(x):\n");
    for (i=0;i<n+1;++i)
        scanf("%f",&a[i]);

    for (j=0;j<=n-2;++j) {
        b[j]=(a[j+1]-a[j])/(x[j+1]-x[j]);
    }
    b[n-1]=(a[n]-a[n-1])/(x[n]-x[n-1]);
    // Step 7: printing the coefficients
    printf("i\tai\tbi\n");
    for (i=0;i<n;++i)
        printf("%d\t%.2f\t%.2f\n",i,a[i],b[i]);
}