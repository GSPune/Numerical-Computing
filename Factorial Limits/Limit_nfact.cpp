#include <iostream>

using namespace std;
unsigned long long int fact(int);
/*namespace N
{
    typedef int n;
}*/
int main()
{
    int n = 1;
    unsigned long long int pmax = 1, max = 1;
    while (max >= pmax) //until processor breaks
    {
        n++;
        pmax = max;
        max = fact(n);
    }
    cout << "The limit reached is " << pmax << " for n equal to " << n << endl;

    float m = 1.0;
    long double pmin = 1.0, min = 1.0;
    while (min <= pmin)
    {
        m++;
        pmin = min;
        min = (long double)1/fact((int)m);
    }
    cout << "The limit reached is " << pmin << " for m equal to " << m << endl;
}
/*The limit reached is 17196083355034583040 for n equal to 23
The limit reached is 5.81528e-20 for m equal to 23*/

unsigned long long int fact(int k)
{
    unsigned long long int f = 1;
    for (unsigned long long int i = 1; i < k + 1; i++)
    {
        f *= i;
    }
   return f;
}