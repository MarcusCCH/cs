#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 1000, K = 25;
long long st[MAXN][K];
long long a[MAXN];
int lg[MAXN + 1];
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i], st[i][0] = a[i];
    // precompute range sum query sparse table
    for (int j = 1; j <= K; j++)
    {
        for (int i = 0; i + (1 << j) <= N; i++)
        { // 1 2 3 4 --> 10
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    int L, R;
    cin >> L >> R;
    lg[1] = 0;
    for (int i = 2; i < N; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }
    int j = lg[R - L + 1]; // 1 6 --> 1 4, 3 6; j= 2;
    cout << min(st[L][j], st[R - (1 << j) + 1][j]) << endl;
    return 0;
}