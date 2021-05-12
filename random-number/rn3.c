// generating float random numbers between [a,b]
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// generating random numbers b/w range
float randnum(float min, float max) {
    float random = ((float)rand())/(float)RAND_MAX;
    return (max-min)*random + min;
}
int main()
{
    // N=total no of random no
    int i,j,N=10;
    float rn[N];
    srand(time(0));
    for(i=0;i<N;++i) {
        rn[i]=randnum(1,5); //random no b/w [1:5]
        printf("%d\t%f\n",i+1,rn[i]);
    }
}