
#include <iostream>
#include <cmath>

using namespace std;
long double fact(int);
/*namespace N
{
    typedef int n;
}*/
int main()
{
    int n = 1,p = 1;
    long double pmax = 0.1, max = 0.1;
    while (max >= pmax)
    {
       /* if (n == 170)
            break;
            170 is the largest integer for which its factorial can be 
            stored in IEEE 754 double-precision floating-point format.*/
        n++;
        pmax = max;
        max = fact(n);
    }
    cout << "The limit reached is " << pmax << "+"<<(n/5)<<" for n equal to " << n << endl;

    float m = 1.0;
    long double pmin = 10, min = 10;
    while (min <= pmin)
    {
        m++;
        pmin = min;
        min = (long double)1/fact((int)m);
    }
    cout << "The limit reached is " << pmin << "-"<<(n/5)<< " for m equal to " << m << endl;
}

long double fact(int k)
{
    long double f = 1;
	int p = 1;
    for (unsigned long long int i = 1; i < k + 1; i++)
    {
        if (i % 5 == 0)
        {
           p = i/5;//sort of marker for powers of 10  
        }
	 	f *= i; 
	}
	f /=pow(10,(p));
   return f;
}
/*The limit reached is 5.17824e+3946+309 for n equal to 1545
The limit reached is 1.93116e-3947-309 for m equal to 1545*/