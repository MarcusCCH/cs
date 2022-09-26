#include <stdio.h>
#include <string.h>
#define MAXN 10000
int a[MAXN];
int binpow(int a, int b)
{
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
int BinaryToDecimal(char* a, int n){
    int ret = 0,ind= 0;
    for(int i = n-1 ; i >=0; i--){
        if(a[i] == '1')
        ret += binpow(2,ind);
        ++ind;
    }   
    return ret;
}
void DecimalToHexadecimal(int num)
{
    printf("%d", num);
    int k = 0;
    while (binpow(16, k) <= num)
    {
        k++;
    }
    for (int i = k - 1; i >= 0; i--)
    {
        int t = binpow(16, i), j = 1;
        for (j = 1; j <= 15; j++)
        {
            if (j * t > num)
            {
                break;
            }
        }
        a[i] = j - 1;
        num -= (j - 1) * t;
    }
    char d[MAXN];
    for (int i = k - 1; i >= 0; i--)
    {
        if (a[i] >= 10)
        {
            int k = 'A';
            k += a[i] - 10;
            char c = k;
            d[i] = k;
            printf("%c", c);
        }
        else
        {
            d[i] = a[i];
            printf("%d", a[i]);
        }
    }
}
void BinaryToHexadecimal(char * a, int n){
    int num = BinaryToDecimal(a, n);
    DecimalToHexadecimal(num);
}
void DecimalToBinary(int n, int len){
    int digits =0;
   
    while (n > 0)
    {
        if (n % 2 != 0)
        {
            n -= 1;
            a[0]++;
            digits++;
        }
        else
        {
            int k = n, power = 0;
            while (k % 2 == 0)
            {
                //  cout << "k" << k << endl;
                k /= 2;
                power++;
            }
            //  cout << power << endl;
            a[power]++;
            if(power > digits)digits = power;
            n -= binpow(2, power);
        }
    }
    // printf("%d\n",digits);
    for (int i = digits; i >= 0; i--)
    {
        printf("%d",a[i]);
    }
}

int HexadecimalToDecimal(char *a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int t = binpow(16, i);
        if (a[i] - 'A' >= 0 && a[i] - 'A' <= 6)
        {
            sum += (a[i] - 'A') * t;
        }
        else
        {
            sum += (a[i] - '0') * t;
        }
    }
    // printf("%d", sum);
    return sum;
}
void HexadecimalToBinary(char *a){
    int num = HexadecimalToDecimal(a, strlen(a));
    DecimalToBinary(num, strlen(a));
} 

char str[MAXN];
int main()
{
    printf("Please enter a set of number:");
    scanf("%s", str);
    int n = strlen(str), from, to;
    printf("Please enter the current number system:");
    scanf("%d", &from);
    if(from == 2)
    for (int i = 0; i < n; i++)
    {
        if (str[i] != '1' && str[i] != '0')
        {
            printf("Error! That set of number is not a binary number.");
            return 0;
        }
    }
    printf("Please enter the number system you want the set of number be converted to:");
    scanf("%d", &to);
    switch(from){
        case 2:
            switch(to){
                case 10:
                    printf("%d",BinaryToDecimal(str,n)); //done;
                    break;
                case 16:
                    BinaryToHexadecimal(str, n); //done
                    break;
            }
        case 10:
            switch(to){
                int ind = 0, num = 0;
                for (int i = n- 1; i >= 0; i--)
                {
                    int k = a[i] - '0';
                    num += k * binpow(10, ind++);
                }
                case 2:
                    DecimalToBinary(num,n);
                    break;
                case 16: 
                    DecimalToHexadecimal(num);
                    break;
            }
        case 16: 
            switch(to){
                case 2:
                    HexadecimalToBinary(str);
                    break;
                case 10:
                    HexadecimalToDecimal(str, n);
                    break;
            }
        default: 
            break;
    }
    return 0;
}