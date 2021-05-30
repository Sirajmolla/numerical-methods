// fitting to any nth order polynomial for (x,y,sig)
// change the arrays according to your problem
#include<stdio.h>
#include<math.h>
// function to be fitted
double f(int n,double a[n],double x){
    double sum=0;
    for (int i=0;i<n;++i)
        sum += a[i]*pow(x,i);
  return sum;
}
// function to solve AX=b for X
void gausspivot(int n,double A[n][n+1],double x[]){
    int i,j,k;
    for(i=0;i<n-1;i++){
        //Partial Pivoting
        for(k=i+1;k<n;k++){
            //If the diagonal element is less than the terms below it
            if(fabs(A[i][i])<fabs(A[k][i])){
                //Swap the rows in the matrix
                for(j=0;j<=n;j++){                
                    double temp;
                    temp=A[i][j];
                    A[i][j]=A[k][j];
                    A[k][j]=temp;
                }
            }
        }
        //Begin the Gauss Elimination
        for(k=i+1;k<n;k++){
            double term;
            term=A[k][i]/A[i][i];
            for(j=0;j<=n;j++){
                A[k][j]=A[k][j]-term*A[i][j];
            }
        }        
    }
    //Start with the back-substitution
    for(i=n-1;i>=0;i--){
        x[i]=A[i][n];
        for(j=i+1;j<n;j++){
            x[i]=x[i]-A[i][j]*x[j];
        }
        x[i]=x[i]/A[i][i];
    }  
    // printing the x array
    for(i=0;i<n;i++) {
        printf(" a[%d]= %.3lf\n",i,x[i]);
    }     
}
int main()
{
    int n,N=11;   // no of datapoints
    //int n=2; // order of matrix or n-1 is the order of polynomial
    printf("Enter the order of the polynomial:");
    scanf("%d",&n);
    n++;  // order of the augmented matrix
    int i,j,k;
    double x[]={0,0.2,0.4,0.6,0.8,1,1.2,1.4,1.6,1.8,2};
    double y[]={6.33,6.51,6.43,5.85,4.71,3.13,1.53,0.64,1.58,5.91,15.71};
    double sigma[]={0.06,0.13,0.19,0.23,0.23,0.19,0.11,0.05,0.14,0.59,1.73};
    double A[n][n+1];
    // part A of augmented matrix [A:b] 
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            double weight,sum=0,w=0;
            for(k=0;k<N;k++) {
                weight=1/pow(sigma[k],2);
                sum+=pow(x[k],i+j)*weight;
                w+=weight;
            }
            A[i][j]=sum/w;
        }
    }
    // part b of augmented matrix [A:b]
    for(i=0;i<n;i++) {
        double weight,sum=0,w=0;
        for(k=0;k<N;k++) {
            weight=1/pow(sigma[k],2);
            sum=sum+(pow(x[k],i)*y[k]*weight);
            w+=weight;
        }
        A[i][n]=sum/w;
    }
    double a[n],yf[N]; //yf[N] is fitted values
    // finding the coefficients
    printf("The coefficients for order [%d] are:\n",n-1);
    gausspivot(n,A,a);

    // exportng the fitted data-points
    FILE*fp=NULL;
    fp=fopen("polysig.txt","w");
    float X;
    for(X=0;X<=2;X+=0.01) {
        fprintf(fp,"%.2f\t%f\n",X,f(n,a,X));
    }
    // for chi square calculation
    for (k=0;k<N;++k)  
        yf[k]=f(n,a,x[k]);
    // calculating the chi square
    double chi=0;
    for (i=0;i<N;++i)
        chi += 1/pow(sigma[i],2)*(yf[i]-y[i])*(yf[i]-y[i]);
    printf("Chi square for order [%d]:%lf\n",n-1,chi);
}