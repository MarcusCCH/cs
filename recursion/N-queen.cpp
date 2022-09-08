#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <cmath>
#include <set>
#include <string.h>
using namespace std;
#define INF 1000000000
#define MAXN 100000
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repe(i, a, b) for (int i = a; i <= b; ++i)
#define reve(i, a, b) for (int i = a; i >= b; --i)
#define rev(i, a, b) for (int i = a; i > b; --i)
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define setpr(x) cout << setprecision(x) << fixed
#define sz size()
#define seea(a, x, y)           \
    for (int i = x; i < y; i++) \
    {                           \
        cin >> a[i];            \
    }
#define seev(v, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        cin >> x;               \
        v.push_back(x);         \
    }
#define sees(s, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        cin >> x;               \
        s.insert(x);            \
    }
bool q[10][10];
int u[10][10];
int pc[10], pr[10];
int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {-1, 0, 1, -1, 0, 1, 1, -1};
int n, m;

bool within(int r, int c){
    return c >= 0 && c < n && r >= 0 && r < m;
}
bool check( int row, int col)
{
    for(int i = 0 ; i < 8; i++){
        int a = dx[i], b= dy[i];
        int k = 1;
        while (within(row + a, col + b) )
        {
            if (q[row + a][col + b]){
                return false;
            }
                k++;
            a*=k,b*=k;
        }
    }
    return true;
}
bool solveNQueen(int col)
{
    if (col >= n) // when N queens are placed successfully
        return true;
    for (int i = 0; i < n; i++)
    { // for each row, check placing of queen is possible or not
        if (check(i, col))
        {
            q[i][col] = 1;               // if validate, place the queen at place (i, col)
            if (solveNQueen(col + 1)) // Go for the other columns recursively
                return true;
            q[i][col] = 0; // When no place is vacant remove that queen
        }
    }
    return false; // when no possible order is found
}
int main()
{
    n = 6, m = 6;
    if(!solveNQueen(0)){
        cout<<"No board exists!"<<endl;
    };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << q[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
