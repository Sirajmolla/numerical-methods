// trapezoidal method
#include<stdio.h>
#include<math.h>
// defining the function to evaluate
float f(float x){
    return atan(x)/(x*x);
}
int main()
{   
    float a=5,b=10; // limits of integration
    int i,n=2;  // starting with two interval
    float integral,answer,x,h,sum,acc=0.0001;
    do{
        integral=answer;
        h=fabs(b-a)/n;
        sum=0;
        for(i=1;i<n;++i){
            x=a+i*h;
            sum=sum+f(x);
        }
        answer=(h/2)*(f(a)+f(b)+2*sum);
        n++;
    }while(fabs(answer-integral)>=acc);
    printf("The integral using trapezoidal Rule is: %f\n",answer);
}