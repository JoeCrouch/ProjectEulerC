//http://projecteuler.net/problem=6
#include <iostream>

using namespace std;

int main()
{
    long int sum=0,sum2=0,i,k;
    for(i=1;i<=100;i++)
    {
        sum=sum+i*i;
        sum2=sum2+i;
    }
    cout<<"The sum of the squares of the first 100 natural numbers is:"<<endl;
    cout<<sum<<endl;
    cout<<"The square of the sum of the first 100 natural numbers is:"<<endl;
    cout<<sum2*sum2<<endl;
    k=sum2*sum2-sum;
    cout<<"The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is:"<<endl;
    cout<<k<<endl;
    return 0;
}
