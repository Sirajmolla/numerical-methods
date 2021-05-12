// generating float random numbers between 0 and 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // N=total no of random no
    int i,j,N=10;
    float rn[N];
    srand(time(0));
    for(i=0;i<N;++i) {
        rn[i]=((float)rand()/RAND_MAX);
        printf("%d\t%f\n",i+1,rn[i]);
    }
}