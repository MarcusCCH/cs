#include <iostream>
#include <vector>
#include <string>
using namespace std;
char col[4] = {'3','2','0','1'};
vector<string>answer;
void recur(string s, char *col){
    if(s.length() == 4){
        answer.push_back(s);
        return;
    }
    for(int i = 0 ; i < 4; i++){
        string p = s;
        p.push_back(col[i]);
        recur(p, col);
    }
}
int main(){
    recur("",col);
    for(int i = 0 ; i < answer.size(); i++){
        cout<<answer[i]<<endl;
    }

    return 0;
}