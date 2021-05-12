// fit the datasets with error in a straight line
#include<stdio.h>
#include<math.h>

int main()
{
    int i,n=10; // no of points
    float x[]={1,2,3,4,5,6,7,8,9,10};
    float y[]={2.8,3.6,2.8,3.5,4.2,5.1,6.6,8.6,10.8,14.2};
    float sigma[]={0.3,0.5,0.55,0.6,0.65,0.7,0.75,0.9,1.1,1.3};

    FILE*fp=NULL;
    fp=fopen("linear.txt","w");

    // summing
    float weight,X=0,Y=0,XY=0,X2=0,w=0;
    for(i=0;i<n;i++)
    {
        weight=1/pow(sigma[i],2);
        X  += x[i]*weight;
        X2 += x[i]*x[i]*weight;
        Y  += y[i]*weight;
        XY += x[i]*y[i]*weight;
        w  += weight;
    }
    // expected values
    X  /= w;
    X2 /= w;
    Y  /= w;
    XY /= w;

    float a0,a1;   // unknowns to find
    a0=(Y*X2-X*XY)/(X2-X*X);
    a1=(XY-X*Y)/(X2-X*X);
    printf("The coefficients a0=%f\ta1=%f\n",a0,a1);
    // calculating the fitted points
    for (i=0;i<n;i++){ 
        y[i]=a0+a1*x[i];
        fprintf(fp,"%f\t%f\n",x[i],y[i]);
    }
}