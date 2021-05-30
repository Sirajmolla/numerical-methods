// calculating clamped cubic spline interpolated value
#include <stdio.h>
#include <math.h>
int main()
{
    // Step 0
    int n,i,j;
    printf("Input no of points:");
    scanf("%d",&n);
    n--;
    float x[n+1],a[n+1],F0,F1;
    float h[n],alpha[n+1],l[n+1],u[n+1],z[n+1],b[n],c[n+1],d[n];
    
    printf("Input values of x:\n");
    for (i=0;i<n+1;++i)
        scanf("%f",&x[i]);
    printf("Input values of corresponding f(x):\n");
    for (i=0;i<n+1;++i)
        scanf("%f",&a[i]);
    printf("Input clamped conditions:\n");
    scanf("%f%f",&F0,&F1);

    // Step 1
    for(j=0;j<n;j++){
        h[j]=x[j+1]-x[j];
    }
    // Step 2
    alpha[0]=(3*(a[1]-a[0])/h[0])-3*F0;
    alpha[n]=3*F1-3*(a[n]-a[n-1])/h[n-1];
    // Step 3
    for(i=1;i<n;i++){
        alpha[i]=((3/h[i])*(a[i+1]-a[i])-(3/h[i-1])*(a[i]-a[i-1]));
    }
    // Step 4
    l[0]=2*h[0];
    u[0]=0.5;
    z[0]=alpha[0]/l[0];
    // Step 5
    for(i=1;i<n;i++){
        l[i]=2*(x[i+1]-x[i-1])-h[i-1]*u[i-1];
        u[i]=h[i]/l[i];
        z[i]=(alpha[i]-h[i-1]*z[i-1])/l[i];
    }
    // Step 6
    l[n]=h[n-1]*(2-u[n-1]);
    z[n]=(alpha[n]-h[n-1]*z[n-1])/l[n];
    c[n]=z[n];
    // Step 7
    for(j=n-1;j>=0;j--){
        c[j]=z[j]-u[j]*c[j+1];
        b[j]=((a[j+1]-a[j])/h[j])-(h[j]*(c[j+1]+2*c[j])/3);
        d[j]=(c[j+1]-c[j])/(3*h[j]);
    }
    // Step 7: printing the coefficients
    printf("i\tai\tbi\tci\tdi\n");
    for (i=0;i<n+1;++i)
        printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\n",i,a[i],b[i],c[i],d[i]);
}