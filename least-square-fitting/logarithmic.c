// power law fitting in the form of y=a*x^b
#include<stdio.h>
#include<math.h>
// function to be fitted
float f(float a,float b,float x){
  return a*pow(x,b);
}
int main()
{
    int i,n=5; // no of points
    float x[]={1,2,3,4,5};
    float y[]={3.5,6.2,9.5,15.3,20.4};
    float sigma[]={0.3,0.5,0.55,0.6,0.65};
    // for expontial fitting
    for(i=0;i<n;i++) {
        x[i]=log(x[i]);
        y[i]=log(y[i]);
    }    
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
    a0=exp(a0); // converting back to original form
    printf("The coefficients a0=%f\ta1=%f\n",a0,a1);
    
    FILE*fp=NULL;
    fp=fopen("logarithmic.txt","w");
    // converting back to original form
    // for(i=0;i<n;i++) {
    //     x[i]=exp(x[i]);
    //     y[i]=exp(y[i]);
    // }
    //calculating the fitted points
    float x1;
    for(x1=1;x1<=5;x1+=0.1) {
        fprintf(fp,"%.2f\t%f\n",x1,f(a0,a1,x1));
    }
}