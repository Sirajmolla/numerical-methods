// evaluting cosine(x)
#include<stdio.h>
#include<math.h>
int main()
{

    float x,t0,t1,R,sum,acc=0.0001;
    printf("Enter the value of x: ");
    scanf("%f",&x);

    t0=1;   //defining first term of series
    sum=t0; //first term is also first partial sum

    printf("n\ttn\tSn\tfabs(tn/sum)\n");

    int i=0;
    do{
        printf("%d\t%.2f\t%.2f\t%f\n",i,t1,sum,fabs(t1/sum));
        i++;
        
        R=-(x*x)/((2*i-1)*(2*i));
        t1=R*t0;
        sum=sum+t1;
        t0=t1;
    } while(fabs(t1/sum)>acc);
    printf("\nThe sum of cos(%.2f) is: %f summing %d terms.",x,sum,i);
}
