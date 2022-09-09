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
#define MAXN 1000100
#define K 25
#define pb push_back
#define F first
#define S second
#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define repe(i, a, b) for (int i = a; i <= b; ++i)
#define reve(i, a, b) for (int i = a; i >= b; --i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
stack<int> s;
int c[MAXN], d[MAXN];
string e;
void solve(string a, int n){
    for (int i = 0; i < n; i++)
    {
        d[i] = -1;
        c[i] = -1;
    }
    int maxlen = 0, times = 1, cur = -1;
    for(int i = 0 ; i <n; i++){
        if (i > 0 && !s.empty() && a[i] == ')')
        {
            // cout<<s.top()<<endl;
            if (a[s.top()] == '('){
            // cout << i << " " << s.top() << endl;
            d[i] = s.top();
            d[s.top()]  = i;
            // if(i -1 < cur || cur == -1){
            //     cur = i -1;
            // }
            // if(d[i] == -1)cur = -1;
            // c[i] = cur;
            // // cout<<d[i]<<endl;
            // int diff = i - c[i] + 1;
            // // cout<<diff<<endl;
            // if (diff > maxlen)
            // {
            //     maxlen = diff;
            //     times = 1;
            // }
            // else if (diff == maxlen)
            // {
            //     times++;
            // }
            };
            s.pop();
            
        }
        else
        {
            s.push(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        int diff = 0;
        if (d[i] == -1)
            cur = -1;
        else if (i < cur || cur == -1)
        {
            cur = i;
        }
        
        // c[i] = cur;
        if(d[i] != -1)
        diff = i - cur + 1;
        // cout<<d[i]<<endl;
        // cout<<diff<<endl;
        if (diff > maxlen)
        {
            maxlen = diff;
            times = 1;
        }
        else if (diff == maxlen && diff != 0)
        {
            times++;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<d[i]<<" ";
    // }
    // cout<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //    cout<<c[i]<<" ";
    // }
    // cout<<endl;
    
    // cout<<endl;
    cout<<maxlen<<" "<<times<<endl;
} 
int32_t main(){ 
 IOS; 
 int i = 0;
 getline(cin, e);

 solve(e, e.length());
 return 0; 
}