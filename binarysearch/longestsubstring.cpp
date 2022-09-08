
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
bool f(string s, int length){

    string ss;
    for(int i = 0; i <= s.length() - length; i++){
        int j = i + length ;
        if(ss.find(s.substr(i,j)) != string::npos){
            return true;
        }
        ss+= s.substr(i,j);
    }
    return false;
}
int longestsubstr(string s){
    int l = 0, r = s.length()-1;
    while(l < r){
        int mid = l+ (r-l+1)/2;
        if(f(s,mid)){
            l = mid;
        }else{
            r = mid-1;
        }

    }
    return l;
}
int main(){ 
    cout<<longestsubstr("aaaa")<<endl;

 return 0; 
}