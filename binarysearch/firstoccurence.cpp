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
void solve(){
}
int arr[] = {1,2,2,2,10,11,12};
int main(){ 
    int n = 7;
    int mid = (n+ 0)/ 2, l=0, r=n-1;
    int num =  3;
    while(l < r-1){
        int mid = (l+r)/2;
        if(arr[mid] < num){
            l = mid;
        }else{
            r = mid;
        }
    }
    if(arr[r] < num){
        cout<<r;
    }else if(arr[l] > num){
        cout<<l;
    }else{
        cout<< (num - arr[l] < arr[r] - num ? l : r)<<endl;
    }
 return 0; 
}