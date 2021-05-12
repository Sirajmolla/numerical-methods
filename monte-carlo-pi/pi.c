/* using random no finding the value of pi. repeating the 
program M times and plotting the mean with std deviation*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
// generating random numbers b/w range
float randnum(float min, float max) {
    float random = ((float)rand())/(float)RAND_MAX;
    return (max-min)*random + min;
}
// calculating mean of an array
float mean(int N,float arr[N]) {
    float sum=0;
    for (int i=0;i<N;++i)
        sum += arr[i];
    return sum/N;
}
// calculating dispersion relation of an array
float dispersion(int N,float arr[N]) {
    float avg,std=0;
    avg=mean(N,arr);
    for (int i=0;i<N;++i)
        std += pow((arr[i]-avg),2);
    return sqrt(std/(N-1));
}
// adding the error from each expt
float std(int N,float arr[N]) {
    float sum=0;
    for(int i=0;i<N;++i)
        sum += (arr[i]*arr[i]);
    return sqrt(sum)/N;
}

void main()
{
    int i,j,n=1000;
    int M=500;   // repeating the expt. M times
    float x[n],y[n],z[n];
    float As=4,area[M],sigma[M];

    FILE*fp=NULL;
    fp=fopen("pi500.txt","w");
    srand(time(0));
    //calculating the area multiple times
    for (j=0;j<M;++j) {
        float Naccept=0;
        for (i=0;i<n;++i) {
            x[i]=randnum(-1,1);
            y[i]=randnum(-1,1);
            z[i]=pow(x[i],2)+pow(y[i],2);
            if (z[i]<=1){
                Naccept++;
            }
        }
        area[j]=As*Naccept/n;
        sigma[j]=sqrt(Naccept*(1-Naccept/n))*As/n;
        //printf("M[%d]\t%f\t%f\n",j+1,area[j],sigma[j]);
        fprintf(fp,"%d\t%f\t%f\n",j+1,area[j],sigma[j]);
    }

    printf("\nTotal performed expt:%d\n",M);
    printf("mean: %f\tbinomial std deviation: %f\n",mean(M,area),std(M,sigma));
    printf("dispersion in mean: %f\n",dispersion(M,area));
}