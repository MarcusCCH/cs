#include <stdio.h>
#define MAXN 10000
int a[MAXN], b[MAXN], c[MAXN];
float mean(int numbers[], int size)
{
    float output;
    for(int i = 0 ; i < size; i++){
        output += numbers[i];
    }
    output /= size;
    return output;
}

void mode(int numbers[], int size)
{
    float maxa[MAXN];
    int maxi = -1, maxk, ind = 0;
    for(int i = 0 ; i < size; i++){
        if(numbers[b[i]] > maxi){
            ind = 0;
            maxi = numbers[b[i]];
            maxa[ind++] = b[i];
            maxk = b[i];
        }else if(numbers[b[i]] == maxi && maxk != b[i]){
            maxa[ind++] = b[i];
            maxk = b[i];
        }
    }
    if(ind == size){
        printf("Mode = No Mode\n");
    }else{
        printf("Mode = ");
        for(int i = 0 ; i < ind ; i++){
            printf("%0.3f%c", maxa[i], (i == ind -1 ? '\n' : ' '));
        }
    }
}

float median(int numbers[], int size)
{
    // TODO
    for(int i = 0 ; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(numbers[i] > numbers[j]){
                int k = numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = k;
            }
        }
    }
    float output;
    if(size % 2 == 0){
        output = numbers[size / 2] + numbers[size / 2 - 1];
        output/= 2;
    }else{
        output = numbers[size/2];
    }
    return output;
}

int main()
{
    int x, cnt = 0, maxi = -1, maxk, ind  = 0;
    while(scanf("%d", &x)){
        b[ind++] = x;
        a[x]++, cnt++;
    }
    printf("Mean = %0.3f\n", mean(b, cnt));
    mode(a, cnt);
    printf("Median = %0.3f\n",median(b, cnt));
}