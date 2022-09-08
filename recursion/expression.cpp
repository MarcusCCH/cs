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

int helper(string s, int len){
    
    if(len == 3){
        return 1;
    }
    int cnt = 0;
    bool appeared = false;
    int low = -1 ,high;
    for(int i = 0 ; i < len;i++){
        if(s[i] == '('){
            appeared = true;
            if(low==-1)
            low = i;
            cnt++;
        }
        if(s[i] == ')')cnt--;
        if(cnt == 0 && appeared){
            high = i;
            break;
        }
    }
    if(low == 0){
        return high +1;
    }else{
        return low -1;
    }
}
int solve(string s, int len){
    if(len == 1){
        return s[0] - 48;
    }
    int pivot = helper(s, len);
    if(pivot< 0)return 0;
    string left, right; int leftlen=0, rightlen=0;
    if(pivot == 1){
        left[0] = s[0];
        leftlen = 1;
    }
    else{
        for(int i = 1; i < pivot -1; i++){
            left[i-1] = s[i];
            leftlen++;
        }
    }
    cout<<"right";
    if(len - pivot == 2) {
        right[0] = s[len-1];
        rightlen = 1;
        cout<<right[0];
    }
    else{
        for (int i = pivot + 1; i < len; i++)
        {
            
            right[i - pivot - 1] = s[i];

            cout<<right[i-pivot-1];
            rightlen++;
        }
    }
    cout<<endl;

    if(s[pivot] == '*'){

        return solve(left,leftlen) * solve(right, rightlen);
    }else{
        return solve(left, leftlen) + solve(right, rightlen);
    }
}
int32_t main(){ 
 IOS;
 string s = "(((1+3)*(2*(4+1)))+(8+9)))*(7+3)";
 
 cout<<solve(s, s.length());
 return 0; 
}