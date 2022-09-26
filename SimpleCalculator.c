#include <stdio.h>
#define MAXN 10000
char str[MAXN];
int main(){
    scanf("%s", str);
    int len = strlen(str);
    float f = str[0] - '0', s = str[2] - '0';
    if(str[1] == '+'){
        printf("%f", f+s);
    }
    else if(str[1] == '-'){
        printf("%f", f-s);
    } else if(str[1] == '/'){
        printf("%f", f/s);
    }else{
        printf("%f", f * s);
    }
    return 0;
}