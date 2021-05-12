// calculating natural cubic spline interpolated value
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
    float h[n],alpha[n],l[n+1],u[n+1],z[n+1],c[n+1],b[n],d[n];

    printf("Input values of x:\n");
    for (i=0;i<n+1;++i)
    	scanf("%f",&x[i]);
    printf("Input values of corresponding f(x):\n");
    for (i=0;i<n+1;++i)
    	scanf("%f",&a[i]);

    // Step 1
    for (i=0;i<=n-1;++i)
        h[i]=x[i+1]-x[i];
    // Step 2
    for (i=1;i<=n-1;++i)
        alpha[i]=3*(a[i+1]-a[i])/h[i]-3*(a[i]-a[i-1])/h[i-1];
    // Step 3
    l[0] = 1;
    u[0] = 0;
    z[0] = 0;
    // Step 4
    for (i=1;i<=n-1;++i) {
        l[i]=2*(x[i+1]-x[i-1])-h[i-1]*u[i-1];
        u[i]=h[i]/l[i];
        z[i]=(alpha[i]-h[i-1]*z[i-1])/l[i];
    }
    // Step 5
    l[n] = 1;
    z[n] = 0;
    c[n] = 0;
    // Step 6
    for (j=n-1;j>=0;--j) {
        c[j]=z[j]-u[j]*c[j+1];
        b[j]=(a[j+1]-a[j])/h[j]-h[j]*(c[j+1]+2*c[j])/3;
        d[j]=(c[j+1]-c[j])/(3*h[j]);
    }
    // Step 7: printing the coefficients
    printf("i\tai\tbi\tci\tdi\n");
    for (i=0;i<n;++i)
        printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\n",i,a[i],b[i],c[i],d[i]);
}