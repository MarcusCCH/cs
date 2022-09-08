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
int maxlen = 0, times = 0;
int cnt = 0;
int solve(string s, int ptr= 0, int prev = 0){
    if(s[ptr] == ')'){
        return ptr;
    } 
    //((()))
    while(ptr < s.length() -1){
        int initptr = ptr;
        ptr = solve(s,ptr+1,ptr);
        if(s[initptr] == '(' && s[ptr] == ')'){
            cout<<initptr<<" "<<ptr<<" "<<endl;
            int diff = ptr - initptr + 1;
            if (diff > maxlen){
                maxlen = diff;
                times = 1;
            }
            else if (diff == maxlen){
                times++;
            }
            cnt += maxlen;
        }
    }

    cout<<ptr<<" "<<cnt<<endl;
    return cnt;
    /*

  (()()))

    */
}
int32_t main(){ 
 IOS;
//  string s = "(())";
 string s = "((()))";
    solve(s);
cout<<maxlen<<" "<<times<<endl;
 return 0; 
}

