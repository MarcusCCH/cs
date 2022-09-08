#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int sum = 0;
//attempt 1
int print(int n, int count)
{
    if (n == 0)
    {
        return 0;
    }
    print(n / 10, count++);
    int k = pow(10, count);
    sum += n % k;
    return sum;
}
//attempt 2;
int print2(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return print2(n / 10) + n % 10;
}

int main()
{
    int n;
    int count = 0;
    cin >> n;
    cout << print(n, count) << endl;
    cout << print2(n);
}