//*****************************************************************************
//File Name: main.cpp
//
//Description: This program solve the Project Euler Problem 60. This problem
//             can be found at http://projecteuler.net/problem=60.
//
//Author: Joe Crouch
//*****************************************************************************

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

// Concatenates two numbers i.e. conc(11,27)=1127
int conc(int a, int b)
{
    int c = b;
    while(c>0)
    {
        a*=10;
        c/=10;
    }
    return a+b;
}

// Checks if a number is prime
bool isPrime(int n)
{
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    if (n < 9) return true;
    if (n % 3 == 0) return false;
    if (n % 5 == 0) return false;

    for (int i=7; i*i<=n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

//Checks which primes concatenate both ways round to another prime
void ConcArray(int a, int sum, int Primes[],int **Pairs)
{
 for (int i=(a+1); i<sum; i++)
 {
     if((isPrime(conc(Primes[a],Primes[i])) && isPrime(conc(Primes[i],Primes[a])))==1)
     {Pairs[a][i] = Primes[i];}
 }
}

//This calculates the frequency of a given number within a certain column of an array
int Contains(int a, int b, int sum, int **Pairs)
{
    int n=0;
    for(int i=a; i<sum; i++)
    {
        if((Pairs[a][i]) == b) n+=1;
    }
    return n;
}

int main()
{
    //Set an upper bound
    int a=10000;
    int A[a-1];
    int MAX=26033;

    //Creates an array containing 2,3,....,a
    for (int i=0; i<a-1; i++)
    {
        A[i]=i+2;
    }

    //Removes the non prime elements of the array using sieve of Eratosthenes: http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    for (int i=0; i*i<a; i++)
    {
        if(A[i] !=0)
        {
            for(int j=i+3; j<a+1; j++)
            {
                if (j % A[i] == 0 ){A[j-2]=0;}
            }
        }
    }

    int sum = 0;

    //Counts the number of primes within the array
    for (int i=0; i<a-1; i++)
    {
        if (A[i] != 0){ sum+=1; }
    }

    //Creates an array that only contains the prims
    int Primes[sum];
    int j=0;
    for (int i=0; i<sum; i++)
    {
    while ( A[j]==0 )
    {
        j+=1;
    }
    Primes[i]=A[j];
    j+=1;
    }

    //Creates a 2 dimiensional array of zeroes
    int ** Pairs;
    Pairs = new int*[sum];
    for (int i = 0; i < sum; ++i)
    Pairs[i] = new int[sum];

    for (int i=0; i<sum; i++)
    {
        for(int j=0; j<sum; j++)
        {Pairs[i][j]=0;}
    }

    // Checks which primes concatenate with each other to form another prime and creates an increasing set that do so
    int b,c,d,e;
    for (a=1; a<sum; a++)
    {
        if((Primes[a]*5)>MAX) break;
        if(Contains(a,0,sum,Pairs)==sum-a) ConcArray(a,sum,Primes,Pairs);

        for(b=a+1; b<sum; b++)
        {
            if((Primes[a]+(Primes[b]*4))>MAX) break;
            if(Contains(a,Primes[b],sum,Pairs)!=1) continue;
            if(Contains(b,0,sum,Pairs)==sum-b) ConcArray(b,sum,Primes,Pairs);

            for(c=b+1; c<sum; c++)
            {
                if((Primes[a]+Primes[b]+(Primes[c]*3))>MAX) break;
                if((Contains(a,Primes[c],sum,Pairs)
                    && Contains(b,Primes[c],sum,Pairs))!=1) continue;
                if((Contains(c,0,sum,Pairs))==sum-c) ConcArray(c,sum,Primes,Pairs);

                for(d=c+1; d<sum; d++)
                {
                    if((Primes[a]+Primes[b]+Primes[c]+(Primes[d]*2))>MAX) break;
                    if((Contains(a,Primes[d],sum,Pairs)
                        && Contains(b,Primes[d],sum,Pairs)
                        && Contains(c,Primes[d],sum,Pairs))!=1) continue;
                    if((Contains(d,0,sum,Pairs))==sum-d) ConcArray(d,sum,Primes,Pairs);

                    for(e=d+1; e<sum; e++)
                    {
                    if((Primes[a]+Primes[b]+Primes[c]+Primes[d]+Primes[e])>MAX) break;
                    if((Contains(a,Primes[e],sum,Pairs)
                            && Contains(b,Primes[e],sum,Pairs)
                            && Contains(c,Primes[e],sum,Pairs)
                            && Contains(d,Primes[e],sum,Pairs))!=1) continue;

                            /*if((Primes[a]+Primes[b]+Primes[c]+Primes[d]+Primes[e])!=MAX) continue;*/
                            cout<<Primes[a]<<"+"<<Primes[b]<<"+"<<Primes[c]<<"+"<<Primes[d]<<"+"<<Primes[e]<<"=26033"<<endl;
                            break;

                    }
                //Stops the for loop once the set of 5 numbers has been found
                if((Primes[a]+Primes[b]+Primes[c]+Primes[d]+Primes[e])==MAX) break;}
            if((Primes[a]+Primes[b]+Primes[c]+Primes[d]+Primes[e])==MAX) break;}
        if((Primes[a]+Primes[b]+Primes[c]+Primes[d]+Primes[e])==MAX) break;}
    if((Primes[a]+Primes[b]+Primes[c]+Primes[d]+Primes[e])==MAX) break;} //Stops the for loop once the set of 5 numbers has been found//
    system("pause");
    return 0;
}
