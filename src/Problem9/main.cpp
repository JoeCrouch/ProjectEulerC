//http://projecteuler.net/problem=9
#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d=0,e,f,g;

    for(a=100;a<500;a++)
    {
        for(b=100;b<500;b++)
        {
            for(c=100;c<800;c++)
            {
                if(a*a+b*b==c*c){if(a+b+c==1000){d=a*b*c;e=a;f=b;g=c; break;}}
            }
            if(d!=0){break;}
        }
        if(d!=0){break;}
    }
    cout<<"The Pythagorean triplet that sums to 1000 is:"<<endl;
    cout<<e<<"^2 + "<<f<<"^2 = "<<g<<"^2"<<endl;
    cout<<e<<"+"<<f<<"+"<<g<<"="<<e+f+g<<endl;
    cout<<"The product of these is:"<<endl;
    cout<<d<<endl;
    return 0;
}
