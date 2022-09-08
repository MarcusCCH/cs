#include <iostream>
using namespace std;
int arr[10] = {1,2,3,4,5};
int n = 5;
int U = 16;
bool find(int arr[], int sum = 0, int k = 0){
    //base case
    if(sum == U){
        // cout<<"Yes"<<endl;
        return true;
    }
    //
    for(int i = k ; i < n ; i++){
        int p = sum; 
        p += arr[k];
        // cout<<p<<endl;
        if(find(arr, p, k+1)){
            return true;
        };
    }
    return false;
}
void solve(){
    if(find(arr)){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    };
}
int main(){
    solve();


    return 0;
}