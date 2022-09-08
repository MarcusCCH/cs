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
int n,m,shots;
int a[MAXN][10];
// void build(){

//     lg[1] = 0;
//     for(int i = 2; i < n; i++){
//         lg[i] = lg[i/2] + 1;
//     } 
//     for(int j = 1; j < K; j++){
//         for(int i = 0; i + (1<<j)<= n; i++){
//             st[i][j] = max(st[i][j-1], st[i+ (1<<(j-1))][j-1]);
//         }

//     }
//     for (int i = 0; i< n; i++){
//         for (int j = 0; j < m; j++)
//         {
            
//                 cout<<st[i][j]<<" ";
            
//         }
//         cout<<endl;
//     }
// }

/*
3 2 4
1 2
1 3
2 1

1 3 = 4
2 3 = 5 -> foul

so -> 1,3

5 2 7
4 0 3
1 2 4
2 1 2 
0 2 1 
1 3 3
2 2 2


2 2 
2 3 = 5 -> no ;


*/
// void precompute(){
//     for (int i = 0; i < n; i++)
//     {
//         int j = i;
//         while (j < n)
//         {
//             int next = j, L = j, R = n, cgcd = query(i, j);
//             while (L < R)
//             {
//                 int mid = (R + L) / 2;
//                 if (query(i, mid) == cgcd)
//                 {
//                     next = mid, L = mid + 1;
//                 }
//                 else
//                 {
//                     R = mid - 1;
//                 }
//             }
//             ans[cgcd] += next - j + 1;
//             j = next + 1;
//         }
//     }
// }
bool cmp(int l, int r, int ul, int ur){
    int ret= 0;
    // cout<<endl;
    repe(i,l,r){
        if(i+1 <= ur)
        rep(j,0,m){
        ret+= max(a[i][j], a[i+1][j]);
        a[i][j] = max(a[i][j], a[i + 1][j]);
        // cout<<a[i][j]<<" ";
        }
        // cout<<endl;
    }
    return ret <= shots;
}
int32_t main(){ 
 IOS; 
 cin>>n>>m>>shots;
 if(shots == 0){
    cout<<0<<endl;
    return 0;
 }
 rep(i,0,n){
    rep(j, 0, m){
    cin>>a[i][j];
    // st[i][j] = a[i][j];
    // }
    }
 }
//  build();

 /*


4 2 4 = 10 -> foul
2 2 4 = 8 -> foul
2 2 2 = 6 -> yes
1 3 3 = 7 -> yes
2 3 3 = 8 -> foul

2 3 3 = 8 -> no;
so either 2 2 2 or 1 3 3


1 2
1 3
2 2

1 3
2 3

*/

 int l = 0, r = n - 1;
 if (){
    
 }
 while (l != r-1)
 {
     while (l+1 != r && !cmp(l, l + 1, l ,r))
     {
         l += 1;
     }
        // cout<<l<<endl;
     while ( r-1 != l && !cmp(r - 1, r, l, r))
     {
         r -= 1;
     }
}
    // repe(i, 0, n)
    // {
    //     repe(j, 0, m)
    //     {
            
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int reta = 0, retb = 0;
    for(int i = 0 ; i < m; i++){
        reta += a[l-1][i];
        retb += a[r-1][i];
    }
    if(reta > shots || reta > retb){
        for (int i = 0; i < m; i++)
        {

            cout<<a[r - 1][i]<<" ";
        }
    }
    else{
        for (int i = 0; i < m; i++)
        {

            cout << a[l - 1][i] << " ";
        }
    }
 return 0; 
}