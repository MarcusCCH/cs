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
int h[MAXN];
int heap_size,n;
vector<int> ans;
void max_heapify(int i)
{
    // cout<<i<<endl;
    // if(i == heap_size)return;
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest = i;
    if (h[l] > h[i])
    {
        largest = l;
    }
    if (h[r] > h[largest])
    {
        largest = r;
    }

    if (i != largest)
    {
        swap(h[i], h[largest]);
        max_heapify(largest);
    }
}
void buildmaxheap(){
    for(int i = heap_size / 2; i >= 1; i--){
        max_heapify(i);
    }
    // for(int i = 1; i <= n; i++)cout<<h[i]<<" ";
}


void heap_sort(){
    buildmaxheap();
    while(heap_size >= 1){
        // cout<<h[1]<<" "<<h[heap_size]<<endl;
        ans.pb(h[1]);
        swap(h[1], h[heap_size]);
        h[heap_size] = -1;
        --heap_size;
        max_heapify(1);
    }   
    for(int i = n-1; i>=0; i--)cout<<ans[i]<<" ";
}

/*
        9
    8       7
6       5

*/

int32_t main(){ 
 IOS; 
 cin>>n;
 heap_size = n;
 for(int i = 1; i <= n; i++){
    cin>>h[i];
 }
 heap_sort();

 return 0; 
}