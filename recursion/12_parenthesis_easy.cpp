#include <iostream>
using namespace std;
string s;
/*

(())())

*/
void check(string s, char pre = ' ', int count = 0){
    if(count < 0) {
        cout<<"NO"<<endl;
        return;
    }
    if((s[0] == ']' && pre!='[') || (s[0] == '}' && pre!='{') || (s[0] == ')' && pre!='(') ){
        cout<<"NO"<<endl;
        return;
    }
    if(s.length() == 0){
        if(count == 0){
            cout<<"YES"<<endl;
            return;
        }
            cout<<"NO"<<endl;
            return;
    }
    count = (s[0] == '(' || s[0] == '[' || s[0] == '{' ) ? count+1: count-1;
    pre = s[0];
    s = s.substr(1, s.length() -1);
    check(s, pre, count);
    // return true;

}   
int main(){
    s = "([(]";
    check(s);


    return 0;
}   