// expontetial fitting in the form of y=a*exp(b*x)
#include<stdio.h>
#include<math.h>

int main()
{
    int i,n=7; // no of points
    float x[]={1,2,3,4,5,6,7};
    float y[]={4,5,8,16,30,38,70};
    float sigma[]={2,2,3,3,4,5,5};
    // for expontial fitting
    for(i=0;i<n;i++) {
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
    fp=fopen("expontetial.txt","w");
    //calculating the fitted points
    for (i=0;i<n;i++){ 
        y[i]=a0*exp(a1*x[i]);
        fprintf(fp,"%f\t%f\n",x[i],y[i]);
    }
}