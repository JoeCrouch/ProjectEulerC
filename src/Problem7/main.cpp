//http://projecteuler.net/problem=7
#include <iostream>

using namespace std;

int isPrime(int n)
{
    int i=1;
    if (n <= 1){return 0;}
    else if (n == 2){return 1;}
    else if (n % 2 == 0){return 0;}
    else if (n < 9){return 1;}
    else if (n % 3 == 0){return 0;}
    else if (n % 5 == 0){return 0;}
    else{for(i=7;i*i<=n;i++){if(n%i==0){return 0;}}return 1;}
}

int main()
{
    int i=1,m=2,k=0;
    while(i<=10001)
    {
        if(isPrime(m)==1){k=m;i=i+1;}
        m++;
    }
    cout<<"The 10,001st prime number is:"<<endl;
    cout<<k<<endl;
    return 0;
}
