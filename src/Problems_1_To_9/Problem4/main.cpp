#include <iostream>
#include <ctime>

using namespace std;

bool isPalindromic(int n)
{
    int x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0;

    x1 = n % 10;
    x2 = ((n - x1) / 10) % 10;
    x3 = ((n - x1 - x2) / 100) % 10;
    x4 = ((n - x1 - x2 - x3) / 1000) % 10;
    x5 = ((n - x1 - x2 - x3 - x4) / 10000) % 10;
    x6 = ((n - x1 - x2 - x3 - x4 - x5) / 100000) % 10;

    if(x6 == 0) {
        if( x5 == x1 && x4 == x2){
                return true;
        }
        else {
            return false;
        }
    }
    else {
        if (x6 == x1 && x5 == x2 && x4 == x3) {
            return true;
        } else {
            return false;
        }
    }
}

int main()
{
    int d = 0, m = 0, k = 0, l = 0;
    for(int i = 999; i > 800; i--)
    {
        for(int j = 999; j > 800; j--)
        {
            m = i * j;
            if (isPalindromic(m)) {
                if (m > d) {
                    d = m;
                    k = i;
                    l = j;
                }
            }
        }
    }
    cout<<"The largest palindrome made from the product of two 3-digit numbers is:"<<endl;
    cout<<"\n"<<k<<" * "<<l<<" = "<<d;
}

