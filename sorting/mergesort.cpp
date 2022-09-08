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
int* combine(int* left, int* right, int leftlen, int rightlen)
{
    vector<int> final;
    int j = 0;
    int k = 0;
    cout<<"initleft"<<leftlen;
    for (int i = ; i < leftlen; i++)
    {
        cout<<left[i]<<" ";
    }
    cout<<endl;
    cout << "initright"<<rightlen;
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
    int ret[MAXN];
    cout<<"ret";
    for (int i = 0; i < final.size(); i++)
    {
        ret[i] = final[i];
        cout<<final[i]<<" ";
    }
    cout<<endl;
    return ret;

}
int* mergesort(int* a, int low, int high, int n){
    //if length of a = 1, return a[0];
    if(n==1){
        return a;
    }
    int mid = (low + high) /2;
    // vector<int> left, right;
    int left[MAXN], right[MAXN];

    cout<< low<< " "<<mid<<" "<<high;
    cout<<"left";
    for(int i = low ; i < mid; i++){
        // left.pb(a[i]);
        left[i] = a[i];
        cout<<left[i]<<" ";
    }
    cout<<endl;
    cout<<"right";
    for(int j = mid; j< high; j++){
        // right.pb(a[j]);
        right[j] = a[j];
        cout << right[j] << " ";
    }
    
    cout<<endl;
    // if(mid - low == 1)return left;
    // if(high - low == 1)return right; 
    //check length is correct, need +1 or not;
    return combine(mergesort(left, low, mid, mid-low), mergesort(right, mid, high, high-mid), low, high); 
}


int32_t main(){ 
    IOS; 
    int a[10] = {1,6,8};
    int b[10] = {4,5,7};

    int c[MAXN]= {1,6,3,4,2,3,9};
    // vector<int> k = combine(a,b,3,3);
    int* fin;
     fin = mergesort(c, 0, 7, 7);
     for(int i = 0; i < 8; i++){
        cout<<fin[i]<<" ";
     }
    // rep(i,0,10){
    //     cout<<k[i]<<endl;
    // }
    return 0; 
}