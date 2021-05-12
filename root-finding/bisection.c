// finding root using Bisection Method
#include<stdio.h>
#include<math.h>
 
// defining the function
float f(float x){
  return sin(x)-x*cos(x);
}
 
int main()
{
  float a,b,x,xm,xl,xr,acc=0.0001,xinc=0.1,abs;
  //xm=root, (xl,xr)=intermediate intervals

  printf("Enter the min value x(a): ");
  scanf("%f",&a);
  printf("Enter the max value x(b): ");
  scanf("%f",&b);

  printf("\nroot\t\tf(xm)\t\tabs\n");
  for (x=a;x<=b;x+=xinc){
    if (f(x)*f(x+xinc)<0){
      xl=x;
      xr=x+xinc;
      do{
        xm=(xl+xr)/2.0;
        if (f(xm)*f(xl)>0)
          xl=xm;
        if (f(xm)*f(xl)<0)
            xr=xm;
        abs=fabs((xl-xr)/(xl+xr));
        }
        while(abs>acc);
        printf("%f\t%f\t%f\t\n",xm,f(xm),abs);
    }
  }
}