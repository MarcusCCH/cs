#include <stdio.h>
#include <string.h>
#define MAXN 1000
char str[MAXN];
int count[MAXN];
int main(){
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(str[i] != 'A' && str[i] != 'B' && str[i]!='C'){
            printf("Score Attack Error");
            return 0;
        }
        count[str[i] - 'A']++;
    }
    float maxi = -1;
    for(int i = 0 ; i < 3; i++){
        if(count[i] > maxi){
            maxi = count[i];
        }
    }
    float combo = 1;
    if(combo >= 5){
        combo = maxi / 10 + 1;
    }
    float ret = maxi * (combo >=4 ? 4: combo);
    printf("%0.2f\n", ret);
    return 0;
}