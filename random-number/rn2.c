// generating float random numbers between 0 and m
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // N=total no of random no, m=upto you want random no
    int i,j,N=10,m=5;
    float rn[N];
    srand(time(0));
    for(i=0;i<N;++i) {
        rn[i]=((float)rand()/RAND_MAX)*m;
        printf("%d\t%f\n",i+1,rn[i]);
    }
}