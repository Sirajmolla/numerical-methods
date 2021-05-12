// finding root using secant method
#include<stdio.h>
#include<math.h>
 
// defining the function
float f(float x){
  return sin(x)-x*cos(x);
}

int main()
{
    float a,b,x1,x2,x3; // x1 starting point a, x2 tending from a to b
    printf("Enter the min value x(a): ");
    scanf("%f",&a);
    printf("Enter the max value x(b): ");
    scanf("%f",&b);

    for(x1=a;x1<=b;x1+=0.01){
        x2=x1+0.01;
        if(f(x1)*f(x2)<=0){
          do{
              x3=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
              x1=x2;
              x2=x3;
          }while(fabs(f(x3))>0.00001);
          printf("\nIn the interval: %.3lf and %.3lf\n",x1,x2);
          printf("The root is: %.4lf\n",x3);
        }
    }
}