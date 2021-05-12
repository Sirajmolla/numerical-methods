// coupled system of equations
#include<stdio.h>
#include<math.h>

float a=0.2,K=1.7;
float b1=0.1,e1=1.0,m1=0.1;
float b2=0.2,e2=2.0,m2=0.1;

float f1(float t,float x,float y1,float y2) {
    return a*x*(1-x/K)-(b1*y1+b2*y2)*x;
}
float f2(float t,float x,float y1,float y2) {
    return e1*b1*y1*x-m1*y1;
}
float f3(float t,float x,float y1,float y2) {
    return e2*b2*y2*x-m2*y2;
}
int main()
{
    FILE*fp=NULL;
    fp=fopen("coupled.txt","w");

    float x,y1,y2,t,h=0.5;
    float k1,k2,k3,k4,m1,m2,m3,m4,n1,n2,n3,n4;

    // giving initial conditions
    t=0,x=1.7,y1=1.7,y2=1.0;
    do {
        fprintf(fp,"%.1f\t%f\t%f\t%f\n",t,x,y1,y2);
        k1=h*f1(t,x,y1,y2);
        m1=h*f2(t,x,y1,y2);
        n1=h*f3(t,x,y1,y2);

        k2=h*f1(t+h/2.0,x+k1/2.0,y1+m1/2.0,y2+n1/2.0);
        m2=h*f2(t+h/2.0,x+k1/2.0,y1+m1/2.0,y2+n1/2.0);
        n2=h*f3(t+h/2.0,x+k1/2.0,y1+m1/2.0,y2+n1/2.0);

        k3=h*f1(t+h/2.0,x+k2/2.0,y1+m2/2.0,y2+n2/2.0);
        m3=h*f2(t+h/2.0,x+k2/2.0,y1+m2/2.0,y2+n2/2.0);
        n3=h*f3(t+h/2.0,x+k2/2.0,y1+m2/2.0,y2+n2/2.0);

        k4=h*f1(t+h,x+k3,y1+m3,y2+n3);
        m4=h*f2(t+h,x+k3,y1+m3,y2+n3);
        n4=h*f3(t+h,x+k3,y1+m3,y2+n3);

        x=x+(k1+2*k2+2*k3+k4)/6.0;
        y1=y1+(m1+2*m2+2*m3+m4)/6.0;
        y2=y2+(n1+2*n2+2*n3+n4)/6.0;
        t=t+h;
    } while(t<300);
 
}