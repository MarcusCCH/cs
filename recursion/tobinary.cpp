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
int a[MAXN];
void print_binary(int n){
    if(n < 0){
        cout<<"-";
        print_binary(-n);
    }else if (n < 2){
        cout<<n;
    }
    print_binary(n/2);
    print_binary(n%2);
}
int32_t main(){ 
 IOS;
 int n = 1195;
 for (int i = 0; i < 64; i++)
     a[i] = 0;
 while (n > 0)
 {
     if (n % 2 != 0)
     {
         n -= 1;
         a[0]++;
     }
     else
     {
         int k = n, power = 0;
         while (k % 2 == 0)
         {
            //  cout << "k" << k << endl;
             k /= 2;
             power++;
         }
        //  cout << power << endl;
         a[power]++;
         n -= pow(2, power);
     }

    }
    for(int i = 10; i >= 0; i--){
        cout<<a[i];
    }
    return 0;
}