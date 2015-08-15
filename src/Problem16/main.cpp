//http://projecteuler.net/problem=16
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int *doubling2(int *A,int n,int a)
{
    int i,j=1;
    A[0]=1;
    for(i=1;i<n;i++)
    {
        A[i]=0;
    }
    while(j<=a)
    {
        for(i=0;i<=n;i++)
        {
            if(A[i]!=0){A[i]=A[i]*2;}
        }
        for(i=0;i<=n;i++)
        {
            if(A[i]>=10){A[i]=A[i]-10;A[i+1]=A[i+1]+1;}
        }
        j++;
    }
    return A;
}

void VecPrint(int *Y,int n){
    int i;
    for(i=n-1;i>=0;i--){cout<<setw(1)<<Y[i];}
    cout<<"\n\n";
    return;}

int *VecMake(int n){
    int *Y;
    Y=(int *)malloc((n+1)*sizeof(int));
    return(Y);}

int main()
{
    int *A;
    int a=1000,n=302,i,sum=0;

    A=VecMake(n);
    A=doubling2(A,n,a);
    for(i=0;i<n;i++)
    {
        sum=sum+A[i];
    }
    cout<<"2^1000="<<endl;
    VecPrint(A,302);
    cout<<"The sum of these digits is:"<<endl;
    cout<<sum<<endl;
    return 0;
}
