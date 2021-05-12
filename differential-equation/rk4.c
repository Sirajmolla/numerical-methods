// solving ODE using rk4 method
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
    float k1,k2,k3,k4;

    FILE*fp=NULL;
    fp=fopen("rk4.txt","w");
    
    x=0;y=0;  // initial condition
    h=0.01; // step size
    // Using Euler Method
    do{
        fprintf(fp,"%f\t%f\t%f\n",x,y,g(x));
        k1=h*f(x,y);
        k2=h*f(x+h/2.0,y+k1/2.0);
        k3=h*f(x+h/2.0,y+k2/2.0);
        k4=h*f(x+h,y+k3);

        y=y+(k1+2*k2+2*k3+k4)/6.0;
        x=x+h;
    } while(x<=10);
}