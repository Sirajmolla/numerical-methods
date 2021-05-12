/*generating float random numbers between 0 and 1 
and plotting the frequency distribution*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,j,N=10000;
    float rn[N];
    srand(time(0));
    for(i=0;i<N;++i) {
        rn[i]=((float)rand()/RAND_MAX);
    }
    //frequncy distribution within bin width
    float h=0.01; //width of interval
    int bin=100;   //100 intervals of width 0.01
    int freq[bin]; 
    for(j=0;j<bin;++j) {
        freq[j]=0;
        for(i=0;i<N;i++) {
            //frequncy of RN within bin width
            if((rn[i]>=j*h)&&(rn[i]<(j+1)*h)) {
                freq[j]++;
            }   
        }
    }
    // stroing frequncy distribution
    FILE*fp=NULL;
    fp=fopen("frequncy.txt","w");
    for(j=0;j<bin;++j) {
        fprintf(fp,"%f\t%d\n",j*h,freq[j]);
    }
    //Correlation Checks
    FILE*fp1=NULL;
    fp1=fopen("correlation.txt","w");
    for(i=0;i<N-2;++i) {
        fprintf(fp1,"%f\t%f\t%f\n",rn[i],rn[i+1],rn[i+2]);  
    }
}