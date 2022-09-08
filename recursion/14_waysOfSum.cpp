#include <iostream>
#include <vector>
using namespace std;
int n;
string dp[10];
// vector<char> d;
// string list(int n, vector<char> cmp){
//     if(n == 1){
//         string s = "";
//         for(int i = 0 ; i < cmp.size(); i++){
//             s  += cmp[i] + (i == cmp.size() -1 ? " + " : "" );
//         }
//         return s;
//     }
    
//     for(int i = 1; i < n ; i++){

    
//         vector<char> c = cmp ;
//         c.push_back((char)n-i);
//         c.push_back((char)i);
//         if(!dp[n-i].length()){
//         dp[n-i] = list(n - i, c);
//         cout<<endl;
//         }
//     }
// }

void list(int n, string s = ""){
    if(n == 1){
        return;
    }
    
    for(int i = 1; i < n ; i++){
        cout<< n - i;
        //add trailing numbers
        string p = s;
        p += to_string(i);
        for(int i = 0 ; i < p.length(); i++){
            cout<< (i==p.length() ? "":" + ")<<p[i];
        }
        cout<<endl;
        // if(!dp[n-i].length()){
        // dp[n-i] = list(n - i,p);
        // }
        list(n-i,p);
    }
}
int main(){
    n = 5;
    list(n);
    return 0;
}