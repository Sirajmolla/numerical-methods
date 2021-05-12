// simpson's 3/8 rule
#include<stdio.h>
#include<math.h>
// defining the function to evaluate
float f(float x){
    return atan(x)/(x*x);
}
int main()
{   
    float a=5,b=10; // limits of integration
    int i,n=3;  // starting with three interval
    float integral,answer,x,h,sum,acc=0.0001;
    do{
        integral=answer;
        h=fabs(b-a)/n;
        sum=0;
        for(i=1;i<n;++i){
            x=a+i*h;
            if(i%3==0)
                sum=sum+2*f(x);
            else
                sum=sum+3*f(x);
        }
        answer=(3*h/8)*(f(a)+f(b)+sum);
        n=n+3;  // n should be a multiple of 3
    }while(fabs(answer-integral)>=acc);
    printf("The integral using Simpson's 3/8 Rule is: %f\n",answer);
}