//http://projecteuler.net/problem=2
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int sum=2,fib1=1,fib=0,fib2=2;
    clock_t t1;
    double time=0;
    while(fib1+fib2<=4000000)
    {
        fib=fib1+fib2;
        if(fib%2==0){sum=sum+fib;}
        fib1=fib2;
        fib2=fib;
    }
    cout<<"By considering the terms in the Fibonacci sequence whose values do not exceed \nfour million, the sum of the even-valued terms is:"<<endl;
    cout<<"\n\nSum="<<sum;
    t1=clock();
    time=time+(double)(t1)/CLOCKS_PER_SEC;
    cout<<"\n\nTime="<<time;
    return 0;
}
