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
#define INF 1000000010
#define MAXN 100010
#define K 25
#define pb push_back
#define F first
#define S second
#define int long long
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
vi combine(vi left, vi right)
{
    vector<int> final;
    int j = 0;
    int k = 0;
    int leftlen = left.size();
    int rightlen = right.size();
    cout << "initleft" << leftlen;
    for (int i = 0; i < leftlen; i++)
    {
        cout << left[i] << " ";
    }
    cout << endl;
    cout << "initright" << rightlen;
    for (int i = 0; i < rightlen; i++)
    {
        cout << right[i] << " ";
    }
    cout << endl;
    while (j < leftlen && k < rightlen)
    {
        // cout << left[j] << " " << right[k] << endl;
        if (left[j] <= right[k])
        {
            // cout<<left[j]<<" "<<endl;
            final.pb(left[j]);
            // if (left[j+1] < right[k])
            j++;
            // cout<<"j"<<j<<endl;
        }
        else if (right[k] <= left[j])
        {
            // cout << right[k] << " " << endl;
            final.pb(right[k]);
            // if(right[k+1]< left[j])
            k++;
            // cout<<"k"<<k<<endl;
        }
    }
    // cout << j << " " << k << endl;
    if (k == rightlen)
    {
        // cout << "hi" << endl;
        for (int i = j; i < leftlen; i++)
        {
            final.pb(left[i]);
        }
    }
    else
    {
        for (int i = k; i < rightlen; i++)
        {
            final.pb(right[i]);
        }
    }
    cout << "ret";
    for (int i = 0; i < final.size(); i++)
    {
        cout << final[i] << " ";
    }
    cout << endl;
    return final;
}
vi mergesort(vi a, int low, int high, int n)
{
    cout<<"hi"<<endl;
    int mid = (low + high) / 2;
    cout << low << " " << mid << " " << high;
    if (n == 1)
    {
        return a;
    }
    // vector<int> left, right;
    vi left, right;
    cout << "left";
    for (int i = low; i < mid; i++)
    {
        // left.pb(a[i]);
        left[i] = a[i];
        cout << left[i] << " ";
    }
    cout << endl;
    cout << "right";
    for (int j = mid; j < high; j++)
    {
        // right.pb(a[j]);
        right[j] = a[j];
        cout << right[j] << " ";
    }

    cout << endl;
    // if(mid - low == 1)return left;
    // if(high - low == 1)return right;
    // check length is correct, need +1 or not;
    return combine(mergesort(left, low, mid, mid - low), mergesort(right, mid, high, high - mid));
}
vi c;
int32_t main()
{
    IOS;
    int n = 7;
    for(int i = 0 ; i < n; i++){
        int x;
        cin>>x;
        c.push_back(x);
    }
    cout<<"hi"<<endl;
    // vector<int> k = combine(a,b,3,3);
    vi fin;
    int low = 0, high = 7;
    fin = mergesort(c, low, high, n);
    for (int i = 0; i < 8; i++)
    {
        cout << fin[i] << " ";
    }
    // rep(i,0,10){
    //     cout<<k[i]<<endl;
    // }
    return 0;
}