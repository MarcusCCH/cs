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
int board[10][10];
int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {-1, 0, 1, -1, 0, 1, 1, -1};
int ans = 0;
bool inbound(int c, int r){
    return c>=0 && c< 8 && r >= 0 && r<8;
}
bool isValid(int c, int r)
{
    if(board[r][c] == 2)return false;
    for (int i = 0; i < c; i++) // check whether there is queen in the left or not
        if (board[r][i] == 1)
            return false;
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1) // check whether there is queen in the left upper diagonal or not
            return false;
    for (int i = r, j = c; j >= 0 && i < 8; i++, j--)
        if (board[i][j] == 1) // check whether there is queen in the left lower diagonal or not
            return false;
    return true;
}

void solve(int c=0){
    if(c==8){
        ans++;
        // rep(i, 0, 8)
        // {
        //     rep(j, 0, 8) cout << board[i][j] << " ";
        //     cout << endl;
        // }
        // cout << endl;
        return;
    }
    for(int i = 0 ; i <8 ; i++){
        if(isValid(c,i)){
            board[i][c] = 1;
            solve(c+1);
            board[i][c] = 0; 
        }
    }
}
int main(){ 
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0; j < 8; j++){
            char c;
            cin>>c;
            if(c == '*'){
                board[i][j] = 2;
            }
        }
    }
solve(0);
 cout<<ans<<endl;
 return 0; 
}