// Iterative C++ program to find modular
// inverse using extended Euclid algorithm
#include <stdio.h>
#include <iostream>
// Returns modulo inverse of a with respect
// to m using extended Euclid Algorithm
// Assumption: a and m are coprimes, i.e.,
// gcd(a, m) = 1
using namespace std;
template <class Rai>
Rai check(Rai i, Rai y)
{
    if (i > y)
    {
        return i;
    }
    else
    {
        return y;
    };
}
int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        // q is quotient
        int q = a / m;
        int t = m;
        //cout << "start" << endl;
        //cout << "q " << q << endl;
        //cout << "t " << t << endl;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
        // cout << "m " << m << " a " << a << " t " << t << endl;
        // Update y and x
        y = x - q * y;
        x = t;
        // cout << "y " << y << " x " << x << endl;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}

// Driver Code
int main()
{
    int a = 3, m = 11;

    // Function call
    printf("Modular multiplicative inverse is %d\n",
           modInverse(a, m));
    char i = 'a';
    char k = 'b';
    cout << check(i, k) << endl;
    int x = 24;
    int *fp = &x;
    *fp += *fp;
    cout << *fp << endl;
    cout << fp << endl;
}
