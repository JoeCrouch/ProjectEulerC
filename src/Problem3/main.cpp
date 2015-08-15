//http://projecteuler.net/problem=3
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void VecPrint(long int *Y,int n){
    int i;
    for(i=0;i<n+1;i++){if(Y[i]!=0){cout<<"\n"<<setw(10)<<Y[i];}
                        else {cout<<"\n\n";return;}}
    cout<<"\n\n";
    return;}

long int factors[100];

void primefactors(long long int n, int s)
{
  int i;
  long int d=0;

  for(i=2;i*i<n;i++)
    {
    if(n%i==0){d=i;break;}
    }
    if(d==0){factors[s]=n;return;}
    factors[s]=d;
    s=s+1;
    primefactors(n/d,s);
}

int main()
{
    int s=0,i;
    long long n=600851475143;
    long int d;

    primefactors(n,s);
    cout<<"Prime factors of 600851475143 are:"<<endl;
    VecPrint(factors,100);
    d=factors[0];
    for(i=1;i<100;i++)
    {
        if(factors[i]==0){break;}
        if(factors[i]>d){d=factors[i];}
    }
    cout<<"\nLargest Prime="<<d;
    cout<<"\n\n";
    return 0;
}
