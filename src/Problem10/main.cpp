//http://projecteuler.net/problem=10
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
    long int m=2;
    __int64 sum=0;
    while(m<2000000)
    {
        if(isPrime(m)==1){sum=sum+m;}
        m++;
    }
    cout<<"The sum of all the primes below two million is:"<<endl;
    cout<<sum;
    return 0;
}
