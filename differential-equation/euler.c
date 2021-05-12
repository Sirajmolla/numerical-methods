// solving ODE using Euler method
#include<stdio.h>
#include<math.h>

// defining the function to be solved
float f(float x,float y){
    return x*sin(x);  
}
// exact solution
float g(float x){
    return sin(x)-x*cos(x);  
}

int main()
{
    float x,y,h;

    FILE*fp=NULL;
    fp=fopen("euler.txt","w");
    
    x=0;y=0;  // initial condition
    h=0.01; // step size
    // Using Euler Method
    do{
        fprintf(fp,"%f\t%f\t%f\n",x,y,g(x));
        y=y+h*f(x,y);
        x=x+h;
    } while(x<=10);
}